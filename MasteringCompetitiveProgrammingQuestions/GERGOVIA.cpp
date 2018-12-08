//Wine trading in Gergovia - Page 122
//https://www.spoj.com/problems/GERGOVIA/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, x, p, q, ans, temp1, temp2;
pair<ll, ll> A[100005], B[100005];
int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        p = 0, q = 0, ans = 0, temp1 = 0, temp2 = 0;
        for (ll i = 0; i < n; ++i)
        {
            cin >> x;
            if (x > 0) A[p] = make_pair(i, x), ++p;
            else if (x < 0) B[q] = make_pair(i, -x), ++q;
        }
        sort(A, A+p), sort(B, B+q);
        while (temp1 < p && temp2 < q)
        {
            ans += abs(A[temp1].first - B[temp2].first) * min(A[temp1].second, B[temp2].second);
            if (A[temp1].second > B[temp2].second)
            {
                A[temp1].second -= B[temp2].second;
                ++temp2;
            }
            else if (A[temp1].second < B[temp2].second)
            {
                B[temp2].second -= A[temp1].second;
                ++temp1;
            }                
            else ++temp1, ++temp2;
        }
        cout << ans << endl;
    }
    return 0;
}
 