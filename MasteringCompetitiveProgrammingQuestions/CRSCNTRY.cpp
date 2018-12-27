#include <bits/stdc++.h>
using namespace std;

int LCS(vector<int> a, vector<int> b)
{
    int n = a.size()+1, m = b.size()+1;
    int dp[n][m];
    for (int i = 0; i < n; ++i) dp[i][0] = 0;
    for (int i = 0; i < m; ++i) dp[0][i] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
int main()
{
    int d;
    scanf("%d", &d);
    while (d--)
    {
        vector< vector<int> > wrds;
        while (true)
        {
            vector<int> cur;
            int temp = 0;
            while (true)
            {
                int inp;
                scanf("%d", &inp);
                if (inp == 0 && temp == 0) goto x;
                if (inp == 0) break;
                else cur.push_back(inp);
                ++temp;
            }
            wrds.push_back(cur);
        }
        x:;
        int ans = 0;
        for (int i = 1; i < wrds.size(); ++i) ans = max(ans, LCS(wrds[0], wrds[i]));
        printf("%d\n", ans);
    }
    return 0;
}