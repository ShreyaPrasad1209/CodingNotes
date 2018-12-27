#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int dp[n][n] {};
    int year = n;
    for (int i = 0; i < n; ++i) dp[i][i] = year * arr[i];
    for (int j = 0; j < n; ++j)
    {
        year = n-1;
        for (int i = j-1; i >= 0; --i)
        {
            dp[i][j] = max(dp[i+1][j] + arr[i]*year, dp[i][j-1] + arr[j]*year);
            --year;
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}