#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000010
ll st, ed, tree[400010], lpd[1000010], arr[100010];

void Sieve()
{
    lpd[1] = 1;
    for(int i = 3; i < MAX; i += 2) lpd[i] = 0;
    for(int i = 2; i < MAX; i += 2) lpd[i] = 2;
    for(int i = 3; i < 1010; i += 2)
    {
        if(!lpd[i])
        {
            lpd[i] = i;
            for(int j = i; (j * i) < MAX; j += 2)
            {
                if(!lpd[i * j]) lpd[i * j] = i;
            }
        }
    }

    for(int i=3;i<MAX;i+=2)
    {
        if(!lpd[i])
            lpd[i] = i;
    }
}

ll LPD(ll index)
{
    return lpd[arr[index]]; 
}

void build_tree(ll node,ll a,ll b )
{
    if(a==b)
    {
       tree[node]=LPD(a);
       return;
    }
    ll mid=(a+b)>>1;
    build_tree(node<<1,a,mid);
    build_tree((node<<1)|1,mid+1,b);
    tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
    return;
}

void lazyPropagatePendingUpdateToSubtree(ll node,ll a,ll b)
{
    if (tree[node]==1) return;
    if (a == b)
    {
        ll temp=LPD(a);
        arr[a]/=temp;
        tree[node]=LPD(a);
        return;
    }
    ll mid = (a + b)>>1;
    lazyPropagatePendingUpdateToSubtree(node<<1,a,mid);
    lazyPropagatePendingUpdateToSubtree((node<<1)|1,mid+1,b);        
    tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}

void update_tree(ll node,ll a,ll b)
{
    if(a> ed || b < st) return;
    if(a >= st && b <= ed)
    {
        lazyPropagatePendingUpdateToSubtree(node,a,b);
        return;
    }
    ll mid = (a+b) >> 1;
    update_tree(node << 1,a,mid);
    update_tree((node << 1) | 1, mid+1, b);
    tree[node] = max(tree[node<<1], tree[(node<<1) | 1]);
}

ll query_tree(ll node,ll a,ll b)
{
    if(a > ed || b < st) return 0;
    if(a >= st && b <= ed)
    return tree[node];
    ll mid = (a + b) >> 1;
    return max(query_tree(node << 1, a, mid), query_tree((node << 1) | 1, mid+1, b));
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    Sieve();
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        build_tree(1, 1, n);
        for(int i=0;i<m;i++)
        {
            int ch;
            cin >> ch >> st >> ed;
            if(!ch) update_tree(1, 1, n);
            else cout << query_tree(1, 1, n) << " ";
        }
        cout << endl;
    }
    return 0;
}