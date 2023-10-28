let sp = Printf.sprintf
let string_list sep map list = list |> List.map map |> String.concat sep
let sl sep map list = sp "[%s]" (string_list sep map list)
let slc map list = sp "[%s]" (string_list ", " map list)

exception PlatformError of string * string

type loglevel =
  | LInfo
  | LWarn
  | LError
  | LSilent

let log_level = ref LError

let info s : unit =
  match !log_level with
  | LInfo ->
    Printf.eprintf "%s\n" s;
    Out_channel.flush stderr
  | _ -> ()
;;

let warn s =
  match !log_level with
  | LWarn | LInfo ->
    Printf.eprintf "%s\n" s;
    Out_channel.flush stderr
  | _ -> ()
;;

let error s =
  match !log_level with
  | LError | LWarn | LInfo ->
    Printf.eprintf "%s\n" s;
    Out_channel.flush stderr
  | _ -> ()
;;

let sh (cmd : string) (ret : string -> int -> 'a) : 'a =
  let open Unix in
  info (sp "* %s" cmd);
  match system cmd with
  | WEXITED i -> ret cmd i
  | WSIGNALED i -> raise (PlatformError (cmd, sp "Signaled with %d." i))
  | WSTOPPED i -> raise (PlatformError (cmd, sp "Stopped with %d." i))
;;

let exec (cmd : string) (args : string list) (ret : string -> int -> 'a) : 'a =
  let open Unix in
  let cmd = Filename.quote_command cmd args in
  info (sp "* %s" cmd);
  match system cmd with
  | WEXITED i -> ret cmd i
  | WSIGNALED i -> raise (PlatformError (cmd, sp "Signaled with %d." i))
  | WSTOPPED i -> raise (PlatformError (cmd, sp "Stopped with %d." i))
;;

let raise_error cmd i =
  if i <> 0 then raise (PlatformError (cmd, sp "Exited with status %d." i))
;;

let ensure_directory_exists (dir : string) = exec "mkdir" [ "-p"; dir ] raise_error

(** takes the first n elements of a list, dropping the rest
    if the list is shorter than n elements, returns the original list *)
let rec take n lst =
  match n, lst with
  | n, _ when n <= 0 -> []
  | n, x :: xs -> x :: take (n - 1) xs
  | _, [] -> []

(** drops the first n elements of a list, yielding the rest
    if the list is shorter than n elements, returns [] *)
and skip n lst =
  match n, lst with
  | 0, x -> x
  | _, [] -> []
  | n, _ :: xs -> skip (n - 1) xs
;;

(** like |> but doesn't need a concrete argument *)
let ( >> ) f g x = x |> f |> g

