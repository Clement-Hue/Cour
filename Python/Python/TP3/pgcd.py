def pgcd(a,b):
    if b == 0:
        return a
    return pgcd(b,a%b)

a = int(input('entrer valeur de a'))
b = int(input("entrer valuer de b"))
print(pgcd(a,b))
