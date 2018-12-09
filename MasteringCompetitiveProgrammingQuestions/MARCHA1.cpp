//https://www.codechef.com/problems/MARCHA1
#include<bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

int t, n, m, mask, pos, counter, arr[25];
int main()
{
    flash;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        for (int i = 0; i < (1<<n); ++i)
        {
            mask = i, pos = 0, counter = 0;
            while (mask > 0)
            {
                if (mask&1) counter += arr[pos];
                mask >>= 1;
                ++pos;
            }
            if (counter == m)
            {
                cout << "Yes" << endl;
                goto x;
            }
        }
        cout << "No" << endl;
        x:;
    }
    return 0;
}
