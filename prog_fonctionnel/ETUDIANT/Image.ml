open Couleur ;;


(** Type des images *)

type pos = float * float
type image = pos -> couleur



(** Exemples d'image *)

let im_black = (fun p -> (0, 0, 0, 255))

let rayures = 
  fun (x,y) ->  (int_of_float (x +. y) mod 255, 0, 0, 255)



let blit_im (o1:image) (o2:image) = failwith "Implémentez-moi !" ;;



(** Type des rectangles *)


type rectangle = { minx : float ; maxx : float ; miny : float ; maxy : float}
