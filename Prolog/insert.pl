insert(X, [], [W]).
insert(X, [A|B], [X,A|B]).
insert(X,[A|B], [A|R]) :- insert(X,B,R).
