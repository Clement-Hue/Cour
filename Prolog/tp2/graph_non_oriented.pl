route1(nantes,rennes,110).
route1(nantes,vannes,120).
route1(nantes,saint_nazaire,60).
route1(nantes,bordeaux,340).
route1(nantes,angers,90).
route1(rennes,brest,250).
route1(rennes,angers,130).
route1(rennes,saint_malo,70).
route1(rennes,mont_saint_michel,70).
route1(rennes,tours,240).
route1(angers,tours,130).
route1(vannes,brest,190).
route1(brest,saint_malo,230).
route1(saint_malo,mont_saint_michel,60).
route1(bordeaux,tours,350).
route1(mont_saint_michel,caen,200).
route1(mont_saint_michel,cherbourg,180).
route1(caen,cherbourg,120).
route1(rennes,saint_brieuc,100).
route1(saint_brieuc,brest,150).
route1(saint_brieuc,vannes,120).

route(X,Y,D) :- route1(X,Y,D).
route(X,Y,D) :- route1(Y,X,D).
itineraire(N,N,0,_, []). /* depart, destination, distance, ville visité, résultat */
itineraire(X,Y,D, ET, [VI|ET2]) :- route(X,VI,D1), \+member(VI,ET), itineraire(VI, Y, D2, [VI,ET], ET2), D is D1 + D2.
chemin(X,Y,D, [X|L]) :- itineraire(X,Y,D, [X], L).
