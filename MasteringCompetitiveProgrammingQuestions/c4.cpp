//Divisible Subset - Page 45
//https://www.codechef.com/status/DIVSUBS
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll b[n + 1];
        b[0] = 0;
        vector<ll> temp[n];
        temp[b[0] % n].push_back(0);
        for(int i=1; i<=n; ++i)
        {
            b[i] = b[i - 1] + a[i - 1];
            temp[b[i] % n].push_back(i);
        }
        ll start, end;
        for(int i=0; i<n; ++i)
        {
            if(temp[i].size() >=2 )
            {
                start = temp[i][0];
                end = temp[i][1];
            }
        }
        cout << (end - start) << endl;
        for(int i = start + 1; i <= end; ++i)
            cout << i << " ";
        
        cout << endl;
    }
    return 0;
}