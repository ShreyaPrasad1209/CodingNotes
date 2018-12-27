#include <bits/stdc++.h>
using namespace std;

int dp[3000][3000];
int EditDist(string a, string b)
{
    for (int i = 0; i <= a.size(); ++i) dp[i][0] = i;
    for (int i = 0; i <= b.size(); ++i) dp[0][i] = i;
    for (int i = 1; i <= a.size(); ++i)
    {
        for (int j = 1; j <= b.size(); ++j)
        {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }
    return dp[a.size()][b.size()];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a;
        cin >> b;
        cout << EditDist(a, b) << endl;
    }
    return 0;
}