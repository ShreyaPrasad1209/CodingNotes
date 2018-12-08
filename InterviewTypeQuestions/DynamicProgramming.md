# Dynamic Programming
## 1. Painter's Partition Problem - Codenation, Google
You have to paint N boards of length {A0, A1, A2 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint continuous sections of board, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

```c++
int dp[1000][1000]{};
int partition(int A[], int n, int k)
{
    if (k == 1) return accumulate(A, A+n, 0);
    if (n == 1) return A[0];
    
    int best = INT_MAX;
    for (int j = 1; j <= n; j++)
    {
        if (!dp[j][k-1]) dp[j][k-1] = partition(A, j, k-1);
        best = min(best, max(dp[j][k-1], accumulate(A+j, A+n, 0)));
    }
    return best;
}
```

Above implementation is brute force with memoization, we can optimize it using binary search

```
example - [1, 2, 3, 4, 5, 6, 7, 8, 9]

 9-------45
low     high
low is when there are n painters. high is when there is 1 painter
find mid = 27
find what mid corresponds to
1+2+3+4+5+6 and 7+8+9 this way array partitions such that parts sum is less then mid. (2 parts)

 6------2------1
low    mid   high
apply binary search on low and mid
```
```c++
int getRequiredPainters(int A[], int n, int maxLengthPerPainter)
{
    int total = 0, numPainters = 1;
    for (int i = 0; i < n; i++)
    {
        total += A[i];
        if (total > maxLengthPerPainter)
        {
            total = A[i];
            numPainters++;
        }
    }
    return numPainters;
}

int partition(int A[], int n, int k)
{
    int lo = *max_element(A, A+n);
    int hi = accumulate(A, A+n, 0);
    while (lo < hi)
    {
        int mid = lo + (hi-lo)/2;
        int requiredPainters = getRequiredPainters(A, n, mid);
        if (requiredPainters <= k) hi = mid;
        else lo = mid+1;
    }
    return lo;
}
//O(NlogN)
```
Same type problem Allocate Books - Google (https://www.youtube.com/watch?v=Ss9ta1zmiZo)

## 2. Knapsack Problem
Given a knapsack (bag) with max m weights capacity and n objects with given profit and weights. We want to maximize profit
```
n = 7, m = 15
objects     1   2   3   4   5   6   7
profit      10  5   15  7   6   18  3
weight      2   3   5   7   1   4   1
We need to select maximum elements(m) from the objects so that we get max profit.

In fractional Knapsack  [GREEDY]
Profit/Weight: [5, 1.6, 3, 1, 6, 4.5, 3]
Keep choosing high values: obj5, obj1, obj6, obj7, obj2, 2/3 * obj2

In 0/1 Knapsack
https://www.youtube.com/watch?v=nLmhmB6NzcM&t=197s
```