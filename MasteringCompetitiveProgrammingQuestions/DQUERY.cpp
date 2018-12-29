#include <bits/stdc++.h>
using namespace std;
#define MAX 300005

int arr[MAX], ans[MAX], p[1000005], tree[MAX] {};
pair<int, pair<int, int> > pr[MAX];

void update(int i, int val)
{
    while (i < MAX)
    {
        tree[i] += val;
        i += (i & -i);
    }
}

int query (int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += tree[i];
        i -= (i & -i);
    }
    return sum;
}

int main()
{
    int n, q, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &pr[i].second.first, &pr[i].first);
        pr[i].second.second = i;
    }
    sort(pr, pr+q);
    memset(p, -1, sizeof(p));
    x = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[arr[i]] != -1)
            update(p[arr[i]], -1);
        p[arr[i]] = i;
        update(i, 1);
        while (x < q && pr[x].first == i)
        {
            ans[pr[x].second.second] = query(pr[x].first) - query(pr[x].second.first-1);
            ++x;
        }
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
