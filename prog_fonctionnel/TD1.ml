(** 
 * Séance de TD n°1                                   *
 *                                                    *
 * Objectifs du jour :                                *
 *    1) s'exercer à programmer sans effet de bord    *
 *    2) syntaxe OCaml                                *    
 *                                                    *) 


(** Fonction pour afficher les résultats des tests *)
let check b =
  print_string (if b then "[SUCCES]" else "[ECHEC]") ;;



(* --------------------------------------------------------- *)

(** Exercice 1 : Écrire une fonction sqsum_int qui prend en  *
  * paramètre deux entiers et renvoit la somme des carrés de *
  * tous les nombres entiers entre ces deux entiers.         *
  * On suppose que le premier paramètre est plus petit ou    *     
  * égal au second.                                          *)


(* en C ou Java : sqsum (a,b) *)

(* En Caml : sqsum a b *)

(* En Caml : sqsum (a + 1) b *)

(* Ce qui ne marche pas : sqsum (a b) *)

let rec sqsum_int n m = 
  if n=m
  then n*n 
  else (n*n) + (sqsum_int (n+1) m)
 ;;

(* Version Alexandre *)
let rec sqsum_int n m =
    (n * n) + (if n < m then (sqsum_int (n + 1) m) else 0)
;;


(* version optimale: *)
let rec sqsum_int n m = 
  if n>m
  then 0 
  else (n*n) + (sqsum_int (n+1) m)
 ;;


(** tests *)
check (sqsum_int 3 3 = 9 ) ;;
check (sqsum_int 3 4 = 25) ;; 
check (sqsum_int 3 5 = 50) ;; 



(* --------------------------------------------------------- *)

(** Exercice 2 : Écrire une fonction qui calcule la moyenne      *
  * (entière) des éléments d'une liste d'entiers.                *
  * Indication :                                                 *
  * faire une fonction qui calcule la taille d'une liste et une  *
  * fonction qui calcule la somme des éléments d'une liste.      *) 

open List ;;

(* (hd s) premier élément de s   *)
(* (tl s) reste de s             *)

(* Première version *)

(* Version sans filtrage *)
let rec len s =
  if s = [] 
  then 0
  else 1 + (len (tl s)) ;;

(* rappel : [] est la liste vide *)
(*         1::[] est la liste qui contient 1 et rien d'autre *)
(*     1 :: 2 :: [] se lit 1 :: (2::[])                       *)

(*                   ::
                    /  \
                   1   ::
                      /  \
                     2   []                                    *)

(* Version avec filtrage *)
let rec len s =
  match s with

  | []      ->  0

  | _ :: r  ->  1 + (len r) 
;;
    


let rec somme s =
  if s = []
  then 0
  else (hd s) + (somme (tl s)) ;;


let rec somme s =
  match s with 

  | []     -> 0 

  | e :: r -> e + (somme r)  

 ;;


(* avantages  :
   1) visuel (règles, cas)
   2) structure cas d'arret / cas récursif un peu automatique 
   3) réflexes qui amène une décomposition du problème gratuitement
   4) sûreté : cas oubliés + cas inatteignables

  trois familles d'avantages : lisibilité/clarté ; maintenabilité ; sûreté.


*) 

let moyenne s = (somme s) / (len s) ;;

(* seconde version *)

let moyenne s =
  
  (* déclaration locale *)
  let rec len s =
    if s = [] 
    then 0
    else 1 + (len (tl s)) 
  in

  let rec somme s =
    if s = []
    then 0
    else (hd s) + (somme (tl s))
  in

  (somme s) / (len s) ;;



(** tests *)
check (moyenne (1::(2::(3::[]))) = 2) ;;



(* --------------------------------------------------------- *)

(** Exercice 3 : Écrire une fonction qui teste si un entier est  *
  *  présent dans une liste.                                     *)

let rec member e s = 
  if s = []
  then false
  else 
    if (hd s) = e 
    then true
    else (member e (tl s))         
 ;;

(* (if f(5) then true else false) se simplifie en (f(5)) *)

(* (if f(5) then true else g(6)) se simplifie en (f(5) || g(6)) *)

(* (if f(5) then g(6) else false) se simplifie en (f(5) && g(6)) *)

(* autre version : *)
let rec member e s = 
  if s = []
  then false
  else ((hd s) = e) || (member e (tl s))         
;;

let rec  member e s = 
  match s with
  | []     -> false
  | n :: r -> (n = e) || (member e r) ;; 

let rec  member e s = 
  match s with

  | []                  -> false

  | n :: r when (n = e) -> true

  | n :: r              -> (member e r) 

;; 



(* tests *)
check (not (member 0 [])) ;;
check (member 1 (1::2::3::[])) ;;
check (member 3 (1::2::3::[])) ;;
check (not (member 4 (1::2::3::[]))) ;;







(* --------------------------------------------------------- *)

(** Exercice 4 : Écrire une fonction qui compte le nombre    *
  * d'éléments qui vérifient une condition donnée dans une   *
  * liste.    (ORDRE SUPERIEUR)                              *)

let rec compte f s = 
  if s = []
  then 0
  else 
    if f (hd s)
    then 1 + (compte f (tl s))
    else compte f (tl s)
;;

let rec compte f s = 
  if s = []
  then 0
  else 
    (if f (hd s) then 1 else 0) + (compte f (tl s))
;;

(* Réécrire cette fonction en utilisant du filtrage (pattern-matching)
   à la place des if/then/else.                                       *)

(* meilleure solution (subjectif) *)
let rec compte f s =
  match s with
  | []                -> 0
  | e :: r when (f e) -> 1 + compte f r
  | e :: r            -> compte f r
;;

(* variante, que je n'aurais pas choisie *)
let rec compte f s =
  match s with
  | []                -> 0
  | e :: r  -> (if f e then 1 else 0) + (compte f r)
;;



(* tests *)
let positif x = (x>0) 
in check (compte positif [] = 0 )  ;;

check (compte ( fun x -> (x>0) ) [] = 0 )  ;;
check (compte ( fun x -> (x>0) ) (0::1::2::[]) = 2 )  ;;
check (compte ( fun x -> (x>1) ) (0::1::2::[]) = 1 )  ;;


(* --------------------------------------------------------- *)

(** Exercice 5 : Écrire une fonction qui insère un élément dans *  
  * une liste triée.                                            *
  * Attention : les structures de données sont non-mutables :   *
  * on renvoit une nouvelle liste, on ne modifie pas celle      *
  *  reçue en paramètre.                                        *)

let insere e s = [] (* remplir ici *) ;;

(* tests *)
check (insere 1 [] = 1::[]) ;;
check (insere 3 (1::2::[]) = 1::2::3::[]) ;;
check (insere 1 (2::3::[]) = 1::2::3::[]) ;;

(* --------------------------------------------------------- *)
