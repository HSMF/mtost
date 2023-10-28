module L = Llvm
module A = Ast

exception Compile_error

type scope = (string, string * A.typ) Hashtbl.t

let enter_scope = Hashtbl.copy
let empty_scope () : scope = Hashtbl.create 64

type ctx =
  { cnt : int ref
  ; lcnt : int ref
  ; scope : scope
  ; strings : (int * string) list ref
  ; functypes : (string * (A.typ list * A.typ)) list
  }

let ctx_enter_scope ctx = { ctx with scope = enter_scope ctx.scope }

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

let reg_of (c : ctx) name =
  try Hashtbl.find c.scope name with
  | Not_found -> raise Compile_error
;;

let func_types (funcs : A.ast) : (string * (A.typ list * A.typ)) list =
  let fntyp (name, args, _, ret) = name, (List.map snd args, ret) in
  List.map fntyp funcs
;;

let rec maptype : A.typ -> L.typ = function
  | A.I64 -> L.I64
  | A.I8 -> L.I8
  | A.Bool -> L.I1
  | A.Str -> L.Ptr L.I8
  | A.UnitTyp -> L.Void
  | A.Ptr t | A.Arr t -> L.Ptr (maptype t)
;;

let rec typeof (c : ctx) (e : A.expr) =
  let open A in
  let what a = function
    | Mult | Add | Sub | Shl | Shr | Shrr | Band | Bor -> typeof c a
    | Lt | Le | Gt | Ge | Eq | Neq | Land | Lor -> Bool
  in
  let what1 x = function
    | Minus | Bnot -> typeof c x
    | Lnot -> Bool
  in
  match e with
  | Unit -> UnitTyp
  | Var x ->
    let _, t = reg_of c x in
    t
  | Int _ -> I64
  | Index (a, _) -> deref_type (typeof c a)
  | Boolean _ -> Bool
  | Fn (_, _) -> I64 (* FIXME *)
  | String _ -> Str
  | Bop (op, l, _) -> what l op
  | Uop (op, x) -> what1 x op

and deref_type a =
  match a with
  | A.Arr x | A.Ptr x -> x
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

