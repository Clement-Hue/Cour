class tableau:
    def __init__(self,tab):
        self.tab = tab

    def inserer(self,indice,valeur):
        tab.append(tab[len(tab) - 1])
        for i in range(len(tab)-1,indice,-1):
            tab[i] = tab[i-1] 
        tab[indice] = valeur
        return tab

    def concatener(self,tab2):
        for i in range(len(tab2)):
            tab.append(tab2[i])

    def recherche(self,valeur):
        for i in range(len(tab)):
            if tab[i] == valeur:
                return i
        return -1


tab = [5,1,8,7,9,5,0]
monTab = tableau(tab)
monTab.inserer(4,10)
print(monTab.tab)
monTab.concatener([11,12,13,15])
print(monTab.tab)
print(monTab.recherche(11))
