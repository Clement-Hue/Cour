from random import *

liste = []
for i in range(10):
	liste.append(randint(0,100))
print(liste)
for i in range(10):
	if liste[i] %2 == 0:
		continue
	else:
		for j in range(i+1,10):
			if liste[j] %2==0:
				liste[i],liste[j] = liste[j], liste[i]
				break
print(liste)
