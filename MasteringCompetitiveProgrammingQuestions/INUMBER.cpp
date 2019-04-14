#include <bits/stdc++.h>
using namespace std;

// dp[i][j] stores previous sum where i = modulo and j = digitSum
int dp[1011][1011];     // Stores last digit sum
int lst[1011][1011];    // Stores last number, needed for backtracking
int MO[1011][1011];     // Stores last modulo, needed for backtracking

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        memset(MO, 0, sizeof(MO));

        queue<pair<int, int>> q;
        for (int i = 1; i <= 9; i++)
        {
            q.push(make_pair(i % n, i));
            dp[i % n][i] = i;
            lst[i % n][i] = i;
        }

        while (!q.empty())
        {
            int ds, rem;
            pair<int, int> tp = q.front();
            q.pop();
            rem = tp.first;
            ds = tp.second;
            if (rem == 0 && ds == n) break;

            for (int i = 0; i <= 9; i++)
            {
                tp.first = (rem * 10 + i) % n;
                tp.second = ds + i;
                // Check if we have already covered this state or if it's impossible then skip
                if (dp[tp.first][tp.second] != -1 || tp.second > n) continue;

                q.push(tp);
                dp[tp.first][tp.second] = ds + i;
                lst[tp.first][tp.second] = i;
                MO[tp.first][tp.second] = rem;
            }
        }

        // Backtracking to find answer value
        int m = 0, s = n;
        stack<int> ans;
        for (int i = 0; ; i++)
        {
            if (m == 0 && s == 0) break;
            ans.push(lst[m][s]);
            int m1 = MO[m][s];
            int s1 = (dp[m][s] - lst[m][s]);
            m = m1;
            s = s1;
        }

        while (!ans.empty())
        {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
}