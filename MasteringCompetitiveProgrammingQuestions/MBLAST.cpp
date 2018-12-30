#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[2005], b[2005];
    int k;
    scanf("%s %s %d", a, b, &k);
    int na = strlen(a), nb = strlen(b);
    int dp[na+1][nb+1];
    dp[0][0] = 0;
    for (int i = 1; i <= na; ++i) dp[i][0] = i*k;
    for (int j = 1; j <= nb; ++j) dp[0][j] = j*k;
    for (int i = 1; i <= na; ++i)
    {
        for (int j = 1; j <= nb; ++j)
        {
            dp[i][j] = min(dp[i-1][j-1] + abs((int)a[i-1] - (int)b[j-1]),
                min(dp[i-1][j], dp[i][j-1]) + k);
        }
    }
    printf("%d\n", dp[na][nb]);
    return 0;
}
