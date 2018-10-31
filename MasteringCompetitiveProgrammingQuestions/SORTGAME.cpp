//Sort Game - Page 20
//https://hack.codingblocks.com/contests/c/101/90
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
#define mat(x, y, name) vector< vector<ull> > name (x, vector<ull>(y));
#define printMat(name) for (int i = 0; i < name.size(); ++i) {for (int j = 0; j < res[i].size(); ++j) cout << res[i][j] << " "; cout << endl;}

int MOD = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    vector< pair<string, int> > emp;
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        string x;
        int y;
        cin >> x >> y;
        emp.push_back(make_pair(x, y));
    }
    sort(emp.begin(), emp.end(), [](pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    for (int i = 0; i < n; ++i)
    {
        if (emp[i].second >= x)
            cout << emp[i].first << " " << emp[i].second << endl;
    }
    return 0;
}