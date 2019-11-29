def NbChiffre(n,base):
    if n ==0:
        return 0
    n//=base
    return 1 + NbChiffre(n,base)

def convert(n,base):
    if n==0:
        return 0
    return n%base + convert(n//base,base)*10

    


n = int(input("entrer une valeur n"))
base = int(input("entrer la base"))
print(NbChiffre(n,base))
print(convert(n,base))
print(convert_inv(n,base))
