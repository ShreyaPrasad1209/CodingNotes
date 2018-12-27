#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int, ll> dp;
ll solve(int n)
{
    if (n == 0) return 0;
    if (dp[n] != 0) return dp[n];
    dp[n] = max(solve(n/2) + solve(n/3) + solve(n/4), (ll)n);
    return dp[n];
}

int n;
int main()
{
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4;
    while(scanf("%d", &n) == 1) printf("%lld\n", solve(n));
    return 0;
}