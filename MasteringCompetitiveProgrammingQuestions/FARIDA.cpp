//https://www.spoj.com/problems/FARIDA/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[10001], dp[10001];
int main()
{
    int t;
    cin >> t;
    for (int x = 1; x <= t; ++x)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        dp[0] = arr[0], dp[1] = max(dp[0], arr[1]);
        for (int i = 2; i < n; ++i) dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
        cout << "Case " << x << ": " << dp[n-1] << endl;
    }
    return 0;
}