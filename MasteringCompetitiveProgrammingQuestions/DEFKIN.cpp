//DEFENSE OF A KINGDOM - Page 110
//https://www.spoj.com/problems/DEFKIN/
#include <bits/stdc++.h>
using namespace std;

int dx[40005], dy[40005];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = 0; i < z; ++i) cin >> dx[i] >> dy[i];
        sort(dx, dx+z);
        sort(dy, dy+z);
        for (int i = z; i >= 0; --i)
        {
            if (i == z) dx[i] = x - dx[i-1], dy[i] = y - dy[i-1];
            else if (i == 0) --dx[i], --dy[i];
            else dx[i] -= dx[i-1]+1, dy[i] -= dy[i-1]+1;
        }
        cout << (*max_element(dx, dx+z+1)) * (*max_element(dy, dy+z+1)) << endl;
    }
    return 0;
}