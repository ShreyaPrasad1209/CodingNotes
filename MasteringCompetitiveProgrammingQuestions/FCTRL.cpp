//Factorial
//https://www.spoj.com/problems/FCTRL/
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

ull t, n, ans, temp, x;
int main()
{
    flash;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;
        temp = 5;
        while(true)
        {
            x = n/temp;
            if (x == 0) break;
            ans += x;
            temp *= 5;
        }
        cout << ans << endl;
    }
    return 0;
}
