(integer) @number
[(string) (char)] @string
(escape_seq) @string.escape

(id) @variable
(externdecl (id) @function)
(func (id) @function)
(comment) @comment
(fncall (id) @function)
[
 (bop)
 (uop)
] @operator

[
 "if"
 "else"
] @conditional
"loop" @repeat


[
  "return"
  "fun"
  "toaster"
  "let"
  "extern"
  "break"
  ; "import"
] @keyword

[
 "("
 ")"
 "["
 "]"
 "{"
 "}"] @punctuation.bracket


[
  "true"
  "false"
] @boolean

(ty) @type

(ERROR) @error
