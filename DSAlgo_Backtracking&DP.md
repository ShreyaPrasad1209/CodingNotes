# DS Algorithms - Backtracking & Dynamic Programming
## 1. Backtracking:
It is a form of recurssion.<br>
It is a general algorithm for finding all solutions to some comutational problems<br>
Backtracking is often faster than brute force enumeration of all complete candidates because it eliminates candidates if it's not completed to a valid solution.<br>
Candidates can be represented in tree where leaf(s) are eliminatede candidates. Backtracking is like DFS traversal of that tree.<br>
<br>![](res/backtrack.png)<br>
So considering we chose A solution then C and we analyze it's bad so we backtrack to node A see another solution.

1) **N Queens Problem:**<br>
We're given a chess board of N X N size and we need to place N queens on it such that no queen can attack each other.
<br>![](res/nqueen.png)<br>
```c++
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int* solution, int count)
{
    if (count == 0)
        return true;
    
    for (int i = 0; i < count; ++i)
    {
        //x = count
        //y = solution[count]
        //x' = i
        //y' = solution[i]
        if ((solution[i] == solution[count]) ||
            (solution[i] + i) == (solution[count] + count) || 
            (solution[i] - i) == (solution[count] - count))
        {
            return false;
        }
    }

    return true;
}

bool performNQueen(int n, int solution[], int count = 0)
{
    if (count == n)
    {
        for (int i = 0; i < n; ++i)
            cout << solution[i] << " ";
        return true;
    }
    
    for (int i = 0; i < n; ++i)
    {
        solution[count] = i;
        if (isSafe(solution, count))
        {
            if (performNQueen(n, solution, count + 1))
                return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    int solution[n];
    performNQueen(n, solution);

    return 0;
}
```

2) **Detecting Hamiltonian Cycles:**<br> Hamiltonian path is a path of graph in which we visit every node exactly once. Detecting it is simple. We start with a node and traverses it's child also see if it's safe to go there (It's not visited) we keep doing this until start node is reached.

3) **Colouring Problem:** We are given a graph and some colors. We need to color every node/vertex such that no two adjacent vertex have same color.<br>
One of the application is to check if the graph is Bipartite or not if it's bipartite the graph must be able to represent through 2 colors.<br>
It's a theory that any graph can be represented through 4 colors.
```c++
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> adj[], int n, int node, string solution)
{
    int size = solution.length();
    for (int i = 0; i < adj[node].size(); ++i)
    {
        int to = adj[node][i];

        if (size > to)
        {
            if (solution[to] == solution[node])
                return false;
        }
    }

    return true;
}

void coloringProblem(vector<int> adj[], int n, int c, char colors[], int node = 0, string solution = "")
{
    if (node == n)
    {
        cout << solution << endl;
        return;
    }

    for (int i = 0; i < c; ++i)
    {
        string newSolution = solution + colors[i];
        if (isSafe(adj, n, node, newSolution))
            coloringProblem(adj, n, c, colors, node + 1, newSolution);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c;
    cin >> c;
    char colors[c];
    for (int i = 0; i < c; ++i)
        cin >> colors[i];
    
    coloringProblem(adj, n, c, colors);
    
    /*
    5 7
    0 1
    1 2
    2 3
    3 4
    4 0
    4 1
    4 2
    3
    R G B
    */
    return 0;
}
```

4) **Knight's Tour Problem:**<br>
A knight (ghora) in a chess board can move in such a way that it will make to a unique non visited place everytime and can traverse whole hamilton cycle visiting every place.
```c++
#include <bits/stdc++.h>
using namespace std;

int arr[8][8];
int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

bool isSafe(int x, int y)
{   
    return (x >= 0 && y >= 0 && x < 8 && y < 8 && arr[x][y] == -1);
}

bool performKnightTour(int x, int y, int count = 1)
{
    arr[x][y] = count;

    if (count == 64)
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < 8; ++i)
    {
        int newX = x + xMove[i];
        int newY = y + yMove[i];
        if (isSafe(newX, newY))
        {
            if (!performKnightTour(newX, newY, count + 1))
                arr[newX][newY] = -1;
            else
                return true;
        }
    }

    return false;
}

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            arr[i][j] = -1;
    }
    
    performKnightTour(x, y);
    return 0;
}
```

