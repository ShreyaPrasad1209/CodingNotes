//AGGRCOW - page 96
//https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, c, l, r, mid, ans, counter, temp, arr[100005];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (ll i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr+n);
        l = 1, r = 1000000001, ans = 0;
        while (l <= r)
        {
            mid = l + (r-l)/2;
            counter = 1, temp = arr[0];
            for (ll i = 1; i < n; ++i)
            {
                if (arr[i] - temp >= mid)
                    ++counter, temp = arr[i];
            }
            if (counter < c) r = mid-1;
            else l = mid+1, ans = mid;
        }
        cout << ans << endl;
    }
    return 0;
}