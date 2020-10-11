init(noeud(noeud(noeud(nil,2,nil),3,noeud(nil,4,nil)),5,noeud(noeud(nil,7,nil),8,noeud(nil,10,nil)))).

parcour(nil).
parcour(noeud(G,X,D)) :- parcour(G), write(X),nl, parcour(D).
nb_noeud(nil,0).
nb_noeud(noeud(G,_,D), R) :-  nb_noeud(G,RG), nb_noeud(D,RD), R is RG + RD +1.
present(noeud(_,X,_),X).
present(noeud(G,V,_),X) :- X < V, present(G,X).
present(noeud(_,V,D),X) :- X > V, present(D,X).
plus_grand(noeud(_,X,nil), X).
plus_grand(noeud(_,_,D), R) :- plus_grand(D,R).

test :- init(A), parcour(A).
test_nb(R) :- init(A), nb_noeud(A,R).
test_present(X) :- init(A), present(A,X).
test_grand(R) :- init(A), plus_grand(A,R).
