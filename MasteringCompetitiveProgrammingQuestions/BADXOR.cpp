#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MOD 100000007

int dp[1025][1025];
ll powMod(ll a, ll b, ll m)
{
    ll x = 1;
    while (b > 0)
    {
        if (b&1) x = (x*a) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return x;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        fill(dp[0], dp[1024] + 1025, 0);
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < 1024; ++j)
                dp[i][j] += (dp[i-1][j] + dp[i-1][j ^ x]) % MOD;
        }

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
                cout << setw(3) << dp[i][j];
            cout << endl;
        }
        
        ll ans = 0;
        for (int i = 0; i < m; ++i)
        {
            int x;
            scanf("%d", &x);
            ans = (ans + dp[n][x]) % MOD;
        }
        cout << ans << endl;
        ans = (powMod(2, n, MOD) - ans + MOD) % MOD;
        // printf("Case %d: %lld\n", tc, ans);
    }
}