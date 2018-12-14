//Matrix Queries I
//https://hack.codingblocks.com/contests/c/128/813
#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100005];
vector<int> tree[1000005];
vector<int> identity{ 1, 0, 0, 1 };
int rM, n, q, a, b, c, d, lft, rgt;
void buildTree(vector<int> arr[], int start, int end, int node = 1)
{
    if (start == end)
    {
        tree[node] = arr[end];
        return;
    }
    int mid = (start + end) >> 1;
    buildTree(arr, start, mid, node*2);
    buildTree(arr, mid+1, end, node*2 + 1);
    tree[node] =
    {
        (((tree[node*2][0] * tree[node*2 + 1][0]) % rM) + ((tree[node*2][1] * tree[node*2 + 1][2]) % rM)) % rM,
        (((tree[node*2][0] * tree[node*2 + 1][1]) % rM) + ((tree[node*2][1] * tree[node*2 + 1][3]) % rM)) % rM,
        (((tree[node*2][2] * tree[node*2 + 1][0]) % rM) + ((tree[node*2][3] * tree[node*2 + 1][2]) % rM)) % rM,
        (((tree[node*2][2] * tree[node*2 + 1][1]) % rM) + ((tree[node*2][3] * tree[node*2 + 1][3]) % rM)) % rM,
    };
}
vector<int> queryTree(int start, int end, int l, int r, int node = 1)
{
    if (start > end || start > r || end < l) return identity;
    if (start >= l && end <= r)
        return tree[node];
    int mid = (start + end) >> 1;
    vector<int> q1 = queryTree(start, mid, l, r, node*2);
    vector<int> q2 = queryTree(mid+1, end, l, r, node*2 + 1);
    vector<int> prod = 
    {
        (((q1[0] * q2[0]) % rM) + ((q1[1] * q2[2]) % rM)) % rM,
        (((q1[0] * q2[1]) % rM) + ((q1[1] * q2[3]) % rM)) % rM,
        (((q1[2] * q2[0]) % rM) + ((q1[3] * q2[2]) % rM)) % rM,
        (((q1[2] * q2[1]) % rM) + ((q1[3] * q2[3]) % rM)) % rM,
    };
    return prod;
}
int main()
{
    cin >> rM >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        cin >> c >> d;
        arr[i] = { a, b, c, d };
    }
    buildTree(arr, 0, n-1);
    for (int i = 0; i < q; ++i)
    {
        cin >> lft >> rgt;
        vector<int> res = queryTree(0, n-1, lft-1, rgt-1);
        cout << res[0] << " " << res[1] << endl;
        cout << res[2] << " " << res[3] << endl;
        cout << endl;
    }
    return 0;
}