## 1) Flags
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    ll dp[n+1];
    dp[1] = 2;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) dp[i] = dp[i-2] + dp[i-1];
    cout << dp[n] << endl;
    return 0;
}
```