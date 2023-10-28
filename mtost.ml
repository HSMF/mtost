module P = Parser
open Lexer
open Util

(* invoke the parser top level function using the generated
 * token function available in the lexer to create the
 * token stream.
 *)
let parse (filename : string) (buf : Lexing.lexbuf) : Ast.item list =
  Lexer.reset_lexbuf filename buf;
  P.toplevel Lexer.token buf
;;

let highlight_issue (input : string) (range : Range.t) =
  let open Range in
  if start_of_range range |> line_of_pos <> (end_of_range range |> line_of_pos)
  then failwith "not implemented"
  else begin
    let line =
      List.nth
        (String.split_on_char '\n' input)
        ((range |> start_of_range |> line_of_pos) - 1)
    in
    let s = range |> start_of_range |> col_of_pos in
    let e = range |> end_of_range |> col_of_pos in
    line, String.init (String.length line) (fun i -> if i >= s && i < e then '^' else ' ')
  end
;;

let prefix_lines prefix (s : string) =
  s |> String.split_on_char '\n' |> List.map (( ^ ) prefix) |> String.concat "\n"
;;

let read_file filename =
  let ch = open_in_bin filename in
  let s = really_input_string ch (in_channel_length ch) in
  close_in ch;
  s
;;

let compile_clang ~opt_level file output =
  let flags = ref [ "-Wno-override-module" ] in
  if opt_level <> 0 then flags := !flags @ [ sp "-O%d" opt_level ];
  Util.exec "clang" (!flags @ [ "-o"; output; "std.o"; file ]) Util.raise_error
;;

let last = List.rev >> List.hd

(* this sucks and needs to be fixed *)
let rec load_file
  (basepath : Path.t)
  (filename : string)
  (dirname : string)
  (externals : (string * Mid1.Ty.t) list ref)
  : Mid1.t list * (Path.t * Mid1.Ty.t) list
  =
  info (sp "compiling %s" filename);
  let concat_dir path = dirname ^ "/" ^ string_list "/" Fun.id path ^ ".tost" in
  let input = filename |> read_file in
  (* parse the file*)
  let buf = Lexing.from_string input in
  let ast =
    try parse filename buf with
    | Lexer.Lexer_error (r, m) ->
      failwith (Printf.sprintf "Lexing error at %s: %s." (Range.string_of_range r) m)
    | P.Error ->
      let range = Lexer.lex_range buf in
      let line, help = highlight_issue input range in
      error (line ^ "\n" ^ help);
      failwith
        (Printf.sprintf
           "Parse error at %s:\n%s\n%s"
           (Range.string_of_range (Lexer.lex_range buf))
           line
           help)
  in
  let ast = Transform.no_implicit_return ast in
  (* get imports *)
  let imports = Ast.imports ast in
  let compiles : (Path.t * string list ref) list ref = ref [] in
  let get_or_insert key =
    try List.assoc key !compiles with
    | Not_found ->
      let entry = ref [] in
      compiles := (key, entry) :: !compiles;
      entry
  in
  (* info @@ slc Path.to_string imports; *)
  let search = List.map (List.rev >> skip 1 >> List.rev) imports in
  (* info @@ slc Fun.id search; *)
  List.iter2
    (fun symbol file ->
      let entry = get_or_insert file in
      entry := symbol :: !entry)
    (List.map (List.rev >> List.hd) imports)
    search;
  List.iter
    (fun (cunit, syms) ->
      info @@ sp "searching for %s in %s" (slc Fun.id !syms) (concat_dir cunit))
    !compiles;
  let midlevels, symbol_map =
    List.map
      (fun (comp_unit, _) -> load_file comp_unit (concat_dir comp_unit) dirname externals)
      !compiles
    |> List.split
  in
  let midlevels, symbol_map = List.(concat midlevels, concat symbol_map) in
  let exported_symbols, externs = Mid1.declared_types ast in
  (* wtf, right? *)
  let imported_symbols =
    List.filter
      (fun (x, _) -> List.find_opt (fun y -> x = y) imports |> Option.is_some)
      symbol_map
    |> List.map (fun (a, b) -> last a, b)
  in
  let print_typemap name tm =
    info
    @@ name
    ^ ": "
    ^ slc (fun (name, ty) -> sp "%s: %s" name (Mid1.Ty.to_string ty)) tm
  in
  let cmp (a, _) (b, _) = String.compare a b in
  externals := List.merge cmp (List.sort cmp externs) !externals;
  info filename;
  print_typemap "exported_symbols" exported_symbols;
  print_typemap "externals       " !externals;
  print_typemap "imported symbols" imported_symbols;
  let midlevel =
    Mid1.from_ast
      (exported_symbols @ !externals @ imported_symbols @ Mid1.operand_func_types)
      ast
  in
  ( midlevel :: midlevels
  , symbol_map
    @ List.map (fun (x, ty) -> Path.prepend_path basepath [ x ], ty) exported_symbols )
