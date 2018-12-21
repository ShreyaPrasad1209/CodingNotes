//https://www.spoj.com/problems/TRICOUNT/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = (n*(n+2)*(2*n + 1)) / 8;
        cout << ans << endl;
    }
    return 0;
}