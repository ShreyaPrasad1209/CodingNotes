//Fibonacci Sum - Page 59
//https://www.spoj.com/problems/SUMSUMS/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ulli;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
 
#define MOD 98765431
 
int main()
{
    flash;
    ulli n, t;
    cin >> n >> t;
    ulli c[n];
    ulli sum = 0;
    for (ulli i = 0; i < n; ++i)
    {
        cin >> c[i];
        sum += c[i];
    }
    while(t--)
    {
        for (ulli i = 0; i < n; ++i)
        {
            c[i] = (sum - c[i]) % MOD;
            if (c[i] < 0) c[i] += MOD;
        }
        sum = sum << 1;
    }
 
    for (ulli i = 0; i < n; ++i) cout << c[i] << endl;
    return 0;
} 