from random import *

res = []
new_liste = []
for i in range(0,10):
    res.append(randint(0,100))
    new_liste.append(res[i])
for i in range(0,9):
    if new_liste[i]%2 != 0 and new_liste[i+1] % 2 == 0:
        new_liste[i], new_liste[i+1] = new_liste[i+1], new_liste[i]

print(res)
print(new_liste)
