from random import *

def create_list():
    res = []
    for i in range(10):
        res.append(randint(0,100))
    return res

def partition(liste,L,R):
    pivot = liste[L]
    p=L
    L+=1
    while  L<=R:
        if liste[L] <= pivot:
            L+=1
        else:
            liste[L] , liste[R] = liste[R], liste[L]
            R-=1
    liste[p] , liste[R] = liste[R], liste[p]
    return R


def QuickSOrt(liste,L,R):
    if L>=R:
        return
    pivot = partition(liste,L,R)
    QuickSOrt(liste,L,pivot-1)
    QuickSOrt(liste,pivot+1,R)
        

    
liste = create_list()
print(liste)
QuickSOrt(liste,0,len(liste)-1)
print(liste)


