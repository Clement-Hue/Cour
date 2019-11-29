import math

def second_degre(a,b,c):
    a = int(a)
    b = int(b)
    c = int(c)
    delta = pow(b,2) - 4*a*c
    if delta >0:
        x1= (-b+math.sqrt(delta) ) / 2*a
        x2= (-b-math.sqrt(delta) ) / 2*a
        print("x1="+str(x1)+" et x2="+str(x2))
        return
    elif abs(delta) <= 0.00001:
        x = -b / (2*a)
        print("x=",x)
        return
    elif delta < 0:
        print("pas de solution")
        return

a = input("entrer le coefficient a")
b = input("entrer le coefficient a")
c = input("entrer le coefficient a")
second_degre(a,b,c)
