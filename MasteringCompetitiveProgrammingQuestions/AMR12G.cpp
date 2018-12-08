//The Glittering Caves of Aglarond
//https://www.spoj.com/problems/AMR12G/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t, n, m, k, ans = 0;
string x;
bool arr[52][52];
pair<int, int> counter[52];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
            counter[i].first = 0, counter[i].second = i;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            for (int j = 0; j < m; ++j)
            {
                if (x[j] == '*') arr[i][j] = true, ++(counter[i].first);
                else arr[i][j] = false;
            }
        }
        
        while(k--)
        {
            sort(counter, counter+n);
            counter[0].first = abs(m-counter[0].first);
            for (int i = 0; i < m; ++i)
                arr[counter[0].second][i] = !arr[counter[0].second][i];
        }

        ans = 0;
        for (int i = 0; i < n; ++i) ans += counter[i].first;
        cout << ans << endl;
    }
    return 0;
}
 