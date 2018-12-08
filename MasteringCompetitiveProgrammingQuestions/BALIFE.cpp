//Load Balancing - Page 107
//https://www.spoj.com/problems/BALIFE/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1000000];
int main()
{
    while(true)
    {
        ll n;
        cin >> n;
        if (n == -1) break;
        for (ll i = 0; i < n; ++i)
        {
            ll x;
            cin >> x;
            A[i] = x;
            if (i > 0) A[i] += A[i-1];
        }
        if (A[n-1] % n) cout << "-1" << endl;
        else
        {
            ll avg = A[n-1]/n;
            ll ans = 0;
            for (ll i = 0; i < n; ++i)
            {
                ll cur = abs((avg * (i+1)) - A[i]);
                if (cur > ans) ans = cur;
            }
            cout << ans << endl;
        }
    }
    return 0;
}