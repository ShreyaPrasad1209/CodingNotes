//Divisor Summation - Page 82
//https://www.spoj.com/problems/DIVSUM/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        if (x == 1) cout << 0 << endl;
        else
        {
            ll ans = 1;
            for (int i = 2; i*i <= x; ++i)
            {
                if (x % i == 0)
                {
                    if (i == x/i) ans += i;
                    else ans += i + x/i;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}