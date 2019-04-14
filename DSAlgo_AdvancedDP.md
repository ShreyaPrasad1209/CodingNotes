# Advanced Dynamic Programming

So what is exactly the dynamic programming, how can we describe it? There’s no clear definition for this technique. It can be rather characterized as an algorithmic technique that is usually based on a starting state of the problem, and a recurrent formula or relation between the successive states. A state of the problem usually represents a sub-solution, i.e. a partial solution or a solution based on a subset of the given input. And the states are built one by one, based on the previously built states.

For simple problems this relation is quite easy to be observed, but for complex problems we may need to do some additional operations or changes to reach such a relation.

Most of DP problems can be divided into two types: optimization problems and combinatoric problems. The optimization problems require you to choose some feasible solution so that the value of goal function is minimized (or maximized). Combinatoric problems request the number of ways to do something or the probability of some event.

The goal of combinatoric DP problem is to find number of ways to do something or the probability that the event happens. Often the number of ways can be big and only the reminder modulo some small number is required. Example: count the number of ways to choose coins so that their overall weight is equal to S.
```
Recurrent equations for DP:
  {k[0] = 1;
  {k[P] = sum_i (k[P-Wi]);   (for Wi <= P)

Consider the input data: S=11, n=3, W = {1,3,5}
  P = 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11
  ------+--+--+--+--+--+--+--+--+--+--+--
  k = 1 |1 |1 |2 |3 |5 |8 |12|19|30|47|74
```