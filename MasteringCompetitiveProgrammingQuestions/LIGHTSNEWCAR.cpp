//Lights New Car - Page 73
//https://codingblocks.com/resources/lights-new-car/
//https://youtu.be/K_UOxtlAIms
#include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

ll string2Int(string a, ll m)
{
    ll ans = 0ll;
    for (int i = 0; i < a.size(); ++i)
        ans = (((ans * 10) % m) + (a[i] - '0')) % m;
    return ans;
}

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
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        ll x = string2Int(a, mod);
        ll y = string2Int(a, mod-1);
        ll ans = powMod(x, y, mod);
        cout << ans << endl;
    }
}