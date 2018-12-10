//Chocolate
//https://www.spoj.com/problems/CHOCOLA/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, m, n, p, q, ans, x;
pair<ll, bool> arr[10000];
bool isX;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for (ll i = 0; i < m-1; ++i)
        {
            cin >> x;
            arr[i] = make_pair(x, true);
        }
        for (ll i = 0; i < n-1; ++i)
        {
            cin >> x;
            arr[m-1+i] = make_pair(x, false);
        }
        sort(arr, arr+m+n-2, greater< pair<ll, bool> >());

        p = 1, q = 1, ans = 0;
        for (int i = 0; i < m+n-2; ++i)
        {
            if (arr[i].second) ans += q * arr[i].first, ++p;
            else ans += p * arr[i].first, ++q;
        }
        cout << ans << endl;
    }
    return 0;
}
 