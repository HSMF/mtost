type ast = item list

and item =
  | FuncDecl of ident * arg list * block * typ
  | ExternDecl of ident * arg list * typ
  | Import of Path.t

and arg = ident * typ
and ident = string

and typ =
  | I64
  | I8
  | Bool
  | Str
  | UnitTyp
  | Ptr of typ
  | Arr of typ

and block = statement list

and rhs =
  | Ident of ident
  | ArrIndex of ident * expr

and statement =
  | Let of ident * expr
  | Assign of rhs * expr
  | Funccall of ident * expr list
  | Return of expr
  | If of expr * block * block
  | Loop of block
  | Break

and bop =
  | Mult
  | Add
  | Sub
  | Shl
  | Shr
  | Shrr
  | Lt
  | Le
  | Gt
  | Ge
  | Eq
  | Neq
  | Land
  | Lor
  | Band
  | Bor

and uop =
  | Minus
  | Lnot
  | Bnot

and expr =
  | Unit
  | Var of ident
  | Int of int64
  | Char of int
  | Boolean of bool
  | Fn of ident * expr list
  | String of string
  | Bop of bop * expr * expr
  | Uop of uop * expr
  | Index of expr * expr
  | Array of expr list
  | DefaultArray of expr * int64

let sp = Printf.sprintf
let string_list sep map list = list |> List.map map |> String.concat sep
let indentation depth = String.make (depth * 2) ' '

let imports (ast : ast) : Path.t list =
  let get_imports = function
    | Import p -> [ p ]
    | _ -> []
  in
  ast |> List.map get_imports |> List.flatten
;;

(* pretty printing *)

let rec expr_to_string : expr -> string = function
  | Unit -> "()"
  | Var x -> x
  | Int i -> Int64.to_string i
  | Char i -> i |> char_of_int |> Char.escaped |> Printf.sprintf "'%s'"
  | Boolean b -> string_of_bool b
  | Fn (name, args) -> Printf.sprintf "%s(%s)" name (string_list ", " expr_to_string args)
  | String string -> Printf.sprintf "\"%s\"" @@ String.escaped string
  | Bop (b, l, r) ->
    Printf.sprintf "(%s %s %s)" (expr_to_string l) (bop_to_string b) (expr_to_string r)
  | Uop (u, v) -> Printf.sprintf "%s%s" (uop_to_string u) (expr_to_string v)
  | Index (arr, index) ->
    Printf.sprintf "(%s)[%s]" (expr_to_string arr) (expr_to_string index)
  | Array elems -> sp "[%s]" (string_list ", " expr_to_string elems)
  | DefaultArray (default, n) -> sp "[%s; %Ld]" (expr_to_string default) n

and bop_to_string = function
  | Mult -> "*"
  | Add -> "+"
  | Sub -> "-"
  | Shl -> "<<"
  | Shr -> ">>"
  | Shrr -> ">>>"
  | Lt -> "<"
  | Le -> "<="
  | Gt -> ">"
  | Ge -> ">="
  | Eq -> "=="
  | Neq -> "!="
  | Land -> "&&"
  | Lor -> "||"
  | Band -> "&"
  | Bor -> "|"

and uop_to_string = function
  | Minus -> "-"
  | Lnot -> "!"
  | Bnot -> "~"

and rhs_to_string (r : rhs) =
  match r with
  | Ident i -> i
  | ArrIndex (i, idx) -> sp "%s[%s]" i (expr_to_string idx)

and statement_to_string (depth : int) : statement -> string = function
  | Let (n, e) -> Printf.sprintf "let %s = %s;" n (expr_to_string e)
  | Assign (n, e) -> Printf.sprintf "%s = %s;" (rhs_to_string n) (expr_to_string e)
  | Funccall (name, args) ->
    Printf.sprintf "%s(%s);" name (string_list ", " expr_to_string args)
  | Return e -> Printf.sprintf "return %s;" @@ expr_to_string e
  | If (cond, thn, els) ->
    Printf.sprintf
      "if %s %s else %s"
      (expr_to_string cond)
      (block_to_string (depth + 1) thn)
      (block_to_string (depth + 1) els)
  | Loop body -> Printf.sprintf "loop %s" (block_to_string (depth + 1) body)
  | Break -> "break;"

and block_to_string (depth : int) = function
  | [] -> "{}"
  | list ->
    Printf.sprintf
      "{\n%s\n%s}"
      (string_list "\n" (fun x -> indentation depth ^ statement_to_string depth x) list)
      (indentation (depth - 1))

and typ_to_string = function
  | I64 -> "i64"
  | I8 -> "i8"
  | Bool -> "bool"
  | Str -> "str"
  | UnitTyp -> "unit"
  | Arr ty -> Printf.sprintf "[%s]" (typ_to_string ty)
  | Ptr ty -> Printf.sprintf "*%s" (typ_to_string ty)

and item_to_string (i : item) =
  match i with
  | FuncDecl (name, args, body, retty) ->
    Printf.sprintf
      "toaster %s(%s): %s %s"
      name
      (string_list
         ", "
         (fun (n, ty) -> Printf.sprintf "%s: %s" n (typ_to_string ty))
         args)
      (typ_to_string retty)
      (block_to_string 1 body)
  | ExternDecl (name, args, retty) ->
    Printf.sprintf
      "extern toaster %s(%s): %s;"
      name
      (string_list
         ", "
         (fun (n, ty) -> Printf.sprintf "%s: %s" n (typ_to_string ty))
         args)
      (typ_to_string retty)
  | Import path -> sp "import %s;" (Path.to_string path)

and items_to_string items = string_list "\n\n" item_to_string items
