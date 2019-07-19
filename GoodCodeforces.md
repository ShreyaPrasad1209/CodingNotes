https://codeforces.com/contest/1194/problem/B
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector< vector<char> > a(n, vector<char> (m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        vector<int> x(m);
        for (int i = 0; i < m; ++i)
        {
            int k = 0;
            for (int j = 0; j < n; ++j)
                if (a[j][i] == '*') ++k;
            x[i] = m-k;
        }

        vector<int> y(n);
        for (int i = 0; i < n; ++i)
        {
            int k = 0;
            for (int j = 0; j < m; ++j)
                if (a[i][j] == '*') ++k;
            y[i] = n-k;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == '*') ans = min(ans, x[j] + y[i]);
                else ans = min(ans, x[j] + y[i] - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```