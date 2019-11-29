class cellule:
    def __init__(self,valeur):
        self.valeur = valeur
        self.suivant = None
        self.precedent = None

class liste:
    def __init__(self):
        self.tete = None
        self.queue = None
        self.nb_elem = 0
    
    def ajouter(self,valeur):
        cell = cellule(valeur)
        if self.queue != None:
            self.queue.suivant = cell
            cell.precedent = self.queue
        self.queue = cell
        self.nb_elem += 1
        if self.tete == None:
            self.tete = cell

        #cell = cellule(valeur)
        #self.queue = cell
        #if self.tete == None:
        #    self.tete = cell
        #    return
        #pt_cell = self.tete
        #while pt_cell.suivant != None:
        #    pt_cell = pt_cell.suivant
        #pt_cell.suivant = cell
        #cell.precedent = pt_cell

    def inserer(self,valeur,indice):
        if self.tete == None:
            return
        cell = cellule(valeur)
        i = 0
        pt_cell = self.tete
        while  pt_cell.suivant != None and i < indice-1 :
            pt_cell = pt_cell.suivant
            i+=1
        tmp = pt_cell.suivant
        pt_cell.suivant = cell
        cell.suivant = tmp
        cell.precedent = pt_cell
        self.nb_elem +=1
        if cell.suivant == None:
            self.queue = cell
            
    def concatener(self,liste):
        self.queue.suivant = liste.tete
        self.nb_elem += liste.nb_elem
            
    def recherche(self,valeur):
        i=0
        pt_cell = self.tete
        while pt_cell != None:
            if pt_cell.valeur == valeur:
                return i
            pt_cell = pt_cell.suivant
            i+=1
        return -1


    def afficher(self):
        if self.tete == None:
            return
        pt_cell = self.tete
        while pt_cell != None:
            print(pt_cell.valeur)
            pt_cell = pt_cell.suivant



newListe = liste()
liste2 = liste()
liste2.ajouter(2)
liste2.ajouter(7)
liste2.ajouter(9)
newListe.ajouter(2)
newListe.ajouter(8)
newListe.ajouter(4)
newListe.inserer(10,2)
newListe.concatener(liste2)
print(newListe.recherche(7))
newListe.afficher()
print("nb elem:",newListe.nb_elem)
