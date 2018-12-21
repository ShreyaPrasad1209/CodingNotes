//https://www.spoj.com/problems/ENIGMATH/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
        cout << b << " " << a << endl;
    }
    return 0;
}