//Onotole needs your help
//https://www.spoj.com/problems/OLOLO/
#include<bits/stdc++.h>
#define ll long long
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll n, x, ans = 0;
int main()
{
    flash;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}
 