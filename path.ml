type t = string list

let prepend_path (basepath : t) (root : t) = basepath @ root
let to_string: t -> string = Util.string_list "::" Fun.id
