import random

CARTE_VALUE = {"as": 1,"roi" : 10,"dame": 10,"valet": 10,"10" : 10,"9": 9,"8" : 8,"7" :7,"6" : 6,"5" : 5,"4":4,"3":3,"2": 2}
COULEUR = ["pic","trefle","coeur","carreau"]
CARTE = [(i, v) for v in COULEUR for i in [*CARTE_VALUE] ]

class Joueur:
    def __init__(self):
        self.carte = random.choices(CARTE,k=7 )
        self.carte_value = [carte[0] for carte in self.carte]
        print(self.carte_value)
        print(self.paire())
        print(self.brelan())

    def paire(self):
        return self._combinaison(2)

    def brelan(self):
        return self._combinaison(3)

    def carre(self):
        return self._combinaison(4)

    def _combinaison(self, nb_same_value):
        for carte in self.carte_value:
            if self.carte_value.count(carte) >= nb_same_value:
                return True
        return False
            