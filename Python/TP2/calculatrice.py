from convert_int import *

def calculatrice(str):
    res = []
    operation = ''
    for l in str:
        if l == '+' or l=='-' or l== '/' or l=='*' or l=='=':
            print( conv_int(res))
            operation = l
            res = []
            continue
        res += l


str = input("entrer texte")
calculatrice(str)

            
