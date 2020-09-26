dpp(0,1).
dpp(P,R) :- P>0, P1 is P-1, dpp(P1,R1), R is 2*R1.
