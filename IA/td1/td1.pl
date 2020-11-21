turn_match(up, down).
turn_match(down, up).
initial_state(state([down, down, up, up, down, up, up, up, down, down, down, up])).
final_state(state(MS)) :- forall( member(M, MS), M = up ).
operation(rule1(L), state(MS), state(NS), 3) :- 
  append(BS, [M, M, M | AS], MS),
  length(BS, L),
  turn_match(M, N),
  append(BS, [N, N, N | AS], NS).
operation(rule2(L), state(MS), state(NS), 2) :- 
  append(BS, [M1, M2 | AS], MS), 
  M1 \= M2,
  length(BS, L),
  append(BS, [M2, M1 | AS], NS).
