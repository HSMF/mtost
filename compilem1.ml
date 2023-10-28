module L = Llvm
module A = Mid1

exception Compile_error

type scope = (string, string * A.Ty.t) Hashtbl.t

let enter_scope = Hashtbl.copy
let empty_scope () : scope = Hashtbl.create 64

type ctx =
  { cnt : int ref
  ; lcnt : int ref
  ; strings : (int * string) list ref
  ; scope : (string * (L.op * A.Ty.t)) list ref
  ; ret : A.Ty.t
  }

let ctx_enter_scope ctx = { ctx with scope = ref !(ctx.scope) }

let fresh (ctx : ctx) =
  let value = !(ctx.cnt) in
  ctx.cnt := value + 1;
  Printf.sprintf "v%d" value
;;

let fresh_lbl (ctx : ctx) =
  let value = !(ctx.lcnt) in
  ctx.lcnt := value + 1;
  Printf.sprintf "L%d" value
;;

let string_naming d = Printf.sprintf "str%d" d

let get_reg (c : ctx) name =
  try List.assoc name !(c.scope) |> fst with
  | Not_found -> raise Compile_error
;;

let get_typ (c : ctx) name =
  try List.assoc name !(c.scope) |> snd with
  | Not_found ->
    !(c.scope)
    |> List.map (fun (n, (_, ty)) -> Printf.sprintf "%s: %s" n (A.Ty.to_string ty))
    |> String.concat ", "
    |> ( ^ ) " "
    |> ( ^ ) name
    |> failwith
;;

let rec maptype : A.Ty.t -> L.typ =
  let open A.Ty in
  function
  | I64 -> L.I64
  | I8 -> L.I8
  | Bool -> L.I1
  (* | Str -> L.Ptr L.I8 *)
  | Unit -> L.Void
  | Arr t -> L.Ptr (maptype t)
  | Func _ -> failwith "todo: map function types"
;;

let typeof (c : ctx) (e : A.expr) =
  let f (a, (_, c)) = a, c in
  A.typeof_expr (List.map f !(c.scope)) e

and deref_type a =
  match a with
  | A.Ty.Arr x -> x
  | _ -> failwith "index into non array"
;;

module CompiledBlock = struct
  type t = L.ins list * L.cfg list

  let prepend_same (ins : L.ins list) ((cont, branches) : t) : t = ins @ cont, branches
  let insert_cfgs (cfgs : L.cfg list) ((cont, branches) : t) : t = cont, cfgs @ branches
  let same ((cont, _) : t) = cont
  let rest ((_, x) : t) = x

  let append (ins : L.ins list) ((cont, branches) : t) =
    let rec append_last (i : L.ins list) : L.cfg list -> L.cfg list = function
      | [] -> []
      | [ (l, x) ] -> [ l, x @ i ]
      | x :: xs -> x :: append_last i xs
    in
    match branches with
    | [] -> cont @ ins, []
    | _ -> cont, append_last ins branches
  ;;
end

let ( => ) (name, x) ls = if name <> "<anon>" then ls := (name, x) :: !ls

let rec compile_item scope (strings : (int * string) list ref) (item : A.item) : L.func =
  (* Printf.eprintf "compiling %s\n" name; *)
  let open A in
  let c : ctx =
    { cnt = ref 0; lcnt = ref 1; strings; scope = ref scope; ret = item.retty }
  in
  let rec setup_args : A.arg list -> L.ins list = function
    | [] -> []
    | (name, typ) :: xs -> begin
      let ret = fresh c in
      (name, (L.Ident ret, typ)) => c.scope;
      [ ret, L.Alloca (maptype typ)
      ; "", L.Store (maptype typ, L.Ident name, L.Ident ret)
      ]
      @ setup_args xs
    end
  in
  let pre = setup_args item.args in
  let first, rest = compile_block c None item.body in
  ( maptype item.retty
  , item.name
  , List.map (fun (ident, typ) -> ident, maptype typ) item.args
  , ("L0", pre @ first) :: rest )

