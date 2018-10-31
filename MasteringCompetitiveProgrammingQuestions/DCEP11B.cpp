//DCEPC11B - Page 71
//https://www.spoj.com/problems/DCEPC11B/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

ll powMod(ll a, ll b, ll m)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b & 1) x = (x * y) % m;
        y = (y * y) % m;
        b >>= 1;
    }
    return x;
}

int main()
{
    flash;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        if (n >= p)
        {
            cout << 0 << endl;
            continue;
        }
        ll result = -1;
        for (ll i = n + 1; i < p; ++i)
            result = (result * powMod(i, p-2, p)) % p;
        if (result < 0) result += p;
        cout << result << endl;
    }
    return 0;
}