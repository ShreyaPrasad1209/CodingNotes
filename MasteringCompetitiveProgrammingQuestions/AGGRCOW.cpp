//AGGRCOW - page 96
//https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, c;
        cin >> n >> c;
        ll a[100009];
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a+n);
        ll l = 1, r = 1000000001, ans = 0;
        while(l <= r)
        {
            ll mid = l + (r-l)/2;
            int fi = a[0], temp = 1;
            for (int k = 1; k < n; ++k)
            {
                if (a[k] - fi >= mid)
                {
                    ++temp;
                    fi = a[k];
                }
            }
            if (temp < c) r = mid-1;
            else
            {
                ans = mid;
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}