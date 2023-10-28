open Ast

let no_implicit_return items : item list =
  let rec visit_body (b : block) : block =
    match b with
    | [] -> [ Return Unit ]
    | [ Return x ] -> [ Return x ]
    | x :: xs -> x :: visit_body xs
  and visit_item = function
    | FuncDecl (name, args, body, retty) -> FuncDecl (name, args, visit_body body, retty)
    | x -> x
  in
  List.map visit_item items
;;
