open Couleur ;;


(** Type des images *)

type pos = float * float
type image = pos -> couleur



(** Exemples d'image *)

let im_black = (fun p -> (0, 0, 0, 255))

let rayures = 
  fun (x,y) ->  (int_of_float (x +. y) mod 255, 0, 0, 255)

let rayuresBis = 
  fun (x,y) ->  (int_of_float (x +. y) mod 255, 100, 0, 100)


let blit_im (o1:image) (o2:image) = failwith "Implémentez-moi !" ;;



(** Type des rectangles *)

let pow x puissance = x ** puissance
let square x = pow x 2.
let distance (xa, ya) (xb, yb) =  sqrt (square (xa-.xb) +. square (ya-.yb))
type rectangle = { minx : float ; maxx : float ; miny : float ; maxy : float}

let lueur center couleur point = Couleur.mult_teinte (1. /.  distance point center ) couleur
let lueur_40_40 couleur point = lueur (40.,40.) couleur point;;
