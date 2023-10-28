let x = 0
let sp = Printf.sprintf
let fail args = failwith (sp args)

open Util

module Ty = struct
  type t =
    | I64
    | I8
    | Bool
    (* | Str *)
    | Unit
    | Func of t list * t
    | Arr of t

  let rec mapty : Ast.typ -> t = function
    | Ast.I64 -> I64
    | Ast.I8 -> I8
    | Ast.Bool -> Bool
    | Ast.Str -> Arr I8
    | Ast.UnitTyp -> Unit
    | Ast.Ptr _ -> failwith "deprecate ptr"
    | Ast.Arr t -> Arr (mapty t)
  ;;

  let rec to_string = function
    | I64 -> "i64"
    | I8 -> "i8"
    | Bool -> "bool"
    (* | Str -> "str" *)
    | Unit -> "unit"
    | Func (args, ret) ->
      sp "(%s) -> %s" (Ast.string_list ", " to_string args) (to_string ret)
    | Arr t -> sp "[%s]" (to_string t)
  ;;

  let item_typ = function
    | Arr t -> t
    | _ -> failwith "not an array"
  ;;

  let func_typ = function
    | Func (a, ret) -> a, ret
    | _ -> failwith "not a function"
  ;;
end

module Lit = struct
  type t =
    | I64 of int64
    | Str of string
    | Bool of bool
    | I8 of int

  let typeof : t -> Ty.t = function
    | I64 _ -> Ty.I64
    | Str _ -> Ty.Arr Ty.I8
    | Bool _ -> Ty.Bool
    | I8 _ -> Ty.I8
  ;;
end

type uid = string

type t = { items : item list }

and item =
  { name : string
  ; args : arg list
  ; body : block
  ; retty : Ty.t
  }

and arg = uid * Ty.t
and block = statement list

and rhs =
  | RhsIdent of uid
  | RhsArr of uid * expr

and statement =
  | Let of uid * expr
  | Assign of rhs * expr
  | Return of expr
  | If of expr * block * block
  | Loop of block
  | Break

and expr =
  | Unit
  | Var of uid
  | Literal of Lit.t
  | Fn of uid * expr list
  | Index of expr * expr
  | Array of expr list
  | ArrayDefault of expr * int64

type tmap = uid * Ty.t

let operand_func_types : tmap list =
  let open Ty in
  [ "add", [ I64; I64 ], I64
  ; "mult", [ I64; I64 ], I64
  ; "sub", [ I64; I64 ], I64
  ; "shl", [ I64; I64 ], I64
  ; "shr", [ I64; I64 ], I64
  ; "shrr", [ I64; I64 ], I64
  ; "lt", [ I64; I64 ], Bool
  ; "le", [ I64; I64 ], Bool
  ; "gt", [ I64; I64 ], Bool
  ; "ge", [ I64; I64 ], Bool
  ; "eq", [ I64; I64 ], Bool
  ; "neq", [ I64; I64 ], Bool
  ; "land", [ I64; I64 ], I64
  ; "lor", [ I64; I64 ], I64
  ; "band", [ Bool; Bool ], I64
  ; "bor", [ Bool; Bool ], Bool
  ; "minus", [ I64 ], I64
  ; "lnot", [ Bool ], Bool
  ; "bnot", [ I64 ], I64
  ]
  |> List.map (fun (a, b, c) -> "<op>i64" ^ a, Func (b, c))
;;

let fun_of_bop =
  let open Ast in
  function
  | Mult -> "<op>i64mult"
  | Add -> "<op>i64add"
  | Sub -> "<op>i64sub"
  | Shl -> "<op>i64shl"
  | Shr -> "<op>i64shr"
  | Shrr -> "<op>i64shrr"
  | Lt -> "<op>i64lt"
  | Le -> "<op>i64le"
  | Gt -> "<op>i64gt"
  | Ge -> "<op>i64ge"
  | Eq -> "<op>i64eq"
  | Neq -> "<op>i64neq"
  | Land -> "<op>i64land"
  | Lor -> "<op>i64lor"
  | Band -> "<op>i64band"
  | Bor -> "<op>i64bor"
;;

let fun_of_uop =
  let open Ast in
  function
  | Minus -> "<op>i64minus"
  | Lnot -> "<op>i64lnot"
  | Bnot -> "<op>i64bnot"
;;

let bt () = Printexc.(get_callstack 10 |> raw_backtrace_to_string)

let assert_ty_eq (t1 : Ty.t) (t2 : Ty.t) =
  if t1 <> t2
  then failwith (sp "expected type %s, got type %s" (Ty.to_string t1) (Ty.to_string t2))
;;

let assert_ty_all_eq (ts : Ty.t list) =
  let rec aux t = function
    | [] -> ()
    | t' :: ts ->
      assert_ty_eq t t';
      aux t ts
  in
  match ts with
  | [] -> ()
  | t :: ts -> aux t ts
;;

(* failwith *)
(*   (sp "expected type %s, got type %s" (Ty.to_string t1) (Ty.to_string t2)) *)

(** func_sig func_types name = [arg_types], return_type for name *)
let sigof (fts : tmap list) (name : uid) : Ty.t =
  try List.assoc name fts with
  | x ->

    error @@ Util.slc (fun (name, ty) -> sp "%s: %s" name (Ty.to_string ty)) fts;
    error (sp "didnt find symbol: %s\n" name);
    flush stderr;
    raise x
;;