;;

let () =
  let set_if_none place error_msg what =
    match !place with
    | Some _ -> failwith error_msg
    | None -> place := Some what
  in
  (* Printf.eprintf "%s\n" (Sys.getcwd ()); *)
  let output_file = ref None in
  let input_file = ref None in
  let print_parsed = ref false in
  let build = ref false in
  let incl = ref "." in
  let positional_arg = set_if_none input_file "can only supply one input file" in
  let opt_level = ref 0 in
  let run = ref false in
  let speclist =
    [ ( "-o"
      , Arg.String (set_if_none output_file "can only supply one output file")
      , "output file" )
    ; "-O0", Arg.Unit (fun () -> opt_level := 0), "opt level 0"
    ; "-O1", Arg.Unit (fun () -> opt_level := 1), "opt level 1"
    ; "-O2", Arg.Unit (fun () -> opt_level := 2), "opt level 2"
    ; "-v", Arg.Unit (fun _ -> log_level := LInfo), "output a lot"
    ; "--print-ast", Arg.Set print_parsed, "print the parsed ast"
    ; "--build", Arg.Set build, "produce an executable, only if there is an output file"
    ; "-I", Arg.Set_string incl, "set include path"
    ; "--run", Arg.Set run, "run the produced binary"
    ]
  in
  Arg.parse speclist positional_arg "mtost.exe [-o <FILE>] <INPUT>";
  let input_file =
    !input_file
    |> function
    | None -> failwith "pls supply an input"
    | Some x -> x
  in
  let input = input_file |> read_file in
  let output_file_name =
    match !output_file with
    | None -> None
    | Some f -> Some f
  in
  (* setup environment *)
  let target = "./target" in
  let basename =
    input_file
    |> String.split_on_char '/'
    |> List.rev
    |> List.hd
    |> Filename.remove_extension
  in
  let input_dir =
    input_file
    |> String.split_on_char '/'
    |> List.rev
    |> skip 1
    |> List.rev
    |> String.concat "/"
  in
  let input_dir = if input_dir = "" then "." else input_dir in
  let in_target f = target ^ "/" ^ f in
  let llvm_ir_file = in_target (basename ^ ".ll") in
  let output = Option.fold ~none:(in_target basename) ~some:Fun.id output_file_name in
  ensure_directory_exists target;
  info llvm_ir_file;
  info output;
  let ir_file = open_out llvm_ir_file in
  let buf = Lexing.from_string input in
  try
    (* parse file *)
    (* let ast = parse input_file buf in *)
    (* let ast = Transform.no_implicit_return ast in *)
    (* info (Ast.items_to_string ast); *)
    let externals = ref [] in
    let step1, tmaps = load_file [] input_file input_dir externals in
    (* todo: fix *)
    let funcs = List.map (fun (a, b) -> last a, b) tmaps in
    let step1 =
      let open Mid1 in
      List.fold_left (fun a b -> a @@@ b) { items = [] } step1
    in
    (* convert to llvm ir *)
    let llvm =
      try Compilem1.compile !externals funcs step1 with
      | e ->
        Printf.eprintf "bt: %s\n" Printexc.(get_callstack 10 |> raw_backtrace_to_string);
        flush stderr;
        raise e
    in
    Printf.fprintf ir_file "%s" (Llvm.string_of_prog llvm);
    close_out ir_file;
    (* compile ir file with clang *)
    compile_clang ~opt_level:!opt_level llvm_ir_file output;
    if !run
    then begin
      exec output [] raise_error
    end;
    ()
  with
  | Lexer.Lexer_error (r, m) ->
    failwith (Printf.sprintf "Lexing error at %s: %s." (Range.string_of_range r) m)
  | P.Error ->
    let range = Lexer.lex_range buf in
    let line, help = highlight_issue input range in
    error (line ^ "\n" ^ help);
    failwith
      (Printf.sprintf
         "Parse error at %s:\n%s\n%s"
         (Range.string_of_range (Lexer.lex_range buf))
         line
         help)
;;
