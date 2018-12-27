//Gives TLE but solution is definitely correct
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c;
unordered_map<string, ll> dp;
ll solve(ll reqd[], ll n, ll i, ll emp, ll curVal)
{
    if (i >= n) return curVal;
    string key = to_string(i) + to_string(emp) + to_string(curVal);
    if (dp[key] != 0) return dp[key];
    ll minV = 1e9;
    if (reqd[i] >= emp)
    {
        ll tmp = reqd[i]*b + (reqd[i] - emp)*a + curVal;
        minV = min(minV, solve(reqd, n, i+1, reqd[i], tmp));
    }
    else
    {
        ll tmp2 = emp;
        for (ll cur = reqd[i]; cur <= tmp2; ++cur)
        {
            ll val = solve(reqd, n, i+1, cur, curVal + cur*b + (tmp2-cur)*c);
            if (val <= minV) minV = val, emp = cur;
        }
    }
    dp[key] = minV;
    return minV;
}
int main()
{
    ll t = 1;
    while (true)
    {
        dp.clear();
        ll n;
        scanf("%lld", &n);
        if (n == 0) break;
        scanf("%lld %lld %lld", &a, &b, &c);
        ll reqd[n];
        for (ll i = 0; i < n; ++i) scanf("%lld", &reqd[i]);
        printf("Case %lld, cost = $%lld\n", t, solve(reqd, n, 0, 0, 0));
        ++t;
    }
    return 0;
}

//Pure DP code AC :)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n, kx = 1;
	scanf("%d", &n);
	while(n)
	{
		ll arr[n+1], mx = 0, ans = 1e16;
		ll hire, sal, fire;
        scanf("%lld %lld %lld", &hire, &sal, &fire);
        for(int i = 1; i < n+1; ++i)
        {
            scanf("%lld", &arr[i]);
            mx = max(mx, arr[i]);
        }
        ll dp[50][1000];
        for (int i = 1; i < arr[1]; ++i) dp[1][i] = 1e16;
        for (int i = arr[1]; i < mx+1; ++i) dp[1][i] = i*(hire+sal);
        for (int i = 2; i < n+1; ++i)
        {
            for (int j= 1; j < mx+1; ++j)
            {
                dp[i][j] = 1e16;
                if (arr[i] > j) continue;
                for (int k = 1; k <= mx; ++k)
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + j*sal + (j > k ? (j-k)*hire : (k-j)*fire));
            }
        }
        for (int i = 1; i < mx+1; ++i) ans = min(ans, dp[n][i]);
        cout << "Case " << kx++ << ", cost = $" << ans << endl;
        scanf("%d", &n);
	}

    return 0;
}