% :- use_module(solver_naive, [ solver/4 ]).
% :- use_module(solver_directed_cycle_detection, [ solver/4 ]).
:- use_module(solver_memoing, [ solver/4 ]).
%:- use_module(solver_uninformed_branch_and_bound, [ solver/5 ]).
:- use_module(solver_iterated_deepening, [ solver/5 ]).
%:- use_module(solver_depth_limit, [ solver/5 ]).

:- use_module(solver_common, [ is_solution/4
                             , solution_cost/2
                             ]).


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

solve5(S) :-
   initial_state(I),
   solver(final_state, operation, I, S, 5),
  % writef("i.e., %t\n", [S]),
  %  is_solution(final_state, operation, I, S),
   solution_cost(S, C),
   writef("for a total cost of %t.\n", [C]).

solve(S) :-
   initial_state(I),
   solver(final_state, operation, I, S),
  %writef("i.e., %t\n", [S]),
   %is_solution(final_state, operation, I, S),
   solution_cost(S, C),
   writef("for a total cost of %t.\n", [C]).

