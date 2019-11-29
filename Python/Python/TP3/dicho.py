from random import *

def dicho(liste,valeur,borne_inf,borne_sup):
    milieu = (borne_inf + borne_sup)//2
    if borne_inf > borne_sup:
        return False
    elif valeur < liste[milieu]:
        borne_sup = milieu-1
        return dicho(liste,valeur,borne_inf,borne_sup)
    elif valeur > liste[milieu]:
        borne_inf = milieu + 1
        return dicho(liste,valeur,borne_inf,borne_sup)
    elif valeur == liste[milieu]:
        return milieu


res = []
for i in range(100):
    res.append(randint(1,100))
res.sort()
print(res)
valeur = int(input("entrer nombre recherché"))
print(dicho(res,valeur,0,100))

