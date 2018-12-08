//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/hostel-visit/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);

ll q, k, v, x, y, temp;
priority_queue<ll> pq;
int main()
{
    flash;
    cin >> q >> k;
    while(q--)
    {
        cin >> v;
        if (v == 1)
        {
            cin >> x >> y;
            temp = x*x + y*y;
            if (pq.size() == k)
            {
                if (temp < pq.top())
                {
                    pq.pop();
                    pq.push(temp);
                }
            }
            else pq.push(temp);
        }
        else cout << pq.top() << endl;
    }
    return 0;
}
