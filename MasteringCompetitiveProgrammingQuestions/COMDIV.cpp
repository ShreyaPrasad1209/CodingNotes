//https://www.spoj.com/problems/COMDIV/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int num = __gcd(a, b);
        int ans = 0;
        for (int i = 1; i*i <= num; ++i)
        {
            if (num%i == 0)
            {
                if (num/i == i) ans += 1;
                else ans += 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
