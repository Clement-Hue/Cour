s(N,1,1).
s(K,K,1).
s(N,K,R) :- K<N, N>=1 ,N1 is N-1, K1 is K-1, s(N1, K1, R1),s(N1,K,R2), R is R1 + K*R2.
