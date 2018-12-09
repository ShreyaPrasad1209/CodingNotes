//Subset Sums
//https://www.spoj.com/problems/SUBSUMS/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a, b, i, mask, pos, cur, temp, ans, arr[35];

vector<ll> countSum(ll l, ll r)
{
    vector<ll> res;
    r -= l;
    for (i = 0; i < (1<<r); ++i)
    {
        mask = i, pos = 0, cur = 0;
        while(mask > 0)
        {
            if (mask&1) cur += arr[l+pos];
            mask >>= 1;
            ++pos;            
        }
        res.push_back(cur);
    }
    return res;
}

int main()
{
    scanf("%lld %lld %lld", &n, &a, &b);
    for (i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    vector<ll> count1 =  countSum(0, n/2);
    vector<ll> count2 =  countSum(n/2, n);
    sort(count1.begin(), count1.end());

    ans = 0;
    for (i = 0; i < count2.size(); ++i)
    {
        auto low = lower_bound(count1.begin(), count1.end(), a-count2[i]);
        auto high = upper_bound(count1.begin(), count1.end(), b-count2[i]);
        ans += (high-low);
    }
    printf("%lld", ans);
    return 0;
}
