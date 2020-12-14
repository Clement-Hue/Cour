% gvim:  fileencoding=utf8

/** <module> Puzzle 15 Problem Solved with an Informed Branch-and-Bound Inference Engine

@author José Martinez
@see [[Polytechnic School of the University of Nantes][http://web.polytech.univ-nantes.fr/]]
@license All Rights Reserved

This code cannot be reproduced, copied, transmitted, etc., without the previous explicit authorisation of the author and/or the School.
It is provided only for a pedagogical usage at Polytech Nantes.

@version 1.O

__HISTORY__

   * June 2019:  first version, cloned from Puzzle 8

__USAGE__

Type in:

==
> swipl
?- consult('puzzle15_solution.pl').
?- solve.
==

and wait...

then better try:
 
==
?- solve(20).
==
 
After that, try:

==
?- time(solve(n)).
==

with n varying between 0 and 25 and draw the graph of inferences for n.

 */

:- module(puzzle15_solution, [ solve/0
                             , solve/1 
                             ]).

:- use_module(puzzle15_problem, [ initial_state/1
                                , final_state/1
                                , operation/4
                                , hamming_heuristic/2
                                , puzzle15_pretty_solution/2
                                ]).
:- use_module(solver_informed_branch_and_bound, [ solver/6 ]).
% :- use_module(solver_informed_branch_and_bound_with_tracing, [ solver/6 ]).
:- use_module(solver_common, [ is_solution/4
                             , solution_cost/2
                             ]).

%! solve is semidet.
%
% Solves the puzzle15 puzzle then displays the solutions.
%
solve :-
   solve(100).

%! solve is semidet.
%
% Solves the puzzle 15 problem then displays one of the best solutions, if found.
%
% @arg UB  A (strict) upper bound on the cost of a solution.
%
solve(UB) :-
   initial_state(I),
   solver(final_state, operation, hamming_heuristic, I, UB, S),
   puzzle15_pretty_solution(I, S),
   writef("i.e., %t\n", [S]),
   is_solution(puzzle15_problem:final_state, puzzle15_problem:operation, I, S),
   solution_cost(S, C),
   writef("for a total cost of %t.\n", [C]).
