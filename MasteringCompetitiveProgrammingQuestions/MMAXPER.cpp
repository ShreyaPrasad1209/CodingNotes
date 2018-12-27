//https://www.spoj.com/problems/MMAXPER/
#include <bits/stdc++.h>
using namespace std;

int n, arr[2000][2], dp[2000][2000];
int solve(int i = 0, int last = 0)
{
    if (i >= n) return -last;
    if (dp[i][last] != -1) return dp[i][last];
    if (i == 0)
    {
        int q1 = arr[i][1] + arr[i][0] + solve(i+1, arr[i][0]);
        int q2 = arr[i][0] + arr[i][1] + solve(i+1, arr[i][1]);
        dp[i][last] = max(q1, q2);
        return dp[i][last];
    }

    int dx1 = abs(arr[i][0] - last);
    int l1 = max(arr[i][0], last) - dx1;
    if (last > arr[i][0]) dx1 = 0;
    int dx2 = abs(arr[i][1] - last);
    int l2 = max(arr[i][1], last) - dx2;
    if (last > arr[i][1]) dx2 = 0;
    int q1 = -l1 + dx1 + arr[i][1] + arr[i][0] + solve(i+1, arr[i][0]);
    int q2 = -l2 + dx2 + arr[i][0] + arr[i][1] + solve(i+1, arr[i][1]);
    dp[i][last] = max(q1, q2);
    return dp[i][last];
}
int main()
{
    for (int i = 0; i < 2000; ++i)
    {
        for (int j = 0; j < 2000; ++j)
            dp[i][j] = -1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i][0], &arr[i][1]);
    cout << solve() << endl;
    return 0;
}