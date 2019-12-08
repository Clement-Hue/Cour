
#
#   Simulation d'une usine d'assemblage d'aeroplanes
#


#   L'usine est composée d'un ensemble de chaines séquentielles de montages
#   qui sont autonomes et fonctionnent en parallèle:
#   - 1 chaine de production de carlingues
#   - 1 chaine de production d'ailes
#   - 1 chaine de production de roues
#   - 1 chaine de production de moteurs
#   - 1 chaine d'assemblage 1 x carlingue + 2 x ailes
#   - 1 chaine d'assemblage 1 x 1xcarlingue+2xailes + 3 x roues
#   - 1 chaine d'assemblage de l'aeroplane complet : 1xcarlingue+2xailes+3xroues+2xmoteurs
#


#   Proposez une synchronisation des chaines de montage à l'aide de Moniteurs


import multiprocessing
import threading
import time
import random
tprint = print
from tprint import tprint

# Définition du Moniteur UsineAeroplane

class MoniteurUsineAeroplane :
    def __init__(self):
        self.chaines = ["aile", "roue", "carlingue", "moteur", "carlingue1Ailes2", "carlingue1Ailes2Roues3", "aeroplane"]
        self.nbProduction=dict( {chaine:0 for chaine in self.chaines})
        self.mutex=threading.Lock()
        self.attente=dict( {chaine:threading.Condition(self.mutex) for chaine in self.chaines})
        self.nbAttente=dict( {chaine:0 for chaine in self.chaines})

def etat_usine ( usine ):
    usine.mutex.acquire()
    res = ""
    for chaine in usine.chaines :
        #res += chaine + "(" , usine.nbProduction[chaine] , " elt, " , usine.nbAttente[chaine] , " att ), "
        pass
    usine.mutex.release()
    return res


