supprFirst(_,[],[]).
supprFirst(X,[X|L], L).
supprFirst(X, [T,L], [T,R]) :- T \= x ,supprFirst(X, L, R).

