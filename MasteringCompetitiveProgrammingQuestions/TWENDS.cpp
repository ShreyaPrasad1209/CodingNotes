
#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, val[1005], dp[1005][1005];
int solve(int l, int r)
{
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    else
    {
        int q1 = (val[l+1] >= val[r]) ? solve(l+2, r) : solve(l+1, r-1);
        q1 += val[l];
        int q2 = (val[l] >= val[r-1]) ? solve(l+1, r-1) : solve(l, r-2);
        q2 += val[r];
        dp[l][r] = max(q1, q2);
        return dp[l][r];
    }
}
int main()
{  
    scanf("%d", &n);
    int sum = 0, counter = 0;
    while (n)
    {
        sum = 0;
        ++counter;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &val[i]);
            sum += val[i];
        }
        memset(dp, -1, sizeof(dp));
        ans = solve(0, n-1);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",
            counter, (2*ans) - sum);
        scanf("%d", &n);
    }
    return 0;
}
