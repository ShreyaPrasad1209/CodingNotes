//Die Hard - Page 122
//https://www.spoj.com/problems/DIEHARD/
#include<bits/stdc++.h>
using namespace std;

int t, h, a, ans, last;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> h >> a;
        last = -1, ans = 0;
        while (h > 0 && a > 0)
        {
            if (last != 0) h += 3, a += 2, last = 0;
            else
            {
                if (h > 5 && a > 10 && last != 1) h -= 5, a -= 10, last = 1;
                else h -= 20, a += 5, last = 2;
            }
            if (h > 0 && a > 0) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
 