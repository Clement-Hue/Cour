i = 0
moyenne = 0 
while True:
    nombre = input("saisir nombre")
    if len(nombre) ==0:
        break
    nombre = int(nombre)
    if i == 0:
        minimum = nombre
        maximum = nombre
    i+=1
    if nombre < minimum:
        minimum = nombre
    if nombre > maximum:
        maximum = nombre
    moyenne += nombre
moyenne /= i
print("le minimum est",minimum,"le maximum est",maximum,"la moyenne est",moyenne)

