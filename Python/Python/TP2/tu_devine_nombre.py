from random import randint

def devine():
    nombre_a_deviner = randint(0,100)
    nombre = 0
    while (nombre != nombre_a_deviner):
        nombre = int(input("entrer un entier\n"))
        if nombre < nombre_a_deviner:
            print("le nombre est plus élevé\n")
        elif nombre > nombre_a_deviner:
            print("le nombre est plus petit\n")
        else:
            print("vous avez gagné")
   
devine()
