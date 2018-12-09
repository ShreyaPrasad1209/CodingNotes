//https://www.spoj.com/problems/GIRLSNBS/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

ll g, b, n, tmpI;
double tmpD;
int main()
{
    flash;
    while(true)
    {
        cin >> g >> b;
        if (g == -1 && b == -1) break;
        else if (g == 0 || b == 0) cout << max(g, b) << endl;
        else if (g == b) cout << 1 << endl;
        else
        {
            n = min(g, b) + 1;
            tmpD = (double)max(g, b) / n;
            tmpI = floor(tmpD);
            if (tmpD > tmpI) ++tmpI;
            cout << tmpI << endl;
        }
    }
    return 0;
}
