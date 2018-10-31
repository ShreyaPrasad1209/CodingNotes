//POWPOW - Page 75
//https://www.spoj.com/problems/POWPOW/
#include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;

static const ll M = 1e9 + 7;

ll powMod(ll a, ll b, ll m)
{
    if (a == 0 && b == 0) return 1;
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b & 1) x = (x * y) % m;
        y = (y * y) % m;
        b >>= 1;
    }
    return x;
}

ll nCr(ll n, ll r, ll p)
{
    if (n < r) return 0;
    ll res = 1, rem = 1;
    for (ll i = n - r + 1; i <= n; i++) res = (res * i) % p;
    for (ll i = 2; i <= r; i++) rem = (rem * i) % p;
    return (res * powMod(rem, p - 2, p)) % p;
}

int main()
{
    flash;
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll exp = nCr(2*n, n, M);
        ll tmp = powMod(b, exp, M);
        ll ans = powMod(a, tmp, M);
        cout << ans << endl;
    }
    return 0;
}