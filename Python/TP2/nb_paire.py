from random import *

liste = []
for i in range(10):
	liste.append(randint(0,100))
print(liste)
new_liste = 10*[0]
j = 0
k = 9
for i in range(10):
	if liste[i] %2 ==0:
		new_liste[j] = liste[i]
		j+=1
	elif liste[i] %2 != 0:
		new_liste[k] = liste[i]
		k-=1
print(new_liste)
	
