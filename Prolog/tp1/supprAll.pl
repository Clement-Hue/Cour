supprall(_, [], []).
supprall(X, [X|Y], Z) :- supprall(X,Y,Z).
supprall(X, [T|Y], [T|Z]) :- T \= X, supprall(X,Y,Z).
