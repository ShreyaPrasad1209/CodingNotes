//Chopsticks - Page 112
//https://www.codechef.com/problems/TACHSTCK
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];
int main()
{
    ll n, d;
    cin >> n >> d;
    for (ll i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    ll ans = 0;
    for (ll i = 1; i < n; ++i)
    {
        if (abs(arr[i] - arr[i-1]) <= d)
            ++ans, ++i;
    }
    cout << ans << endl;
    return 0;
}