let rec typeof_expr (fts : tmap list) : expr -> Ty.t = function
  | Unit -> Ty.Unit
  | Var n -> sigof fts n
  | Literal (Lit.I64 _) -> Ty.I64
  | Literal (Lit.Bool _) -> Ty.Bool
  | Literal (Lit.I8 _) -> Ty.I8
  | Fn (name, args) -> begin
    match sigof fts name with
    | Ty.Func (aty, retty) ->
      if List.length aty <> List.length args
      then
        failwith
          (sp
             "%s expected %d arguments but got %d"
             name
             (List.length aty)
             (List.length args))
        (* else if List.exists2 (fun got exp -> exp <> typeof_expr fts got) args aty *)
        (* then failwith (sp "invalid argument to %s" name) *);
      List.iter2 assert_ty_eq aty (List.map (typeof_expr fts) args);
      retty
    | _ -> failwith (sp "type error: %s is not a function" name)
  end
  | Literal (Lit.Str _) -> Ty.Arr Ty.I8
  | Index (e1, e2) ->
    let t1, t2 = typeof_expr fts e1, typeof_expr fts e2 in
    (match t1, t2 with
     | Ty.Arr t, Ty.I64 -> t
     | _, _ ->
       failwith (sp "cannot index into %s with %s" (Ty.to_string t1) (Ty.to_string t2)))
  | ArrayDefault (e, _) -> Ty.Arr (typeof_expr fts e)
  | Array es -> begin
    match es with
    | [] -> failwith "cannot yet handle empty arrays"
    | e :: es ->
      let t = typeof_expr fts e in
      assert_ty_all_eq (t :: List.map (typeof_expr fts) es);
      t
  end
;;

let declared_types (ast : Ast.ast) =
  let open Ty in
  let open List in
  let ft name args retty = name, Func (args |> map snd |> map mapty, mapty retty) in
  let rec mapitem (with_body, without) : Ast.ast -> _ * _ = function
    | [] -> with_body, without
    | Ast.FuncDecl (name, args, _, retty) :: xs ->
      mapitem (ft name args retty :: with_body, without) xs
    | Ast.ExternDecl (name, args, retty) :: xs ->
      mapitem (with_body, ft name args retty :: without) xs
    | Ast.Import _ :: xs -> mapitem (with_body, without) xs
  in
  mapitem ([], []) ast

;;

let rec from_ast fts (ast : Ast.ast) =
  let items = List.map (mapitem fts) ast |> List.flatten in
  { items }

and mapitem (fts : tmap list) (item : Ast.item) =
  match item with
  | Ast.FuncDecl (name, args, body, retty) ->
    let args = List.map (fun (x, t) -> x, Ty.mapty t) args in
    let retty = Ty.mapty retty in
    [ { name; args; body = mapblock (args @ fts) retty body; retty } ]
  | Ast.ExternDecl _ -> (* extern decl has no representation *) []
  | Ast.Import _ -> (* import has no representation *) []

and mapblock (fts : tmap list) retty = List.map (mapstmt (ref fts) retty)

and mapstmt (fts : tmap list ref) (retty : Ty.t) : Ast.statement -> statement = function
  | Ast.Let (name, value) ->
    let value = mapexpr !fts value in
    fts := (name, typeof_expr !fts value) :: !fts;
    Let (name, value)
  | Ast.Assign (Ast.Ident name, value) ->
    let value = mapexpr !fts value in
    let expected_type = sigof !fts name in
    let actual_type = typeof_expr !fts value in
    assert_ty_eq expected_type actual_type;
    Assign (RhsIdent name, value)
  | Ast.Assign (Ast.ArrIndex (name, idx), value) ->
    let arr_type = sigof !fts name in
    let value = mapexpr !fts value in
    let actual_type = typeof_expr !fts value in
    let idx = mapexpr !fts idx in
    assert_ty_eq Ty.I64 (typeof_expr !fts idx);
    assert_ty_eq (Ty.item_typ arr_type) actual_type;
    Assign (RhsArr (name, idx), value)
  | Ast.Funccall (name, args) ->
    let fexpr = Ast.Fn (name, args) in
    let fexpr = mapexpr !fts fexpr in
    let _ = typeof_expr !fts fexpr in
    Let ("<anon>", fexpr)
  | Ast.Return e ->
    let e = mapexpr !fts e in
    let t = typeof_expr !fts e in
    assert_ty_eq retty t;
    Return e
  | Ast.If (cond, thn, els) ->
    let cond = mapexpr !fts cond in
    assert_ty_eq Ty.Bool (typeof_expr !fts cond);
    If (cond, mapblock !fts retty thn, mapblock !fts retty els)
  | Ast.Loop body -> Loop (mapblock !fts retty body)
  | Ast.Break -> Break

and mapexpr (fts : tmap list) (e : Ast.expr) : expr =
  let e =
    match e with
    | Ast.Unit -> Unit
    | Ast.Var x -> Var x
    | Ast.Int i -> Literal (Lit.I64 i)
    | Ast.Char c -> Literal (Lit.I8 c)
    | Ast.Boolean b -> Literal (Lit.Bool b)
    | Ast.String s -> Literal (Lit.Str s)
    | Ast.Fn (name, args) -> Fn (name, List.map (mapexpr fts) args)
    | Ast.Bop (op, l, r) -> Fn (fun_of_bop op, [ mapexpr fts l; mapexpr fts r ])
    | Ast.Uop (op, x) -> Fn (fun_of_uop op, [ mapexpr fts x ])
    | Ast.Index (arr, idx) -> Index (mapexpr fts arr, mapexpr fts idx)
    | Ast.Array es -> Array (List.map (mapexpr fts) es)
    | Ast.DefaultArray (e, n) -> ArrayDefault (mapexpr fts e, n)
  in
  let _ = typeof_expr fts e in
  e
;;