let rec compile_item functypes strings (name, args, body, retty) : L.func =
  (* Printf.eprintf "compiling %s\n" name; *)
  let scope : scope = empty_scope () in
  let c = { scope; cnt = ref 0; lcnt = ref 1; strings; functypes } in
  (*let rec populate_scope = function
    | [] -> ()
    | (name, typ) :: xs ->
    Hashtbl.add scope name (name, typ);
    populate_scope xs
    in*)
  let rec setup_args : A.arg list -> L.ins list = function
    | [] -> []
    | (name, typ) :: xs -> begin
      (* TODO: fix this *)
      let ret = fresh c in
      Hashtbl.add scope name (ret, typ);
      [ ret, L.Alloca (maptype typ)
      ; "", L.Store (maptype typ, L.Ident name, L.Ident ret)
      ]
      @ setup_args xs
    end
  in
  let pre = setup_args args in
  let first, rest = compile_block c None body in
  ( maptype retty
  , name
  , List.map (fun (ident, typ) -> ident, maptype typ) args
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
    Hashtbl.add c.scope name (ret, typ);
    (* TODO: fix type *)
    let compiled = expc @ [ ret, L.Alloca ltyp; "", L.Store (ltyp, expr, L.Ident ret) ] in
    CompiledBlock.prepend_same compiled (compile_block c label_after xs)
  end
  | A.Assign (name, exp) :: xs -> begin
    let expc, expr = compile_expr c exp in
    let ret, typ = reg_of c name in
    let compiled = expc @ [ "", L.Store (maptype typ, expr, L.Ident ret) ] in
    CompiledBlock.prepend_same compiled (compile_block c label_after xs)
  end
  | A.Return exp :: _ -> begin
    let ret, retreg = compile_expr c exp in
    (* TODO: fix type *)
    ret @ [ "", L.Ret (L.I64, retreg) ], []
  end
  | A.Funccall (name, args) :: xs -> begin
    let expc, _expr = compile_expr c (A.Fn (name, args)) in
    let compiled = expc in
    CompiledBlock.prepend_same compiled (compile_block c label_after xs)
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

and compile_expr (c : ctx) : A.expr -> L.ins list * L.op = function
  | A.Unit -> failwith "what"
  | A.Var name -> begin
    let dest, typ = reg_of c name in
    let ret = fresh c in
    [ ret, L.Load (maptype typ, L.Ident dest) ], L.Ident ret
  end
  | A.Int i -> [], L.Constant i
  | A.Boolean true -> [], L.Constant 1L
  | A.Boolean false -> [], L.Constant 0L
  | A.Fn (name, args) -> begin
    let comp_args = List.map (compile_expr c) args in
    let ret = fresh c in
    (* TODO: figure out return type of function *)
    (* Printf.eprintf "%s\n" name; *)
    let rettyp = List.assoc name c.functypes |> snd |> maptype in
    let args =
      List.assoc name c.functypes
      |> fst
      |> List.map maptype
      |> List.map2 (fun (_, a) b -> a, b) comp_args
    in
    ( (comp_args |> List.map fst |> List.concat) @ [ ret, L.Call (rettyp, name, args) ]
    , L.Ident ret )
  end
  | A.String s -> begin
    let n = List.length !(c.strings) in
    c.strings := (n, s) :: !(c.strings);
    [], L.Gident (string_naming n)
  end
  | A.Bop
      (((A.Add | A.Mult | A.Sub | A.Shl | A.Shr | A.Shrr | A.Band | A.Bor) as op), l, r)
    -> begin
    let mapbop = function
      | A.Add -> L.Add
      | A.Mult -> L.Mul
      | A.Sub -> L.Sub
      | A.Shl -> L.Shl
      | A.Shr -> L.Lshr
      | A.Shrr -> L.Ashr
      | A.Band -> L.And
      | A.Bor -> L.Or
      | _ -> failwith "should not happen"
    in
    let op = mapbop op in
    let a, areg = compile_expr c l in
    let b, breg = compile_expr c r in
    let ret = fresh c in
    a @ b @ [ ret, L.Bop (op, areg, breg) ], L.Ident ret
  end
  | A.Bop (((A.Lt | A.Le | A.Eq | A.Neq | A.Gt | A.Ge) as op), l, r) -> begin
    let mapbop = function
      | A.Lt -> L.Slt
      | A.Le -> L.Sle
      | A.Eq -> L.Eq
      | A.Neq -> L.Ne
      | A.Gt -> L.Sgt
      | A.Ge -> L.Sge
      | _ -> failwith "should not happen"
    in
    let cnd = mapbop op in
    let a, areg = compile_expr c l in
    let b, breg = compile_expr c r in
    let typ = typeof c l in
    let ret = fresh c in
    a @ b @ [ ret, L.Cmp (maptype typ, cnd, areg, breg) ], L.Ident ret
  end
  | A.Bop (b, _, _) ->
    failwith (Printf.sprintf "todo: handle other binary ops: %s" (A.bop_to_string b))
  | A.Uop (A.Minus, x) -> begin
    let a, areg = compile_expr c x in
    let ret = fresh c in
    a @ [ ret, L.Bop (L.Sub, L.Constant 0L, areg) ], L.Ident ret
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
  | A.Uop (_, _) -> failwith "kjhassd"
;;

let compile (funcs : A.ast) : L.program =
  let functypes =
    ("printd", ([ A.I64 ], A.UnitTyp))
    :: ("printc", ([ A.I8 ], A.UnitTyp))
    :: func_types funcs
  in
  let open L in
  let strings = ref [] in
  let fdecls = List.map (compile_item functypes strings) funcs in
  let strings : (string * gdecl) list =
    let make_gdecl (i, s) =
      string_naming i, (L.Array (L.I8, String.length s + 1), GString (s ^ "\x00"))
    in
    (!strings) |> List.map make_gdecl
  in
  let externals = [ Void, "printd", [ "x", I64 ]; Void, "printc", [ "x", I8 ] ] in
  L.new_prog (fdecls) strings externals
;;
