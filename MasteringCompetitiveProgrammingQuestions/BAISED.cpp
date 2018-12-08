//Biased Standings - Page 105
//https://www.spoj.com/problems/BAISED/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll A[n];
        for (ll i = 0; i < n; ++i)
        {
            string str;
            cin >> str >> A[i];
        }
        sort(A, A+n);
        ll ans = 0;
        for (ll i = 1; i <= n; ++i) ans += abs(A[i-1] - i);
        cout << ans << endl;
    }
    return 0;
}