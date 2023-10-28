type program =
  { fdecls : func list
  ; gdecls : (string * gdecl) list
  ; externals : (typ * string * arg list) list
  }

and func = typ * string * arg list * cfg list
and gdecl = typ * ginit

and ginit =
  | GString of string
  | GGid of string
  | GInt of int64

and typ =
  | I64
  | Void
  | I1
  | I8
  | Array of typ * int
  | Ptr of typ

and arg = string * typ
and cfg = string * ins list

and cnd =
  | Eq
  | Ne
  | Slt
  | Sle
  | Sgt
  | Sge

and bop =
  | Add
  | Sub
  | Mul
  | Shl
  | Lshr
  | Ashr
  | And
  | Or

and operation =
  | Bop of bop * op * op
  | Alloca of typ
  | Load of typ * op
  | Store of typ * op * op
  | Cmp of typ * cnd * op * op
  | Call of typ * op * (op * typ) list
  | Getelementptr of typ * op * op list
  | Bitcast of typ * op * typ
  | Br of string
  | BrCond of op * string * string
  | RetVoid
  | Ret of typ * op

and ins = string * operation

and op =
  | Null
  | Ident of string
  | Constant of int64
  | Gident of string

let new_prog fdecls gdecls externals = { fdecls; gdecls; externals }
let sp = Printf.sprintf
let string_list sep map list = list |> List.map map |> String.concat sep
let indent s = "  " ^ s

let escape s =
  let rec aux buf chs =
    let mapch = function
      | 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | ' ' -> None
      | x -> Printf.sprintf "\\%02x" (int_of_char x) |> Option.some
    in
    match chs () with
    | Seq.Nil -> Buffer.contents buf
    | Seq.Cons (x, xs) ->
      (match mapch x with
       | Some escape -> Buffer.add_string buf escape
       | None -> Buffer.add_char buf x);
      aux buf xs
  in
  aux (Buffer.create (String.length s)) (String.to_seq s)
;;

let rec string_of_func (ty, name, args, cfgs) =
  sp
    "define %s @%s(%s) {\n%s\n}\n"
    (string_of_typ ty)
    name
    (string_list ", " string_of_arg args)
    (string_list "\n" string_of_cfg cfgs)

and string_of_typ = function
  | I64 -> "i64"
  | Void -> "void"
  | I1 -> "i1"
  | I8 -> "i8"
  | Array (t, n) -> sp "[%d x %s]" n (string_of_typ t)
  | Ptr _ -> "ptr" (*sp "%s*" (string_of_typ ty)*)

and string_of_arg (name, typ) = sp "%s %%%s" (string_of_typ typ) name

and string_of_cfg (label, blocks) =
  sp "%s:\n%s" label (string_list "\n" (fun x -> x |> string_of_ins |> indent) blocks)

and string_of_cnd : cnd -> string = function
  | Eq -> "eq"
  | Slt -> "slt"
  | Sle -> "sle"
  | Sgt -> "sgt"
  | Sge -> "sge"
  | Ne -> "ne"

and string_of_op = function
  | Null -> "null"
  | Ident s -> sp "%%%s" s
  | Constant i -> sp "%Ld" i
  | Gident s -> sp "@%s" s

and string_of_operation : operation -> string = function
  | Bop (Add, op1, op2) -> sp "add i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (Sub, op1, op2) -> sp "sub i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (Mul, op1, op2) -> sp "mul i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (Shl, op1, op2) -> sp "shl i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (And, op1, op2) -> sp "and i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (Or, op1, op2) -> sp "or i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (Lshr, op1, op2) -> sp "lshr i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Bop (Ashr, op1, op2) -> sp "ashr i64 %s, %s" (string_of_op op1) (string_of_op op2)
  | Alloca typ -> sp "alloca %s" (string_of_typ typ)
  | Load (typ, src) ->
    sp "load %s, %s %s" (string_of_typ typ) (string_of_typ (Ptr typ)) (string_of_op src)
  | Store (typ, src, dest) ->
    sp
      "store %s %s, %s %s"
      (string_of_typ typ)
      (string_of_op src)
      (string_of_typ (Ptr typ))
      (string_of_op dest)
  | Cmp (typ, cnd, op1, op2) ->
    sp
      "icmp %s %s %s, %s"
      (string_of_cnd cnd)
      (string_of_typ typ)
      (string_of_op op1)
      (string_of_op op2)
  | Call (typ, name, args) ->
    sp
      "call %s %s(%s)"
      (string_of_typ typ)
      (string_of_op name)
      (string_list
         ", "
         (fun (op, typ) -> sp "%s %s" (string_of_typ typ) (string_of_op op))
         args)
  | Getelementptr (typ, op, ops) ->
    sp
      "getelementptr %s, %s %s, %s"
      (string_of_typ (typ))
      (string_of_typ (Ptr typ))
      (string_of_op op)
      (string_list ", " (fun x -> x |> string_of_op |> ( ^ ) "i64 ") ops)
  | Bitcast (from, op, too) ->
    sp "bitcast %s %s to %s*" (string_of_typ (Ptr from)) (string_of_op op) (string_of_typ too)
  | Br lbl -> sp "br label %%%s" lbl
  | BrCond (cond, l1, l2) ->
    sp "br i1 %s, label %%%s, label %%%s" (string_of_op cond) l1 l2
  | RetVoid -> "ret void"
  | Ret (typ, op) -> sp "ret %s %s" (string_of_typ typ) (string_of_op op)

and string_of_ins (ret, opera) =
  match opera with
  | Store _ | Call (Void, _, _) | Br _ | BrCond _ | RetVoid | Ret _ ->
    string_of_operation opera
  | _ -> sp "%%%s = %s" ret (string_of_operation opera)

and string_of_externals (ex : (typ * string * arg list) list) : string =
  let soe (ty, name, args) =
    sp "declare %s @%s(%s)" (string_of_typ ty) name (string_list ", " string_of_arg args)
  in
  string_list "\n" soe ex

and string_of_gdecls (gdecls : (string * gdecl) list) : string =
  let rec s_gvalue (v : ginit) =
    match v with
    | GString s -> sp "c\"%s\"" (escape s)
    | GGid g -> sp "@%s" g
    | GInt i -> Int64.to_string i
  in
  let song (name, (ty, value)) =
    sp "@%s = global %s %s" name (string_of_typ ty) (s_gvalue value)
  in
  string_list "\n" song gdecls
;;

let string_of_llvm funcs = string_list "\n\n" string_of_func funcs

let string_of_prog { fdecls; gdecls; externals } =
  sp
    "%s\n\n%s\n\n%s"
    (string_of_externals externals)
    (string_of_gdecls gdecls)
    (string_of_llvm fdecls)
;;