and compile_block (c : ctx) (label_after : string option) : A.block -> CompiledBlock.t
  = function
  | [] -> [], []
  (* should be: A.Return x when typeof x == Unit *)
  | A.Return A.Unit :: _ -> [ "", L.RetVoid ], []
  | A.Let (name, exp) :: xs -> begin
    let expc, expr = compile_expr c exp in
    let typ = typeof c exp in
    let ltyp = maptype typ in
    let ret = fresh c in
    (name, (L.Ident ret, typ)) => c.scope;
    let compiled =
      if name = "<anon>"
      then expc
      else expc @ [ ret, L.Alloca ltyp; "", L.Store (ltyp, expr, L.Ident ret) ]
    in
    CompiledBlock.prepend_same compiled (compile_block c label_after xs)
  end
  | A.Assign (A.RhsIdent name, exp) :: xs -> begin
    let expc, expr = compile_expr c exp in
    let ret = get_reg c name in
    let typ = get_typ c name in
    let compiled = expc @ [ "", L.Store (maptype typ, expr, ret) ] in
    CompiledBlock.prepend_same compiled (compile_block c label_after xs)
  end
  | A.Assign (A.RhsArr (name, idx), exp) :: xs -> begin
    let expc, expr = compile_expr c exp in
    let idxc, idxr = compile_expr c idx in
    let elem_ptr = fresh c in
    let arr_ptr = get_reg c name in
    let arr = fresh c in
    let typ = A.Ty.item_typ (get_typ c name) in
    let compiled =
      expc
      @ idxc
      @ [ arr, L.Load (maptype (get_typ c name), arr_ptr)
        ; elem_ptr, L.Getelementptr (maptype typ, L.Ident arr, [ idxr ])
        ; "", L.Store (maptype typ, expr, L.Ident elem_ptr)
        ]
    in
    CompiledBlock.prepend_same compiled (compile_block c label_after xs)
  end
  | A.Return exp :: _ -> begin
    let ret, retreg = compile_expr c exp in
    (* TODO: fix type *)
    ret @ [ "", L.Ret (L.I64, retreg) ], []
  end
  | A.If (cond, thn, []) :: xs -> begin
    let condc, condr = compile_expr c cond in
    let then_ctx = ctx_enter_scope c in
    let then_label = fresh_lbl c in
    let after_label = fresh_lbl c in
    let then_compiled =
      compile_block then_ctx label_after thn
      |> CompiledBlock.append [ "", L.Br after_label ]
    in
    let then_first, then_rest = CompiledBlock.(same then_compiled, rest then_compiled) in
    let comp_xs = compile_block c label_after xs in
    let comp_xs, comp_xs' = CompiledBlock.(same comp_xs, rest comp_xs) in
    ( condc @ [ "", L.BrCond (condr, then_label, after_label) ]
    , ((then_label, then_first) :: then_rest) @ [ after_label, comp_xs ] @ comp_xs' )
  end
  | A.If (cond, [], els) :: xs -> begin
    let condc, condr = compile_expr c cond in
    let else_ctx = ctx_enter_scope c in
    let then_label = fresh_lbl c in
    let after_label = fresh_lbl c in
    let then_compiled =
      compile_block else_ctx label_after els
      |> CompiledBlock.append [ "", L.Br after_label ]
    in
    let then_first, then_rest = CompiledBlock.(same then_compiled, rest then_compiled) in
    let comp_xs = compile_block c label_after xs in
    let comp_xs, comp_xs' = CompiledBlock.(same comp_xs, rest comp_xs) in
    ( condc @ [ "", L.BrCond (condr, after_label, then_label) ]
    , ((then_label, then_first) :: then_rest) @ [ after_label, comp_xs ] @ comp_xs' )
  end
  | A.If (cond, thn, els) :: xs -> begin
    let condc, condr = compile_expr c cond in
    let then_ctx = ctx_enter_scope c in
    let else_ctx = ctx_enter_scope c in
    let then_label = fresh_lbl c in
    let else_label = fresh_lbl c in
    let after_label = fresh_lbl c in
    let then_compiled =
      compile_block then_ctx label_after thn
      |> CompiledBlock.append [ "", L.Br after_label ]
    in
    let else_compiled =
      compile_block else_ctx label_after els
      |> CompiledBlock.append [ "", L.Br after_label ]
    in
    let then_first, then_rest = CompiledBlock.(same then_compiled, rest then_compiled) in
    let else_first, else_rest = CompiledBlock.(same else_compiled, rest else_compiled) in
    let comp_xs = compile_block c label_after xs in
    let thens = (then_label, then_first) :: then_rest in
    let elses = (else_label, else_first) :: else_rest in
    let comp_xs, comp_xs' = CompiledBlock.(same comp_xs, rest comp_xs) in
    ( condc @ [ "", L.BrCond (condr, then_label, else_label) ]
    , thens @ elses @ [ after_label, comp_xs ] @ comp_xs' )
  end
  | A.Loop body :: xs -> begin
    let body_ctx = ctx_enter_scope c in
    let body_label = fresh_lbl c in
    let xs_label = fresh_lbl c in
    let body_compiled =
      compile_block body_ctx (Some xs_label) body
      |> CompiledBlock.append [ "", L.Br body_label ]
    in
    let after, rest = CompiledBlock.(same body_compiled, rest body_compiled) in
    let comp_xs = compile_block c label_after xs in
    let comp_xs, comp_xs' = CompiledBlock.(same comp_xs, rest comp_xs) in
    ( [ "", L.Br body_label ]
    , ((body_label, after) :: rest) @ [ xs_label, comp_xs ] @ comp_xs' )
  end
  | A.Break :: _ -> [ "", L.Br (Option.get label_after) ], []

and compile_literal (c : ctx) : A.Lit.t -> L.op = function
  | A.Lit.I64 i -> L.Constant i
  | A.Lit.Str s -> begin
    let n = List.length !(c.strings) in
    c.strings := (n, s) :: !(c.strings);
    L.Gident (string_naming n)
  end
  | A.Lit.Bool true -> L.Constant 1L
  | A.Lit.Bool false -> L.Constant 0L
  | A.Lit.I8 i -> L.Constant (Int64.of_int i)

and compile_pseudo_function (c : ctx) (name : string) (args : A.expr list) =
  let compile_bop bop l r =
    let a, areg = compile_expr c l in
    let b, breg = compile_expr c r in
    let ret = fresh c in
    a @ b @ [ ret, L.Bop (bop, areg, breg) ], L.Ident ret
  in
  let compile_cmp cnd l r lt =
    let a, areg = compile_expr c l in
    let b, breg = compile_expr c r in
    let typ = lt in
    let ret = fresh c in
    a @ b @ [ ret, L.Cmp (maptype typ, cnd, areg, breg) ], L.Ident ret
  in
  let open Option in
  let open A.Ty in
  (* ocamlformat:skip*)
  match name, args with
  | "<op>i64mult", [ l; r ] -> compile_bop L.Mul l r |> some
  | "<op>i64add", [ l; r ] -> compile_bop L.Add l r |> some
  | "<op>i64sub", [ l; r ] -> compile_bop L.Sub l r |> some
  | "<op>i64shl", [ l; r ] -> compile_bop L.Shl l r |> some
  | "<op>i64shr", [ l; r ] -> compile_bop L.Lshr l r |> some
  | "<op>i64shrr", [ l; r ] -> compile_bop L.Ashr l r |> some
  | "<op>i64lt", [ l; r ] -> compile_cmp L.Slt l r I64 |> some
  | "<op>i64le", [ l; r ] -> compile_cmp L.Sle l r I64 |> some
  | "<op>i64gt", [ l; r ] -> compile_cmp L.Sgt l r I64 |> some
  | "<op>i64ge", [ l; r ] -> compile_cmp L.Sge l r I64 |> some
  | "<op>i64eq", [ l; r ] -> compile_cmp L.Eq l r I64 |> some
  | "<op>i64neq", [ l; r ] -> compile_cmp L.Ne l r I64 |> some
  | "<op>i64land", [ _; _ ] -> failwith "not implemented"
  | "<op>i64lor", [ _; _ ] -> failwith "not implemented"
  | "<op>i64band", [ l; r ] -> compile_bop L.And l r |> some
  | "<op>i64bor", [ l; r ] -> compile_bop L.Or l r |> some
  | "<op>i64minus", [ x ] -> compile_bop L.Sub (A.Literal (A.Lit.I64 0L)) x |> some
  | "<op>i64lnot", [ _ ] -> failwith "not implemented"
  | "<op>i64bnot", [ _ ] -> failwith "not implemented"
  | _ -> None

and compile_normal_function (c : ctx) (name : string) (args : A.expr list) =
  let comp_args = List.map (compile_expr c) args in
  let atypes, rettyp = name |> get_typ c |> A.Ty.func_typ in
  let rettyp = maptype rettyp in
  let func = get_reg c name in
  let ret = fresh c in
  ( (comp_args |> List.map fst |> List.concat)
    @ [ ( ret
        , L.Call
            ( rettyp
            , func
            , List.map2 (fun at ar -> ar, maptype at) atypes (List.map snd comp_args) ) )
      ]
  , L.Ident ret )

and compile_expr (c : ctx) : A.expr -> L.ins list * L.op = function
  | A.Unit -> failwith "what"
  | A.Var name -> begin
    let dest = get_reg c name in
    let typ = get_typ c name in
    let ret = fresh c in
    [ ret, L.Load (maptype typ, dest) ], L.Ident ret
  end
  | A.Literal l -> [], compile_literal c l
  | A.Fn (name, args) -> begin
    match compile_pseudo_function c name args with
    | Some x -> x
    | None -> compile_normal_function c name args
  end
  | A.Index (arr, idx) -> begin
    let a, areg = compile_expr c arr in
    let i, ireg = compile_expr c idx in
    let arr_idx = fresh c in
    let arr_type = typeof c arr in
    let ret = fresh c in
    ( a
      @ i
      @ [ arr_idx, L.Getelementptr (arr_type |> deref_type |> maptype, areg, [ ireg ])
        ; ret, L.Load (arr_type |> deref_type |> maptype, L.Ident arr_idx)
        ]
    , L.Ident ret )
  end
  | A.Array _ -> failwith "h"
  | A.ArrayDefault _ -> failwith "h"
;;

let compile extern declared (ast : A.t) : L.program =
  let externals =
    List.map
      (fun (name, def) ->
        let a, ret = A.Ty.func_typ def in
        maptype ret, name, List.mapi (fun i x -> Printf.sprintf "x%d" i, maptype x) a)
      extern
  in
  let prelude = List.map (fun (name, def) -> name, (L.Gident name, def)) extern in
  let declared = List.map (fun (name, def) -> name, (L.Gident name, def)) declared in
  let pseudos = List.map (fun (name, typ) -> name, (L.Null, typ)) A.operand_func_types in
  let open L in
  let strings = ref [] in
  let scope = declared @ prelude @ pseudos in
  let funcs =
    let open A in
    ast.items
  in
  let fdecls = List.map (compile_item scope strings) funcs in
  let strings : (string * gdecl) list =
    let make_gdecl (i, s) =
      string_naming i, (L.Array (L.I8, String.length s + 1), GString (s ^ "\x00"))
    in
    !strings |> List.map make_gdecl
  in
  L.new_prog fdecls strings externals
;;
