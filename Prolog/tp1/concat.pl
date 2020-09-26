concat([],L,L).
concat([X|L1], Y, [X|Z]) :- concat(L1,Y,Z).
