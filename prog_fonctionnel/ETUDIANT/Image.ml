open Couleur 
open Mandelbrot


(** Type des images *)

type pos = float * float
type image = pos -> couleur



(** Exemples d'image *)

let im_black = (fun p -> (0, 0, 0, 255))

let rayures = 
  fun (x,y) ->  (int_of_float (x +. y) mod 255, 0, 0, 255)

let rayuresBis = 
  fun (x,y) ->  (int_of_float (x +. y) mod 255, 100, 0, 100)


let blit_im (o1:image) (o2:image) = fun pos ->  blit_pix (o1 pos ) (o2 pos )

let rec blitz list_im  = 
  match list_im with
  | [] ->  im_black
  | e::r -> blit_im e (blitz r ) 


let image_mandlebrot precision pos= 
   match Mandelbrot.mandelbrot precision  pos with
  | Mandelbrot.Diverge precision ->   (255,255,255,255)
  | Mandelbrot.MaxIter ->  (0,0,0,255)

(** Type des rectangles *)

let pow x puissance = x ** puissance
let square x = pow x 2.
let distance (xa, ya) (xb, yb) =  sqrt (square (xa-.xb) +. square (ya-.yb))
type rectangle = { minx : float ; maxx : float ; miny : float ; maxy : float}
let inverse_distance a b = 1. /. distance a b
let lueur center couleur point = Couleur.mult_transp (inverse_distance point center) (Couleur.mult_teinte (inverse_distance point center ) couleur)
let lueur_40_40 couleur point = lueur (40.,40.) couleur point;;
