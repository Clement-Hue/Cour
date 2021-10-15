# Application parallèle en PVM avec une ferme de travailleurs

## Exécution

Comme dans le cas des "ping", compilez deux programmes, `sum_farmer.exe` et `sum_worker.exe`, avec

   - `make sum`.

Après avoir initialisé la machine virtuelle ("pvm", "quit"), il ne reste plus qu'à lancer le programme principal :

   - `./sum_farmer.exe`

pour lancer une réduction parallèle additive (une somme) avec le nombre de travailleurs indiqué dans le fichier partagé des constantes (cf. `sum_constants.h`).

À la fin de la session de travail, pensez à arrêter la machine virtuelle, surtout en version multi-poste, pour supprimer tous les démons et fichiers de travail ("pvm", "halt").

## Modèle

Le principal intérêt de ce code est de fournir un modèle de codage, un squelette de programmation parallèle, pour toute application qui peut se ramener, totalement ou en partie, à une application parallèle.
On notera tout particulièrement l'isolation de la gestion des messages dans un fichier dédié (cf. `sum_messages.h`).
Cela permet d'assurer la maintenance conjointe de l'envoi et de la réception d'un même type de message.

__Nota.__  Dans ce modèle, la répartition de charge est _statique_.

__Nota.__  Il serait possible d'tiliser les primitives de groupe, `scatter` et `gather` afin d'obtenir une version SPMD.

__Subsidiaire.__  Expliquez pourquoi la parallélisation de l'exemple est totalement... stupide !