All the above mentioned problems are NP Complete problems. NP stands for non deterministic polynomial. In all above and usually every NP problems the running time is exponential which is extremly slow so instead of finding the exact value we look for approximation.

## 2. Dynamic Programming:
Breaking complex problem it into simpler simmilar sub problems and then solving it. Also memoizing sub problems for faster re-calculation.<br>
Simplest example is calculating fibonaaci series we use F(n) = F(n-1) + F(n-2) this is breaking into simillar sub problems. We can do memoization to optimize it (optimize overlapping sub problems)

DP means - a) Memoization (Top down approach) b) Pure DP (Bottom up approach)

Recursive implementation of Fibonaaci even using memo calls stacks for recursive call 2^n times using itteration to fill a linear DP for fibonacci is O(N)

1) **Number Reduce Problem:** <br>
Given a number we can either divide it by 3, 2 or subtract 1. We need to find min operation to make 1 from n.
```c++
int solve(int n)
{
    if (n == 1) return 0;
    int q1 = INF, q2 = INF, q3 = INF;
    if (n%3 == 0) q1 = 1 + solve(n/3);
    if (n%2 == 0) q2 = 1 + solve(n/2);
    q3 = 1 + solve(n-1);
    return min(q1, min(q2, q3));
}
//We can memoize it, or do top down dp
```

2) **Staircase Problem:** <br>
We have N stairs and we can either climb by 1 step or 2 step. Find how many ways possible.
<br>![](res/staircase.png)<br>
W(n) = W(n-1) + W(n-2)
```c++
int memo[30];
int staircaseProblem(int n)
{
    if (memo[n-1] == -1) memo[n-1] = staircaseProblem(n - 1);
    if (memo[n-2] == -1) memo[n-2] = staircaseProblem(n - 2);
    
    return memo[n - 1] + memo[n - 2];
}
```

3) **On the way home:** <br>
We need to go from start to end which is bottom right most. Other way can be using backtracking but this is way more optimized then it.
<br>![](res/onthewayhome.png)<br>
```c++
int n, m;

int onTheWayHomeProblem()
{
    int ways[m][n];
    for (int i = 0; i < m; ++i) ways[i][n-1] = 1;
    for (int i = 0; i < n; ++i) ways[m-1][i] = 1;
    for (int i = m-2; i >= 0; --i)
    {
        for (int j = n-2; j >= 0; --j)
            ways[i][j] = ways[i + 1][j] + ways[i][j + 1];
    }
    return ways[0][0];
}
```
If we were given condition to move in any 4 direction then there would have been infinite possibilities.

4) We have n wines with their initial prices given. A wine sells at rate of initial price times year it is old. We can sell one wine only per year. What is max profit. We can sell only from two ends<br>
[2, 3, 5, 1, 4]. Approach is find max after selling both end wines. Using greedy and selling cheap first is wrong
```c++
//We will use 2D DP storing l & r
int dp[1000][1000];
int solve(int arr[], int l, int r, int year)
{
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int q1 = arr[l]*year + solve(arr, l+1, r, year+1);
    int q2 = arr[r]*year + solve(arr, l, r-1, year+1);
    int ans = max(q1, q2);
    dp[l][r] = ans;
    return ans;
}
//Without memoization it's complexity was O(2^n) with memoization it is O(N^2)

//Bottom up approach
int solve(int arr[], int n)
{
    int dp[1000][1000] {};
    int year = n;
    for (int i = 0; i < n; ++i) dp[i][i] = year*arr[i];
    --year;
    for (int len = 2; len <= n; ++len)
    {
        int l = 0, r = n-len;
        while (l <= r)
        {
            int temp = l+len-1;
            dp[l][temp] = max(arr[l]*year + dp[l+1][temp],
                arr[temp]*year + dp[l][temp-1]);
            ++l;
        }
        -year;
    }
    return dp[0][n-1];
}

/* For [2, 3, 5, 1, 4]
    2       3       5       1       4
2   10      23      43      45      50
3   0       15      37      40      48
5   0       0       25      29      41
1   0       0       0       5       24
4   0       0       0       0       20
*/
```

