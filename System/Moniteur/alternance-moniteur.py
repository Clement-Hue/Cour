import multiprocessing
import threading
import time
import random
tprint = print
# A décommenter pour synchroniser l'affichage tprint()
from tprint import tprint

#
# Implémentation d'une alternance "ping pong" avec les moniteurs python (Lock et Condition)
#


#
# Définition du Moniteur Ping Pong
#

class Moniteur_PingPong():
    def __init__(self):
        self.chaine_ping_pong=""
        self.tour= ['ping','pong']
        self.lock = threading.Lock()
        self.fifo = threading.Condition(self.lock)

# point d'entrée du moniteur :
def moniteur_ping_pong(moniteur, nom, i):
    moniteur.lock.acquire()
    tprint("{nom} débute".format(nom=nom))
    # a compléter: EM
    while nom not in moniteur.tour: 
        moniteur.fifo.wait()

    # a compléter : attendre (=wait) jusqu'à son tour (si nom != moniteur.tour ....)

    time.sleep(random.randint(0, 3))
    moniteur.chaine_ping_pong = moniteur.chaine_ping_pong + nom.upper() + '-'
    tprint( '{nom} : \t (i={i}) chaine_ping_pong={chaine_ping_pong}'.format(nom=nom, i=i, chaine_ping_pong=moniteur.chaine_ping_pong) )
    if moniteur.chaine_ping_pong.endswith("PING-PING-") or moniteur.chaine_ping_pong.endswith("PING-PING-") :
        tprint( '{nom} : \t ERREUR !'.format(nom=nom) )

    if nom == "ping" :
        moniteur.tour = "pong"
    else:
        moniteur.tour = "ping"
        
    moniteur.fifo.notify()
    # a compléter : réveiller (=signal) le processus dont s'est le tour si endormi 
    
    tprint("{nom} termine".format(nom=nom))
    # a compléter: EM
    moniteur.lock.release()


# fin de definition du moniteur





#
# test alternance Ping Pong
#
def alternance():
    # liste des noms de threads à créer
    NomsThreads = ["PONG","PING"]
    # puis essayez avec:
    # NomsThreads = ["PONG","PING","PING","PONG","PING","PONG","PONG","PING"]
    threads = []

    # boucle de répétition de chaque thread
    NbCoups = 10

    # ressources critiques dans le moniteur
    moniteur = Moniteur_PingPong()
    



    # Threads de type Ping (resp. Pong)
    def thread_ping_pong(nom) :
        global chaine_ping_pong
        tprint( '{nom} : Debut du thread nom={nom}'.format(nom=nom))

        for i in range(NbCoups):
            time.sleep(random.randint(0, 3))
            moniteur_ping_pong(moniteur, nom.lower(), i)

        tprint( '{nom} : Fin du thread'.format(nom=nom))



      
    # Création des Thread
    for nom in NomsThreads:
        threads.append(threading.Thread(target=thread_ping_pong, args=(nom,)))
    # ou
    # threads = [threading.Thread(target=thread_ping_pong, args=(nom,)) for nom in NomsThreads]

    tprint('Debut du test avec {nom}'.format(nom=NomsThreads))

    # Démarrage des threads
    for t in threads:
        t.start()

    # Attente de terminaison des threads
    for t in threads:
        t.join()

    tprint('Fin du test')


if __name__ == "__main__" :
    alternance()
