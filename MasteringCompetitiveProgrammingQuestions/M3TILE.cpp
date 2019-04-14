/*
Let T(n) denote the number of ways you can fill a 3xn matrix.
Assume that we have filled the 3xn matrix with 2x1 dominos. How would the final solution look like? Think about the dominos in the last two colums.

Case - 1:
....x x x x t1-t1     ....x x x x t1-t1     ....x x x x t1 t2
....x x x x t2-t2     ....x x x x t2 t3     ....x x x x t1 t2
....x x x x t3-t3     ....x x x x t2 t3     ....x x x x t3-t3

 t1-t1, t2-t2, t3-t3 denote 3 different 2x1 dominos.

In all the above the cases you just need to find T(n-2) to find the number of ways of filling the final matrix.

Case - 2:

....x x x  x t1-t1     ....x x x t4 t4 t1
....x x x t4 t4 t2     ....x x x t3 t3 t1
....x x x t3 t3-t2     ....x x x  x t2 t2

This looks a bit different. there is a gap in the 3 column from right. What to do?
Okay, let's define a new function F(m) which denotes the number of ways of filling a [(3xm) matrix and an extra element at the top after the last column]
We can always flip F(m) to get a solution for the number of ways of filling a [(3xm) matrix and an extra element at the bottom after the last column]
It is easy to see that F(n) = T(n-1) + F(n-2) because to get to our so called extra element at the end form there are only two possible ways at the last two columns     
     x x x x t2-t2     x x x x  t2-t2
     x x x x t1         x x x t1 t1
     x x x x t1         x x x t3 t3
       T(n-1)                F(n-2)

So putting it all together:

T(n) = 3*T(n-2)+ 2*F(n-3)
F(n) = T(n-1) + F(n-2)

with base cases:

T(0) = 1;
F(0) = 0;
T(x)= 0 & F(x) = 0 if (x<0)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, T[31], F[31];
	T[0] = 1; F[0] = 0;
	for (int i = 1; i <= 30; ++i)
    {
		T[i] = ((i >= 2) ? 3*T[i-2] : 0) + ((i >= 3) ? 2*F[i-3] : 0);
		F[i] = T[i-1] + ((i >= 2) ? F[i-2] : 0);
	}
	while(true)
    {
		scanf("%d", &n);
		if(n == -1) break;
		printf("%d\n", T[n]);
	}
	return 0;
}