def moniteurUsineApresCarlingue(usine):
    tprint("moniteurUsineApresCarlingue demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["carlingue"] += 1
    if usine.nbProduction["carlingue"] >= 1 and usine.nbProduction["aile"] >= 2 and usine.nbAttente["carlingue1Ailes2"] > 0 :
        tprint("nbProduction[carlingue]={} et nbProduction[aile]={} et nbAttente[carlingue1Ailes2]={} => attente[carlingue1Ailes2].notify()".format(usine.nbProduction["carlingue"], usine.nbProduction["aile"], usine.nbAttente["carlingue1Ailes2"]))
        usine.attente["carlingue1Ailes2"].notify()
    # fin d'E.M. 
    tprint("moniteurUsineApresCarlingue V(mutex)...")
    usine.mutex.release()
    
def moniteurUsineApresAile(usine):
    tprint("moniteurUsineApresAile demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["aile"] += 1
    if usine.nbProduction["carlingue"] >= 1 and usine.nbProduction["aile"] >= 2 and usine.nbAttente["carlingue1Ailes2"] > 0 :
        tprint("nbProduction[carlingue]={} et nbProduction[aile]={} et nbAttente[carlingue1Ailes2]={} => attente[carlingue1Ailes2].notify()".format(usine.nbProduction["carlingue"], usine.nbProduction["aile"], usine.nbAttente["carlingue1Ailes2"]))
        usine.attente["carlingue1Ailes2"].notify()
    # fin d'E.M. 
    tprint("moniteurUsineApresAile V(mutex)...")
    usine.mutex.release()
    
def moniteurUsineApresRoue(usine):
    tprint("moniteurUsineApresRoue demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["roue"] += 1
    if usine.nbProduction["carlingue1Ailes2"] >= 1 and usine.nbProduction["roue"] >= 3 and usine.nbAttente["carlingue1Ailes2Roues3"] > 0 :
        tprint("nbProduction[carlingue1Ailes2]={} et nbProduction[roue]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[carlingue1Ailes2Roues3].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["roue"], usine.nbAttente["carlingue1Ailes2Roues3"]))
        usine.attente["carlingue1Ailes2Roues3"].notify()
    # fin d'E.M. 
    tprint("moniteurUsineApresRoue V(mutex)...")
    usine.mutex.release()

def moniteurUsineApresMoteur(usine):
    tprint("moniteurUsineApresMoteur demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["moteur"] += 1
    if usine.nbProduction["carlingue1Ailes2Roues3"] >= 1 and usine.nbProduction["moteur"] >= 2 and usine.nbAttente["aeroplane"] > 0 :
        tprint("nbProduction[carlingue1Ailes2]={} et nbProduction[moteur]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[aeroplane].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["moteur"], usine.nbAttente["aeroplane"]))
        usine.attente["aeroplane"].notify()
    # fin d'E.M. 
    tprint("moniteurUsineApresMoteur V(mutex)...")
    usine.mutex.release()



def moniteurUsineAvantcarlingue1Ailes2(usine):
    tprint("moniteurUsineAvantcarlingue1Ailes2 demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    if usine.nbProduction["carlingue"] < 1 or usine.nbProduction["aile"] < 2 or usine.nbAttente["carlingue1Ailes2"] > 0 :
        tprint("Attente condition nbProduction[carlingue]={} ou nbProduction[aile]={} ou nbAttente[carlingue1Ailes2]={} => attente[carlingue1Ailes2].wait()".format(usine.nbProduction["carlingue"], usine.nbProduction["aile"], usine.nbAttente["carlingue1Ailes2"]))
        usine.nbAttente["carlingue1Ailes2"] += 1
        usine.attente["carlingue1Ailes2"].wait()
        usine.nbAttente["carlingue1Ailes2"] -= 1
        tprint("Obtient condition nbProduction[carlingue]={} ou nbProduction[aile]={} ou nbAttente[carlingue1Ailes2]={} => attente[carlingue1Ailes2].wait()".format(usine.nbProduction["carlingue"], usine.nbProduction["aile"], usine.nbAttente["carlingue1Ailes2"]))
    usine.nbProduction["carlingue"] -= 1
    usine.nbProduction["aile"] -= 2
    # fin d'E.M. 
    tprint("moniteurUsineAvantcarlingue1Ailes2 V(mutex)...")
    usine.mutex.release()
    
    
def moniteurUsineAprescarlingue1Ailes2(usine):
    tprint("moniteurUsineAprescarlingue1Ailes2 demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["carlingue1Ailes2"] += 1
    if usine.nbProduction["carlingue1Ailes2"] >= 1 and usine.nbProduction["roue"] >= 3 and usine.nbAttente["carlingue1Ailes2Roues3"] > 0 :
        tprint("nbProduction[carlingue1Ailes2]={} et nbProduction[roue]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[carlingue1Ailes2Roues3].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["roue"], usine.nbAttente["carlingue1Ailes2Roues3"]))
        usine.attente["carlingue1Ailes2Roues3"].notify()
    # fin d'E.M. 
    tprint("moniteurUsineAprescarlingue1Ailes2 V(mutex)...")
    usine.mutex.release()



def moniteurUsineAvantcarlingue1Ailes2Roues3(usine):
    tprint("moniteurUsineAvantcarlingue1Ailes2Roues3 demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    if usine.nbProduction["carlingue1Ailes2"] < 1 or usine.nbProduction["roue"] < 3 or usine.nbAttente["carlingue1Ailes2Roues3"] > 0 :
        tprint("Attente condition nbProduction[carlingue1Ailes2]={} et nbProduction[roue]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[carlingue1Ailes2Roues3].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["roue"], usine.nbAttente["carlingue1Ailes2Roues3"]))
        usine.nbAttente["carlingue1Ailes2Roues3"] += 1
        usine.attente["carlingue1Ailes2Roues3"].wait()
        usine.nbAttente["carlingue1Ailes2Roues3"] -= 1
        tprint("Obtient condition nbProduction[carlingue1Ailes2]={} et nbProduction[roue]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[carlingue1Ailes2Roues3].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["roue"], usine.nbAttente["carlingue1Ailes2Roues3"]))
    usine.nbProduction["carlingue1Ailes2"] -= 1
    usine.nbProduction["roue"] -= 3
    # fin d'E.M. 
    tprint("moniteurUsineAvantcarlingue1Ailes2Roues3 V(mutex)...")
    usine.mutex.release()
    
    
def moniteurUsineAprescarlingue1Ailes2Roues3(usine):
    tprint("moniteurUsineAprescarlingue1Ailes2Roues3 demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["carlingue1Ailes2Roues3"] += 1
    if usine.nbProduction["carlingue1Ailes2Roues3"] >= 1 and usine.nbProduction["moteur"] >= 2 and usine.nbAttente["aeroplane"] > 0 :
        tprint("Attente nbProduction[carlingue1Ailes2]={} et nbProduction[moteur]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[aeroplane].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["moteur"], usine.nbAttente["aeroplane"]))
        usine.attente["aeroplane"].notify()
    # fin d'E.M. 
    tprint("moniteurUsineAprescarlingue1Ailes2Roues3 V(mutex)...")
    usine.mutex.release()

def moniteurUsineAvantAeroplane(usine):
    tprint("moniteurUsineAvantAeroplane demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["moteur"] += 1
    if usine.nbProduction["carlingue1Ailes2Roues3"] < 1 or usine.nbProduction["moteur"] < 2 or usine.nbAttente["aeroplane"] > 0  :
        tprint("Attente condition nbProduction[carlingue1Ailes2]={} et nbProduction[moteur]={} et nbAttente[carlingue1Ailes2Roues3]={} => attente[aeroplane].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["moteur"], usine.nbAttente["aeroplane"]))
        usine.nbAttente["aeroplane"] += 1
        usine.attente["aeroplane"].wait()
        usine.nbAttente["aeroplane"] -= 1
        tprint("Obtient condition nbProduction[carlingue1Ailes2]={} et nbProduction[moteur]={} et nbAttente[carlingue1Ailes2Roues3]={} <= attente[aeroplane].notify()".format(usine.nbProduction["carlingue1Ailes2"], usine.nbProduction["moteur"], usine.nbAttente["aeroplane"]))
    usine.nbProduction["carlingue1Ailes2Roues3"] -= 1
    usine.nbProduction["moteur"] -= 2

    # fin d'E.M. 
    tprint("moniteurUsineAvantAeroplane V(mutex)...")
    usine.mutex.release()

def moniteurUsineApresAeroplane(usine):
    tprint("moniteurUsineApresAeroplane demande P(mutex)...")
    usine.mutex.acquire()
    # code en E.M. sur mutex
    usine.nbProduction["aeroplane"] += 1
    # fin d'E.M. 
    tprint("moniteurUsineApresAeroplane V(mutex)...")
    usine.mutex.release()


# fin du moniteur

nbAeroplanesPrevus=5
usine = MoniteurUsineAeroplane()

def carlingue():
    for i in range(nbAeroplanesPrevus):
        time.sleep(random.randint(0, 3))
        tprint( '   Une carlingue est achevée ({})'.format(i+1))
        moniteurUsineApresCarlingue(usine)

def aile() :
    for i in range(nbAeroplanesPrevus*2):
        time.sleep(random.randint(0, 2))
        tprint( '   Une Aile est achevée ({})'.format(i+1))
        moniteurUsineApresAile(usine)

def roue():
    for i in range(nbAeroplanesPrevus*3):
        time.sleep(random.randint(0, 2))
        tprint( '   Une roue est achevée ({})'.format(i+1))
        moniteurUsineApresRoue(usine)
        
def moteur():
    for i in range(nbAeroplanesPrevus*2):
        time.sleep(random.randint(0, 1))
        tprint( '   Un moteur est achevé ({})'.format(i+1))
        moniteurUsineApresMoteur(usine)
        


def carlingue1Ailes2():
    for i in range(nbAeroplanesPrevus):
        moniteurUsineAvantcarlingue1Ailes2(usine)
        time.sleep(random.randint(0, 3))
        tprint( '   Un assemblage 1 carlingue avec 2 ailes est achevé ({})'.format(i+1))
        moniteurUsineAprescarlingue1Ailes2(usine)


def carlingue1Ailes2Roues3():
    for i in range(nbAeroplanesPrevus):
        moniteurUsineAvantcarlingue1Ailes2Roues3(usine)
        time.sleep(random.randint(0, 3))
        tprint( '   Un assemblage 1 carlingue et 2 ailes avec 3 roue est achevé ({})'.format(i+1))
        moniteurUsineAprescarlingue1Ailes2Roues3(usine)


def aeroplane():
    for i in range(nbAeroplanesPrevus):
        moniteurUsineAvantAeroplane(usine)
        time.sleep(random.randint(0, 3))
        tprint( '   Un aeroplane est achevé ({})'.format(i+1))
        moniteurUsineApresAeroplane(usine)

#
#  Test de l'usine d'assemblage d'aeroplane
#

tprint('Demarrage de l\'usine')

# Création des Thread de chaine de production
threads=dict()
for chaine in [carlingue, aile, moteur, roue, carlingue1Ailes2, carlingue1Ailes2Roues3, aeroplane ]:
    print(chaine.__name__)
    threads[chaine]=threading.Thread(target=chaine)

# Démarrage des threads
for t in threads.values() :
    t.start()

# Attente de terminaison des threads
for t in threads.values() :
    t.join()

tprint( 'Etat usine : ' + etat_usine ( usine ) )
tprint('Arret de l\'usine')


