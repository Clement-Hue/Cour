from math import * 

def je_devine(nombre_secret):
    borne_inf = 0
    borne_sup = 100
    milieu  = 0
    while milieu != nombre_secret:
        milieu = (borne_inf + borne_sup)//2
        if milieu < nombre_secret:
            print(milieu," c'est plus élevé\n")
            borne_inf = milieu  +1
        elif milieu > nombre_secret:
            print(milieu,"c'est en dessous\n")
            borne_sup = milieu-1
        else:
            print(milieu,"vous avez gagné\n")


nombre_secret = int(input("entrer un nombre secret\n"))
je_devine(nombre_secret)
