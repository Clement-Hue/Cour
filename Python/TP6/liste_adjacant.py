def es_ce_un_graphe_oriente(matrice):
	for i in range(len(matrice)):
		for j in range(i):
			if matrice[i][j] != matrice[j][j]:
				return False
	return True

class noeud:
	def __init__(self,num,liste_adjacant=None):
		self.num = num
		self.liste_adjacant = liste_adjacant

	def add_liste_adjacant(self,liste_adjacant):
		self.liste_adjacant = liste_adjacant
 

class graphe:
	def __init__(self,liste_noeud,oriented):
		self.liste_noeud = liste_noeud 
		self.oriented = oriented
		self.nb_sommet = len(self.liste_noeud)
	
	def is_it_oriented(self):
		for noeud in self.liste_noeud:
			for noeud_ajdacant in noeud.liste_adjacant: 
				if noeud not in noeud_ajdacant.liste_adjacant: 
					return True 
		return False 

	def nb_arete(self):
		nb_arete = 0
		for noeud in self.liste_noeud:
			for noeud_adjacant in noeud.liste_adjacant:
				nb_arete+=1	
		return nb_arete//2

	def ajout_arete(self,noeud_graph,noeud_hors_graph):
		noeud_graph.liste_adjacant.append(noeud_hors_graph)
		noeud_hors_graph.liste_adjacant.append(noeud_graph)
		

def transforme_matrice_adj_into_liste(matrice_adjacant):
	liste_noeud = [] 
	for i in range(len(matrice_adjacant)):
		liste_adjacant = []
		for j in range(len(matrice_adjacant[i])):
			if matrice_adjacant[i][j] == 1:
				liste_adjacant.append(j)
		node = noeud(i,liste_adjacant)
		liste_noeud.append(node)
	graph = graphe(liste_noeud,False)
	return graph 

def  transforme_liste_into_matrice_adj(liste_adjacant):
	matrice = []
	for i in range(len(liste_adjacant)):
		matrice.append([0]* len(liste_adjacant))
	for noeud in liste_adjacant: 
		for noeud_adjacant in noeud.liste_adjacant:
			matrice[noeud.num][noeud_adjacant.num]  = 1
	return matrice

def transform_liste_into_matrice_inc(graphe):
	matrice = []
	for i in range(graphe.nb_arete()):
		matrice.append([0] * graphe.nb_sommet)
	i=0


	return matrice


		
		 
		
			
		
matrice_adjacant = [[0,1,0,1],[1,1,1,0],[0,0,0,1],[1,1,0,0]]
print(transforme_matrice_adj_into_liste(matrice_adjacant).liste_noeud)
noeud0 = noeud(0)
noeud1 = noeud(1)
noeud2 = noeud(2)
noeud3 = noeud(3)
noeud0.add_liste_adjacant([noeud1,noeud3,noeud2])
noeud1.add_liste_adjacant([noeud2,noeud3,noeud0])
noeud2.add_liste_adjacant([noeud1,noeud0])
noeud3.add_liste_adjacant([noeud0,noeud1])
graphe = graphe([noeud0,noeud1,noeud2,noeud3],False)
print(graphe.is_it_oriented())
print(transforme_liste_into_matrice_adj(graphe.liste_noeud))
print(transform_liste_into_matrice_inc(graphe))
	