5) **Rod Cutter:** <br>
We are given a rod of some length and we can cut it in any number of pieces. We are given an array that tells us price for rod piece of that size. We need to find rod maximum selling price cuts.
```c++
#include <bits/stdc++.h>
using namespace std;

int rodCutter(int cost[], int n)
{
    int maxCost[n+1];
    fill(maxCost, maxCost + n + 1, -9999);
    maxCost[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
            maxCost[i] = max(maxCost[i], cost[j] + maxCost[i - j]);
    }

    return maxCost[n];
}

int main()
{
    int n;
    cin >> n;
    int cost[n + 1];
    for (int i = 0; i <= n; ++i) cin >> cost[i];    
    cout << rodCutter(cost, n);
    return 0;
}
```
DP relation will be: Max Cost of rod = (Cost of 1 Rod + Max cost of remaining rod) + (Cost of 2 Rod + Max cost of remaining rod) + ...

6) **Edit Distance:**
Given a string we can perform insertion, deletion, replacement to convert to another string find min operations.
```
              i-->
    ""  S   A   T   U   R   D   A   Y
""  0   1   2   3   4   5   6   7   8
S   1   0   1   2   3   4   5   6   7
U   2 
N   3
D   4
A   5
Y   6

We want to make saturday -> sunday
each cell represents min operations reqd. to convert inp. to out.

At any point this DP represents say for i=3, j=1
We want to make S from SAT this means 2 deletion. so 2 min operations.
replacement: 1 + dp[i-1][j-1]
deletion: 1 + dp[i-1][j]
insertion: 1 + dp[i][j-1]
min of all three is ans of that cell
```

7) **Find Longest Increasing subsequence:**
Whenever question says longest, maximum, highest out of subsequences then chances are more of DP
```c++
/*
[3, 10, 2, 1, 20] = [3, 10, 20] = 3
[3, 2] = [3] or [2] = 1
[50, 3, 10, 7, 40, 50] = [3, 7, 40, 50] or [3, 10, 40, 50] = 4
*/
int solve(int arr[], int n)
{
    int dp[1000];
    fill(dp, dp+n, 1);
    int ans = -1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] >= arr[j])
            {
                int curLen = 1 + dp[j];
                dp[i] = max(curLen, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

8)  **Maximum Subset Problem:**
Here the return function two operation will give entire possibilities for the recurssion.
```c++
bool isSubsetSum(ull n, ull arr[], ull sum)
{
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;
    if (arr[n - 1] > sum) return isSubsetSum(n-1, arr, sum);
    return isSubsetSum(n-1, arr, sum) || isSubsetSum(n-1, arr, sum-arr[n-1]);
}
```
<br>![](res/subsetsum.png)<br>
```c++
bool isSubsetSum(int n, int arr[], int sum)
{
    bool m[n][sum + 1];
    for (int i = 0; i < n; ++i) m[i][0] = true;
    for (int i = 1; i < sum + 1; ++i) m[0][i] = (arr[0] == i) ? true : false;
    for (int j = 1; j < sum + 1; ++j)
    {
        for (int i = 1; i < n; ++i)
        {
            if (j - arr[i] > 0) m[i][j] = m[i-1][j] || m[i-1][j-arr[i]];
            else m[i][j] = m[i-1][j];
        }
    }
    return m[n-1][sum];
}
```

9) **Longest Common Subsequence:**
```
X = nematode
Y = empty
ans is 3 i.e. emt
This algorithm has application in biological field. If biologist discovers a DNA AGTABAG he wants to find which closest organism does DNA resembles

if (x[i] == y[j]) 1 + LCS(x[i+1], y[j+1])
otherwise max of LCS(x[i], y[j+1]) & LCS(x[i+1], y[j])

basically try matching if current i and j matches with i if not then either other n-i matches with other array or vice versa. We need to find max so max of both

DP Table
              i-->
    ""  A   G   G   T   A   B
""  0   0   0   0   0   0   0
G   0   0   1   1   1   1   1
X   0   0   1   1   1   1   1
T   0   0   1   1   2   2   2
X   0
T   0
A   0
B   0

dp[i][j] = 1+dp[i-1][j-1] or max(dp[i-1][j], dp[i][j-1])
depending upon (x[i] == y[j])
```

10) **Knapsack Problem:**