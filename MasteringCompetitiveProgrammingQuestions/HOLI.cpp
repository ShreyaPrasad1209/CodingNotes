//Holiday Accomodation - Page 46
//https://www.spoj.com/problems/HOLI/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector< pair<ll, ll> > adj[100005];
ll ret = 0;
ll n;

ll dfs (ll par, ll u)
{
    ll ans = 1;
    for(ll i = 0; i < adj[u].size(); ++i)
    {
        ll v = adj[u][i].first;
        ll wt = adj[u][i].second;
        if(v==par) continue;
        
        ll nodes = dfs(u,v);
        ret += 2 * min(nodes, n-nodes) * wt;
        ans += nodes;
    }
    return ans;
}

int main()
{
    ll t;
    scanf("%lld", &t);
    ll tc = 1;
    while(t--)
    {
        ret = 0;
        scanf("%lld", &n);
        for (ll i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i <= n-1; ++i)
        {
            ll u, v, x;
            scanf("%lld %lld %lld", &u, &v, &x);
            adj[u].push_back({v, x});
            adj[v].push_back({u, x});
        }
        dfs(-1, 1);
        cout << "Case #" << tc++ << ": " << ret << endl;
    }
}