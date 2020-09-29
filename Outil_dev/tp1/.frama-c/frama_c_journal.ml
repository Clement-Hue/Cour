(* Frama-C journal generated at 11:07 the 18/09/2020 *)

exception Unreachable
exception Exception of string

(* Run the user commands *)
let run () =
  Dynamic.Parameter.String.set "" "prog1.c";
  File.init_from_cmdline ();
  Project.set_keep_current false;
  Dynamic.Parameter.Int.set "-wp-steps" 1;
  Dynamic.Parameter.Int.set "-wp-steps" 2;
  Dynamic.Parameter.Int.set "-wp-steps" 3;
  Dynamic.Parameter.Int.set "-wp-steps" 4;
  Dynamic.Parameter.Int.set "-wp-steps" 5;
  Dynamic.Parameter.Int.set "-wp-steps" 6;
  Dynamic.Parameter.Int.set "-wp-steps" 7;
  Dynamic.Parameter.Int.set "-wp-steps" 8;
  Dynamic.Parameter.Int.set "-wp-steps" 9;
  Dynamic.Parameter.Int.set "-wp-steps" 10;
  Dynamic.Parameter.Int.set "-wp-steps" 11;
  Dynamic.Parameter.Int.set "-wp-steps" 10;
  Dynamic.Parameter.Int.set "-wp-steps" 9;
  Dynamic.Parameter.Int.set "-wp-steps" 8;
  Dynamic.Parameter.Int.set "-wp-steps" 7;
  Dynamic.Parameter.Int.set "-wp-steps" 6;
  Dynamic.Parameter.Int.set "-wp-steps" 5;
  Dynamic.Parameter.Int.set "-wp-steps" 4;
  Dynamic.Parameter.Int.set "-wp-steps" 3;
  Dynamic.Parameter.Int.set "-wp-steps" 2;
  Dynamic.Parameter.Int.set "-wp-steps" 1;
  Dynamic.Parameter.Int.set "-wp-steps" 0;
  ()

(* Main *)
let main () =
  Journal.keep_file "./.frama-c/frama_c_journal.ml";
  try run ()
  with
  | Unreachable -> Kernel.fatal "Journal reaches an assumed dead code" 
  | Exception s -> Kernel.log "Journal re-raised the exception %S" s
  | exn ->
    Kernel.fatal
      "Journal raised an unexpected exception: %s"
      (Printexc.to_string exn)

(* Registering *)
let main : unit -> unit =
  Dynamic.register
    ~plugin:"Frama_c_journal.ml"
    "main"
    (Datatype.func Datatype.unit Datatype.unit)
    ~journalize:false
    main

(* Hooking *)
let () = Cmdline.run_after_loading_stage main; Cmdline.is_going_to_load ()
