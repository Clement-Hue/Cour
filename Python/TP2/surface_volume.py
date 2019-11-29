from math import pi 

def disque_perim(rayon):
    return 2*pi*rayon 

def disque_surface(rayon):
    return pi*pow(rayon,2)

def volume_cylindre(rayon,hauteur):
   return disque_surface(rayon) * hauteur

def surface_cylindre(rayon,hauteur):
    return disque_perim(rayon) * hauteur

rayon = int(input("donner le rayon du disque"))
hauteur = int(input("donner la hauteur du cylindre"))
print("le périmètre du disque:",disque_perim(rayon))
print("la surface du disque:",disque_surface(rayon))
print("le volume du cylindre:",volume_cylindre(rayon,hauteur))
print("la surface du cylindre:",surface_cylindre(rayon,hauteur))

