type pos =
  { line : int
  ; col : int
  }

let line_of_pos p = p.line
let col_of_pos p = p.col
let mk_pos line col = { line; col }

let min p1 p2 =
  if p1.line < p2.line || (p1.line = p2.line && p1.col < p2.col) then p1 else p2
;;

let max p1 p2 =
  if p1.line > p2.line || (p1.line = p2.line && p1.col > p2.col) then p1 else p2
;;

type t =
  { start : pos
  ; fin : pos
  ; filename : string
  }

let file_of_range range = range.filename
let start_of_range range = range.start
let end_of_range range = range.fin
let mk_range filename start fin = { filename; start; fin }
let valid_pos { line; col } = line >= 0 && col >= 0

let merge_range r1 r2 =
  if r1.filename <> r2.filename
  then
    failwith
      (Printf.sprintf
         "merge_range called on different files: %s and %s"
         r1.filename
         r2.filename)
  else if not (valid_pos r1.start)
  then r2
  else if not (valid_pos r2.start)
  then r1
  else mk_range r1.filename (min r1.start r2.start) (max r1.fin r2.fin)
;;

let string_of_range { filename; start; fin } =
  Printf.sprintf "%s:[%d.%d-%d.%d]" filename start.line start.col fin.line fin.col
;;

let norange = 
    {filename = 
        "__no_file";
        start = mk_pos 0 0;
        fin = mk_pos 0 0
    }
