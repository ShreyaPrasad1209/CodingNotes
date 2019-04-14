// https://www.spoj.com/problems/AIBOHP/
#include <bits/stdc++.h>
using namespace std;

static int dp[6101][6101];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char str[6102];
        scanf("%s", str);
        int len = strlen(str);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0, k = i; k < len; ++k, ++j)
                dp[j][k] = (str[j] == str[k]) ? dp[j+1][k-1]
                    : min(dp[j][k-1], dp[j+1][k]) + 1;
        }
        printf("%d\n", dp[0][len-1]);
    }
	return 0;
}