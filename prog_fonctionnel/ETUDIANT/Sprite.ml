open Couleur
open Image

(* attention : Image = mon module, Images = liccamlimages *)

let transp_couleur = ( ( 0, 0, 0, invisible) : couleur )

let couleur_of_color c = (c.Color.r, c.Color.g, c.Color.b, 255)

let load fic =
  try
    Bmp.load fic [] 
  with Failure m -> failwith ("echec de chargement : " ^m)
;;

let col_of_col (a,b,c) = {Color.r=a ; Color.g = b ; Color.b = c}

let image_of_sprite fic transp_coul =
  let i = load fic 
  and transp = col_of_col transp_coul
  in match i with
  | Images.Rgb24 i'  ->
    (fun (x,y) ->    
      let e = Rgb24.get i' (int_of_float x) (int_of_float y) 
      in if e = transp 
	then transp_couleur
	else couleur_of_color e
	  
    )
  | _ -> failwith "erreur de chargement format RGB"
    

let masuperimage = image_of_sprite "spaceharriermsripng7bis.bmp" (1, 47, 69) ;;
(* attention, ici on a vraiment envie de ne pas utiliser l'application de image_of_sprite  à tous les arguments, on veut récupérer une fonction. Si on repassait le nom de fichier à chaque fois qu'on voudrait accéder à un pixel, on rechargerait l'image (Png.load_as_rgb24). *)






