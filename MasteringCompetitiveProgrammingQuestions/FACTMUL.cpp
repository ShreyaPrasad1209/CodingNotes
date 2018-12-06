//Product of factorials - Page 87
//https://www.spoj.com/problems/FACTMUL/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact[587117 + 10];
ll MOD = 109546051211LL;

ll mul(ll a, ll b)
{
    ll res = 0;
    while(b)
    {
        if (b&1)
        {
            res += a;
            if (res >= MOD) res -= MOD;
        }
        b >>= 1;
        a = (a << 1);
        if (a >= MOD) a-= MOD;
    }
    return res;
}

void process()
{
    fact[0] = 1;
    for (int i = 1; i < 587117; ++i)
        fact[i] = mul(i, fact[i-1]);
}

int main()
{
    //Modulo p which is 109546051211
    //p = p1 * p2 = 186583 * 587117
    //x1 = ans % p1
    //x2 = ans % p2
    //solve ans using chinease remainder theorem
    process();

    int x;
    cin >> x;
    if (x >= 587117) cout << 0 << endl;
    else
    {
        ll ans = 1;
        for (int i = 1; i <= x; ++i) ans = mul(ans, fact[i]);
        cout << ans << endl;
    }

	return 0;
}