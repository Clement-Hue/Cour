def es_ce_un_graphe_oriente(matrice):
	for i in range(len(matrice)):
		for j in range(i):
			if matrice[i][j] != matrice[j][j]:
				return False
	return True

class noeud:
	def __init__(self,num,liste_adjacant):
		self.num = num
		self.liste_adjacant = liste_adjacant
 

class graphe:
	def __init__(self,liste_adjacant,oriented):
		self.liste_adjacant = liste_adjacant
		self.oriented = oriented
	
	def is_it_oriented(self):
		for i in range(len(self.liste_adjacant)):
			print(liste_adjacant[i])
	#		for j in self.liste_adjacant[i]:
	#			if i not in self.liste_adjacant[j]: 
	#				return False
	#	self.oriented = False
		return True

def transforme_matrice_into_liste(matrice_adjacant):
	liste_adjacant = []
	for i in range(len(matrice_adjacant)):
		liste_adjacant.append([])
		for j in range(len(matrice_adjacant[i])):
			if matrice_adjacant[i][j] == 1:
				liste_adjacant[i].append(j+1)
	return liste_adjacant

#def  transforme_liste_into_matrice(liste_adjacant)
#	for i in range(len(liste_adjacant))::
#		for j in liste_adjacant[i]:
#			matrice_adjacant[i][j] = 





		
matrice_adjacant = [[0,1,0,1],[1,1,1,0],[0,0,0,1],[1,1,0,0]]
print(transforme_matrice_into_liste(matrice_adjacant))
noeud1 = noeud(1,[2,3,4]) 
noeud2 = noeud(2,[1,3])
noeud3 = noeud(3,[1,2,4])
noeud4 = noeud(4,[1,2,3])
liste_adjacant = graphe([noeud1,noeud2,noeud3,noeud4],False)
print(liste_adjacant.is_it_oriented())
	
