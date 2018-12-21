//https://www.spoj.com/problems/TWOSQRS/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000001];
int main()
{   
    for (ll i = 0; i < 1000001; ++i) a[i] = i * i;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n, x;
        scanf("%lld", &n);
        int i = 0, j = sqrt(n);
        while (i <= j)
        {
            x = a[i] + a[j];
            if (x == n) break;
            if (x < n) i++;
            else j--;
        }
        if (i <= j) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}