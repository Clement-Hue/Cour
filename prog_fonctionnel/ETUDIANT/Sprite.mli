

(* Charge un fichier sous forme d'image. *)
(* Le fichier n'a besoin d'être chargé qu'une seule fois,                           *
 * l'image résultante pouvant être utilisée sans provoquer à nouveau de chargement. *)
val image_of_sprite : string -> (int*int*int) -> Image.image
