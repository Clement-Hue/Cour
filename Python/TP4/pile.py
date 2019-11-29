class cellule:
    def __init__(self,valeur):
        self.valeur = valeur
        self.suivant = None
        self.precedent = None

class Pile:
    def __init__(self):
        self.tete  = None
        self.queue = None

    def empiler(self,valeur):
        cell = cellule(valeur)
        if self.queue != None:
            self.queue.suivant = cell
            cell.precedent = self.queue
        self.queue = cell
        if self.tete == None:
            self.tete = cell

    def depiler(self):
        res = self.queue.valeur
        self.queue = self.queue.precedent
        return res

    def afficher(self):
        pt_cell = self.queue
        while pt_cell !=None:
            print(pt_cell.valeur)
            pt_cell = pt_cell.precedent


def expression_prefixe(chaine):
    pile = Pile()
    for i in range(len(chaine)-1,-1,-1):
        if chaine[i] == ' ':
            i = 1
            continue
        elif chaine[i] == '-':
            pile.empiler(pile.depiler() - pile.depiler())
        elif chaine[i] == '+':
            pile.empiler(pile.depiler() + pile.depiler())
        elif chaine[i] == '/':
            pile.empiler(pile.depiler() / pile.depiler())
        elif chaine[i] == '*':
            pile.empiler(pile.depiler() *  pile.depiler())
        else:
            #if i == 0:
            #    chiffre = (ord(chaine[i]) - ord('0')) * 10
            #    chiffre += pile.depiler()
            #    pile.empiler(chiffre)
            #    continue
            chiffre = ord(chaine[i]) - ord('0')
            pile.empiler(chiffre)
            i = 0

    pile.afficher()



pile = Pile()
pile.empiler(2)
pile.empiler(5)
pile.empiler(1)
pile.depiler()
#expression_prefixe("+ - 4 * 3 2 / 5 2")
expression_prefixe("+ * 3 2 + 9 3")






