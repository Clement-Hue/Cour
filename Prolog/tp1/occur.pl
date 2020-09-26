occur(X,[X|T]).
occur(X,[H|T]) :- occur(X,T).
