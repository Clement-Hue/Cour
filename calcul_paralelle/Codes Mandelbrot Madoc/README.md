[//]:#(gvim: set fileencoding=utf8)

# Contenu

Ce répertoire contient quelques programmes permettant de calculer une image représentant une partie de l'ensemble de Mandelbrot.

# Version séquentielle

Le programme séquentiel est fourni dans une version fonctionnelle.
Il suffit de le compiler avec :

   - `make seq`

pour obtenir le programme `MandelbrotSeq.exe`.

Il peut être invoqué directement,

   - `./MandelbrotSeq.exe`

sans paramètre ou avec des paramètres spécifiques (cf. Makefile).

Plusieurs exécutions sont également prévues pour générer neuf images à différents niveaux d'agrandissement.
Pour chronométrer les performances, il suffit de les lancer avec la commande `time`, soit :

   - `time make SamplesSeq`.

Après la génération des neuf images dans le répertoire "Images", le temps d'exécution cumulé s'affichera sur la console système.

On reprendra ces deux étapes après avoir activé la compilation optimisée -O3 dans le Makefile.

__Nota.__  Une version Python est fournie, démontrant à quel point un langage interprété est totalement à éviter pour des calculs intensifs !
           Pour comparaison, on pourra la lancer avec

   - `time python3 MandelbrotSeq.py > ouf.ppm`.

# Versions parallèles

Deux versions parallèles sont à développer :

   - tout d'abord avec *OpenMP*,
   - puis avec PVM (éventuellement *OpenMPI*).

Dans le second cas, on commencera par une version mono-poste qui ne nécessite quasiment aucun paramétrage et évite de pénibles nettoyages à la main sur les machines distantes en cas de "plantage".
Ce n'est que lorsque le programme sera opérationnel que l'on pourra s'intéresser à ses performances sur un réseau de machines.

__Nota.__ MPI est l'alternative actuelle à PVM.
          *OpenMPI* est censé être devenu plus rapide que PVM vers 2015-2016, la dernière version de PVM datant de 2009.
          Néanmoins, sur ce TP, du moins dans les versions développées par l'enseignant, et sur mono-poste, PVM reste encore aux alentours de deux à trois fois plus rapide !

À titre d'illustration, le tableau suivant donne les performances relevées sur un poste de travail, pour une seul exécution, ordonné par temps croissants :

| Version      | Processeur       | Nombre | Optimisation | « Dry Run » | Temps, réel (s) |
| :---         | :---             |   ---: |    :---:     |    :---:    |            ---: |
| PVM          | I7-8700 @3.20GHz | 12     | 3            | VRAI        |  2,036          |
| PVM          | --               | --     | 3            | FAUX        |  3,494          |
| OpenMP       | --               | --     | 3            | VRAI        |  3,775          |
| OpenMP       | --               | --     | 3            | FAUX        |  3,930          |
| OpenMPI      | --               | --     | 3            | VRAI        |  5,627          |
| PVM          | --               | --     | 0            | VRAI        |  6,223          |
| PVM          | --               | --     | 0            | FAUX        |  8,109          |
| OpenMPI      | --               | --     | 3            | FAUX        |  8,332          |
| OpenMPI      | --               | --     | 0            | VRAI        | 10,776          |
| OpenMP       | --               | --     | 0            | VRAI        | 11,040          |
| OpenMP       | --               | --     | 0            | FAUX        | 11,464          |
| OpenMPI      | --               | --     | 0            | FAUX        | 13,392          |
| Séquentielle | --               |  1     | 3            | VRAI        | 14,608          |
| Séquentielle | --               | --     | 3            | FAUX        | 16,539          |
| Séquentielle | --               | --     | 0            | VRAI        | 39,935          |
| Séquentielle | --               | --     | 0            | FAUX        | 43,410          |

où "dry run" correspond au fait que les images générées sont ou ne sont pas enregistrées sur le disque, ce qui élimine une partie séquentielle finale un peu lente.

