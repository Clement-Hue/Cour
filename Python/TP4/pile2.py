class PILE:
    def __init__(self):
        self.tab = []

    def empiler(self,valeur):
        self.tab.append(valeur)

    def depiler(self):
        print(self.tab[len(self.tab)-1])
        self.tab.pop()

pile = PILE()
pile.empiler(5)
pile.empiler(7)
pile.empiler(8)
pile.empiler(3)
pile.depiler()




