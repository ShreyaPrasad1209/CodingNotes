//Sorting Bank Accounts
//https://www.spoj.com/problems/SBANK/
#include<bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

int t, n;
char x[100];
map<string, int> mp;
int main()
{
    flash;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%d\n", &n);
        mp.clear();
        for (int i = 0; i < n; ++i)
        {
            scanf ("%[^\n]%*c", x);
            ++mp[(string)x];
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
            cout << it->first << it->second << endl;
        
        if (t > 0) cout << endl;
    }
    return 0;
}
