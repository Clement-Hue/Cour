(** Type des couleurs. *)

type couleur = int * int * int * int   (** rouge, vert, bleu, transparence *)

(** Tous les entiers sont entre 0 et 255. *)


val mult_teinte : float -> couleur -> couleur
val mult_transp : float -> couleur -> couleur

val invisible : int
val opaque    : int
val int_to_color: int -> int -> couleur

(** Fonctions utilitaires. *)


val norm :int -> int

val blit_pix : couleur -> couleur -> couleur


