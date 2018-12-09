//https://hack.codingblocks.com/contests/c/511/1556
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
 
ll n, k, x, key, temp, arr[100005];
void swap(ll i, ll j)
{
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
int main()
{
    flash;
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &x);
        arr[i] = x;
    }
 
    if (k >= n)
    {
        sort(arr, arr+n, greater<int>());
        for (int i = 0; i < n; ++i) cout << arr[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            key = distance(arr, max_element(arr+i, arr+n));
            if (key != i) swap(key, i);
            else ++k;
        }
        for (int i = 0; i < n; ++i) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
 