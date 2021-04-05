open Image
open ImageDump

(* Utiliser ce fichier pour appeler et tester vos fonctions. *)


(* Test 1 *)
(* let _ = print_ppm  { minx = 0.0 ; maxx = 768.0 ; miny =  0.0 ; maxy = 1024.0} (1024,768) rayuresBis ;; *)
let _ = print_ppm  { minx = 0.0 ; maxx = 768.0 ; miny =  0.0 ; maxy = 1024.0} (1024,768) ( blit_im  (lueur (120., 120. ) (255,255,255,255)) (lueur (100., 100.) (0,0,255,255)) ) ;; 





