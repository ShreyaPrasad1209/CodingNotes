//Prime Looking Numbers - Page 49
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    flash;
    ll num = 999;
    ll arr[] = {2, 3, 5};
    ll n = sizeof(arr) / sizeof(ll);
    ll result = 0;
    for (ll i = 1; i < (1 << n); ++i)
    {
        ll mask = i, temp = 1, pos = 0, product = 1ll;
        ll bits = __builtin_popcount(mask);
        while (mask > 0)
        {
            ll lastBit = (mask&1);
            if (lastBit) product *= arr[pos];
            mask >>= 1;
            ++pos;
        }
        if (bits&1) result += num/product;
        else result -= num/product;
    }
    cout << result << endl;
    return 0;
}