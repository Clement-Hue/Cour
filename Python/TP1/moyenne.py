def f(x):
    x = int(x)
    print(2*pow(x,2)-x+1)

def moyenne(nombre1,nombre2):
    return (nombre1+nombre2)/2
    
x = input("entrer ne valeur de x")
f(x)
print("la moyenne de 11 et 14:",moyenne(11,14))
print("la moyenne de 18 et 15:",moyenne(18,15))
print("la moyenne de 20 et 15:",moyenne(20,15))
