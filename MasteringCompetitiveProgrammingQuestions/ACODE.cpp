#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[5010];
    scanf("%s", a);
    while (a[0] != '0')
    {
        int n = strlen(a);
        long long int dp[n];
        for (int i = 0; i < n; i++) dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {

            int j = (a[i - 1] - '0') * 10 + (a[i] - '0');
            if (a[i] - '0') dp[i] = dp[i - 1];
            if (j > 9 && j < 27)
            {
                if (i == 1) dp[i] = dp[i] + 1;
                else dp[i] += dp[i - 2];
            }
        }
        printf("%lld\n", dp[n - 1]);
        scanf("%s", a);
    }
    if (a[0] == '0')
        return 0;
}