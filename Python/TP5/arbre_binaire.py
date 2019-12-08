class Node:
	def __init__(self,valeur,n1,n2):
		self.valeur = valeur
		self.gauche = n1
		self.droite = n2

	def insertion(self,valeur):
		if valeur > self.valeur:
			if self.droite == None:
				self.droite  = Node(valeur,None,None)
			else:
				self.droite.insertion(valeur)
		else:
			if self.gauche == None:
				self.gauche  = Node(valeur,None,None)
			else:
				self.gauche.insertion(valeur)

	def insert_iterative(self,valeur):
		while self != None:
			if valeur > self.valeur:
				if self.droite == None:
					self.droite  = Node(valeur,None,None)
					return
				self = self.droite
			else:
				if self.gauche == None:
					self.gauche  = Node(valeur,None,None)
					return
				self= self.gauche
				


class Arbre_binaire:
	def __init__(self):
		self.root = None

	def insertion(self,valeur):
#        if self.root == None:
#            self.root = Node(valeur,None,None)
#            return
#        self.root.insertion(valeur)
		if self.root == None:
			self.root = Node(valeur,None,None)
			return
		self._insertion(valeur,self.root)

	
	def _insertion(self,valeur,node):
		if valeur > node.valeur:
			if node.droite == None:
				node.droite  = Node(valeur,None,None)
			else:
				self._insertion(valeur,node.droite)
		else:
			if node.gauche == None:
				node.gauche  = Node(valeur,None,None)
			else:
				self._insertion(valeur,node.gauche)
	
	def insert_iterative(self,valeur):
#	    if self.root == None:
#	        self.root = Node(valeur,None,None)
#			return	 
		if self.root == None:
			self.root = Node(valeur,None,None)
			return
		node = self.root
		while node != None:
			if valeur > node.valeur:
				if node.droite == None:
					node.droite  = Node(valeur,None,None)
					return
				node = node.droite
			else:
				if node.gauche == None:
					node.gauche  = Node(valeur,None,None)
					return
				node= node.gauche


		
	def recherche(self,valeur):
		if self.root == None:
			return False
		return self._recherche(valeur,self.root)	


	def _recherche(self,valeur,node):
		if valeur == node.valeur:
			return True
		if valeur > node.valeur:
			if node.droite != None:
				return self._recherche(valeur,node.droite)
		else:
			if node.gauche != None:
				return self._recherche(valeur,node.gauche)
		return False 
	
	def recherche_iteratif(self,valeur):
		if self.root == None:
			return False
		node = self.root
		while node != None:
			if valeur == node.valeur:
				return True
			if valeur > node.valeur:
				node = node.droite
			else:
				node = node.gauche
		return False

				

	def parcour(self):
		self._parcour(self.root)

	def _parcour(self,node):
		if node == None:
			return
		self._parcour(node.gauche)
		print(node.valeur)
		self._parcour(node.droite)
	
	def liste_trie(self):
		if self.root == None:
			return
		liste = []
		self._liste_trie(self.root,liste)
		return liste

	def _liste_trie(self,node,liste):
		if node is None:
			return
		self._liste_trie(node.gauche,liste)
		liste.append(node.valeur)
		self._liste_trie(node.droite,liste)
		

def tri(liste):
	arbre = Arbre_binaire()
	for i in range(len(liste)):
		arbre.insertion(liste[i])
	return arbre.liste_trie()
		


a =  Arbre_binaire()
a.insert_iterative(10)
a.insert_iterative(5)
a.insert_iterative(20)
print('10 dans la liste ?\n',a.recherche_iteratif(10))
print('parcour:')
a.parcour()
print('liste trié:')
print(tri([5,4,8,9,2,1,6,8]))




		
		
