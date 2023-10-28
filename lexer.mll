{
  open Lexing
  open Range
  open Parser

  exception Lexer_error of Range.t * string

  let pos_of_lexpos (p:Lexing.position): pos = mk_pos (p.pos_lnum) (p.pos_cnum - p.pos_bol)

  let mk_lex_range (p1:Lexing.position) (p2:Lexing.position) : Range.t =
    mk_range p1.pos_fname (pos_of_lexpos p1) (pos_of_lexpos p2)

  (* Expose the lexer state as a Range.t value *)
  let lex_range lexbuf : Range.t =
    mk_lex_range (lexeme_start_p lexbuf) (lexeme_end_p lexbuf)

    (* Reset the lexer state *)
  let reset_lexbuf (filename:string) lexbuf : unit =
    lexbuf.lex_curr_p <- {
      pos_fname = filename;
    pos_cnum = 0;
    pos_bol = 0;
    pos_lnum = 1;
    }

    (* Boilerplate to define exceptional cases in the lexer. *)
  let unexpected_char lexbuf (c:char) : 'a =
    raise (Lexer_error (lex_range lexbuf,
      Printf.sprintf "Unexpected character: '%c'" c))

  let error lexbuf fmt =
    Printf.kprintf (fun msg ->
      raise (Lexer_error (lex_range lexbuf,msg))) fmt



  let keyword_table: (string, Range.t -> Parser.token) Hashtbl.t = Hashtbl.create 64
  let () = List.iter (fun (keywd, tok) -> Hashtbl.add keyword_table keywd tok)
  [
        ("true", fun r -> TRUE r)
      ; ("false", fun r -> FALSE r)
      ; ("extern", fun r -> EXTERN r)
      ; ("fun", fun r -> FUN r)
      ; ("toaster", fun r -> FUN r)
      ; ("let", fun r -> LET r)
      ; ("return", fun r -> RETURN r)
      ; ("break", fun r -> BREAK r)
      ; ("loop", fun r -> LOOP r)
      ; ("if", fun r -> IF r)
      ; ("else", fun r -> ELSE r)
      ; ("unit", fun r -> T_UNIT r)
      ; ("i64", fun r -> T_i64 r)
      ; ("i8", fun r -> T_i8 r)
      ; ("bool", fun r -> T_bool r)
      ; ("str", fun r -> T_str r)
      ; ("import", fun r -> IMPORT r)
  ]

  let ident_or_kw range ident = try
    (Hashtbl.find keyword_table ident) range
  with Not_found -> IDENT (range, ident)

  let make_char lexbuf (s:string) = let open String in
    let range = lex_range lexbuf in
    let chars = to_seq s |> List.of_seq in
    let to_hex = function
        | '0'..'9' as c -> (int_of_char c) - (int_of_char '0')
        | 'a'..'f' as c -> (int_of_char c) - (int_of_char 'a') + 10
        | _ -> failwith "invalid hex"
    in
    match chars with
    | ['\\'] -> error lexbuf "invalid escape sequence"
    | [c]    -> CHAR(range, int_of_char c)
    | ['\\'; 'x'; ('0'..'9' | 'a'..'f') as a; ('0'..'9' | 'a'..'f') as b]
             -> CHAR(range, to_hex a * 16 + to_hex b)
    | ['\\'; '0']
             -> CHAR(range, 0)
    | ['\\'; '\\']
             -> CHAR(range, int_of_char '\\')
    | ['\\'; '\'']
             -> CHAR(range, int_of_char '\'')
    | ['\\'; 'n']
             -> CHAR(range, int_of_char '\n')
    | xs -> failwith (Printf.sprintf "unknown char: %s" (xs |> List.to_seq |> String.of_seq) )
}

let lowercase = ['a'-'z']
let uppercase = ['A'-'Z']
let start_ident = uppercase | lowercase | '_'
let digit = ['0'-'9']
let ident = start_ident | digit
let whitespace = ['\t' ' ' '\r']

let char = [^'\'' '\\'] | "\\x" ['0'-'9'] ['0'-'9'] | "\\0" | "\\n" | "\\\\" | "\\'"

rule token = parse
  | eof { EOF }
  | whitespace+ { token lexbuf }
  | '\n' { Lexing.new_line lexbuf; token lexbuf }
  | '(' { LPAREN (lex_range lexbuf) }
  | ')' { RPAREN (lex_range lexbuf) }
  | '{' { LBRACE (lex_range lexbuf) }
  | '}' { RBRACE (lex_range lexbuf) }
  | '[' { LBRACK (lex_range lexbuf) }
  | ']' { RBRACK (lex_range lexbuf) }
  | ';' { SEMICOLON (lex_range lexbuf) }
  | '*' { STAR (lex_range lexbuf) }
  | "::" { DOUBLECOLON (lex_range lexbuf) }
  | ':' { COLON (lex_range lexbuf) }
  | ',' { COMMA (lex_range lexbuf) }
  | '=' { EQL (lex_range lexbuf) }
  | '"' { STRING (lex_range lexbuf, string (Buffer.create 100) lexbuf) } (* see below *)
  | "//" { comment lexbuf }

  | '+' { ADD (lex_range lexbuf) }
  | '-' { SUB (lex_range lexbuf) }
  | "<<" { SHIFTL (lex_range lexbuf) }
  | ">>" { SHIFTR (lex_range lexbuf) }
  | ">>>" { SHIFTRA (lex_range lexbuf) }
  | '<' { LT (lex_range lexbuf) }
  | "<=" { LE (lex_range lexbuf) }
  | '>' { GT (lex_range lexbuf) }
  | ">=" { GE (lex_range lexbuf) }
  | "==" { EQ (lex_range lexbuf) }
  | "!=" { NEQ (lex_range lexbuf) }
  | "&&" { LAND (lex_range lexbuf) }
  | "||" { LOR (lex_range lexbuf) }
  | '&' { BAND (lex_range lexbuf) }
  | '|' { BOR (lex_range lexbuf) }
  | '!' { LNOT (lex_range lexbuf) }
  | '~' { BNOT (lex_range lexbuf) }
  | '\'' (char as c) '\'' { make_char (lexbuf) c }
  | start_ident ident* { ident_or_kw (lex_range lexbuf) (Lexing.lexeme lexbuf) }
  | digit+ { INT (lex_range lexbuf, lexbuf |> Lexing.lexeme |> Int64.of_string) }
  | _ as c { unexpected_char lexbuf c }
and comment = parse
  | '\n' { Lexing.new_line lexbuf; token lexbuf }
  | _ { comment lexbuf }

and string buf = parse
  | [^'"' '\n' '\\']+ {
      Buffer.add_string buf @@ lexeme lexbuf; string buf lexbuf
    }
  | '\n' {
      Buffer.add_char buf '\n'
  ; Lexing.new_line lexbuf
  ; string buf lexbuf
    }
  |
  "\\n"
    {
      Buffer.add_char buf '\n'
 ; string buf lexbuf
    }
  |
  "\\0"
    {
      Buffer.add_char buf (char_of_int 0)
 ; string buf lexbuf
    }
  | '\\' '"' {
      Buffer.add_char buf '"'
  ; string buf lexbuf
    }
  | '\\' {
      Buffer.add_char buf '\\'
  ; string buf lexbuf
    }
  | '"' { Buffer.contents buf } (* return *)
  | eof { error lexbuf "end of input inside of a string" }
  | _ {
      error lexbuf
      "found '%s' - don't know how to handle" @@ lexeme lexbuf
    }
