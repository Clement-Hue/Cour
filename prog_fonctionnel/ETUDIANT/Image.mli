
(** Type des images *)

type pos = float * float
type image = pos -> Couleur.couleur


(** Exemples d'images *)
val im_black : image
val rayures : image
val rayuresBis: image
val lueur_40_40: Couleur.couleur -> image

(** Opération de blit *)
val blit_im : image -> image -> image


(** Type des rectangles (pour cadrer une image lors de son affichage) *)

type rectangle = { minx : float; maxx : float; miny : float; maxy : float; }
