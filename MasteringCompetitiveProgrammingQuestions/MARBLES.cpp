//Marbles - Page 59
//https://www.codechef.com/problems/MARBLES
#include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;

ll nCr (int n, int m)
{
    if (m > n - m) m = n - m;    
    ll ans = 1;
    for (int i = 0; i < m; ++i) ans = ans * (n - i) / (i + 1);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cout << nCr(n-1, k-1) << endl;
    }
    return 0;
}