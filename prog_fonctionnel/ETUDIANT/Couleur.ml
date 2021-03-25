(** Type des couleurs. *)



type couleur = int * int * int * int   (** rouge, vert, bleu, transparence *)

(** Tous les entiers sont entre 0 et 255. *)



let invisible = 0
and opaque    = 255


(** Fonctions utilitaires. *)


let norm n = min 255 (max 0 n)


let blit_pix (r1,v1,b1,t1) (r2,v2,b2,_) =

    let f val1 val2 t =
      let ratio1 = 255 - t
      and ratio2 = t 
      in
      (ratio1 * val2 + ratio2 * val1) / 255 

    in  (f r1 r2 t1,  f v1 v2 t1,  f b1 b2 t1,  t1)  ;;


let mult_teinte coeff (r,v,b,t) = failwith "Implémentez-moi !"
let mult_transp coeff (r,v,b,t) = failwith "Implémentez-moi !"
