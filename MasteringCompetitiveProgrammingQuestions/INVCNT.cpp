//https://www.spoj.com/problems/INVCNT/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void update(ll BIT[], ll n, ll i, ll val)
{
    while (i <= n)
    {
        BIT[i] += val;
        i += (i & -i);
    }
}

ll query(ll BIT[], ll i)
{
    ll sum = 0;
    while (i > 0)
    {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; ++i) cin >> arr[i];
        ll maxElement = *max_element(arr, arr+n);
        ll BIT[maxElement+1] {};
        ll ans = 0;
        for (ll i = n-1; i >= 0; --i)
        {
            ans += query(BIT, arr[i]-1);
            update(BIT, maxElement, arr[i], 1);
        }
        cout << ans << endl;
    }
    return 0;
}

//For negative values or values differing a lot maintaining count will
//require a lot of space in BIT array this can be improved by coordinate compression
//[100, 99, 82, 11, 97, 100] = [5, 3, 2, 1, 4, 5] this can be done by simply putting elements in a set