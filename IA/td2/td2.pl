word(_, 0, []).
word(AS, N, [A | W]) :-
    N > 0,
    member(A, AS),
    N_minus_1 is N - 1,
    word(AS, N_minus_1, W).
