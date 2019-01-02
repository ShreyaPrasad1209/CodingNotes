#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[1000];
ll dp[1000][1000];
ll sum(int i, int j)
{
    ll ans = 0;
    for (int k = i; k <= j; ++k)
    {
        ans += arr[k];
        ans %= 100;
    }
    return ans;
}
ll solve(int i, int j)
{
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k <= j; ++k)
        dp[i][j] = min(dp[i][j], solve(i, k) + solve(k+1, j) + (sum(i, k) * sum(k+1, j)));
    return dp[i][j];
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
                dp[i][j] = -1;
        }
        cout << solve(0, n-1) << endl;
    }
    return 0;
}
