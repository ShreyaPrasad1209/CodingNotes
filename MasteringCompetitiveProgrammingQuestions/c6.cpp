//Holiday Accomodation - Page 46
//https://www.spoj.com/problems/HOLI/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
#define mat(x, y, name) vector< vector<ull> > name (x, vector<ull>(y));
#define printMat(name) for (int i = 0; i < name.size(); i++) {for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " "; cout << endl;}

int MOD = 1000000000;

void perform(vector< pair<ulli, ulli> > a[], bool visited[], ulli sol[], ulli& ans, ulli n, ulli node = 0)
{
    visited[node] = true;
    sol[node] = 1;
    ulli at = a[node].size();
    for (ulli i = 0; i < a[node].size(); i++)
    {
        ulli v = a[node][i].first;
        if (!visited[v])
        {
            perform(a, visited, sol, ans, n, v);
            sol[node] += sol[v];
            ans += 2 * min(sol[v], n-sol[v]) * a[node][i].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ulli t;
    cin >> t;
    ulli tc = t;
    while(tc--)
    {
        ulli n;
        cin >> n;
        vector< pair<ulli, ulli> > a[n];
        bool visited[n] {};
        ulli sol[n] {};
        for (ulli i = 0; i < n-1; i++)
        {
            ulli x, y, z;
            cin >> x >> y >> z;
            a[x-1].push_back(make_pair(y-1, z));
            a[y-1].push_back(make_pair(x-1, z));
        }
        ulli ans = 0;
        perform(a, visited, sol, ans, n);
        cout << "case #" << t - tc << ": " << ans << endl;
    }
    return 0;
}