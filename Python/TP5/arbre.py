class Noeud:
    def __init__(self,valeur,n1,n2):
        self.valeur = valeur
        self.gauche = n1
        self.droite = n2


class Arbre:
    def __init__(self):
        self.root = None

    def node(f,x,n1,n2):
        noeud = Noeud(x,n1,n2)
        return noeud

    def depth(self):
        return self._depth(self.root)

    def _depth(self,node):
        if (node==None) :
            return(0)
        return(max(self._depth(node.gauche),self._depth(node.droite))+1)

    def term(self):
        return None
    
    def nb_noeud(self):
        return self._nb_noeud(self.root)

    def _nb_noeud(self,node):
        if node == None:
            return 0
        return 1 + self._nb_noeud(node.gauche) + self._nb_noeud(node.droite)

    def sum(self):
        return self._sum(self.root)


    def _sum(self,node):
        if node == None:
            return 0
        return node.valeur + self._sum(node.gauche) + self._sum(node.droite)

    def inc(self):
        self._inc(self.root)

    def _inc(self,node):
        if node == None:
            return
        node.valeur += 1
        self._inc(node.gauche)
        self._inc(node.droite)

    def tree(self,n):
        self.root = n

    def empty(self):
        if self.racine != None:
            return False
        return True

    def root(self):
        return self.racine

    def parcour(self):
        self._parcour(self.root)

    def _parcour(self,node):
        if node == None:
            return
        self._parcour(node.gauche)
        print(node.valeur)
        self._parcour(node.droite)

    def hierarchy(self):
        if self.root == None:
            return False
        return self._hierarchy(self.root,self.root.valeur)

    def _hierarchy(self,node,valeur):
        if node.valeur > valeur:
            return False
        valeur = node.valeur
        if node.gauche != None:
            i = self._hierarchy(node.gauche,valeur)
        else:
            i = True
        if node.droite != None:
            k = self._hierarchy(node.droite,valeur)
        else:
            k = True
        return i and k





g = Arbre()
d = Arbre()
a = Arbre()
g.tree ( g.node (1  , g.node (0  , g.term () ,  g.term () ) ,  g.term () ) )
d.tree ( d.node (4  , d.node (3  , d.term () ,  d.term () ) ,  d.node (5 ,  d.term ()  , d.term () ) ) )
a.tree ( a.node (2  ,  g.root, d.root))
print("somme des noeuds",d.sum())
d.inc()
g.parcour()
print(g.hierarchy())
