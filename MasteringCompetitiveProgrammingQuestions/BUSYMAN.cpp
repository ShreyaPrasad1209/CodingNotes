//I AM VERY BUSY - Page 102
//https://www.spoj.com/problems/BUSYMAN/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector< pair<int, int> > act;
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            act.push_back(make_pair(a, b));
        }
        sort(act.begin(), act.end(), [](pair<int, int> &A, pair<int, int> &B)
        {
            return ((A.second < B.second) ||
                (A.second == B.second && A.first < B.first));
        });
        int counter = 1, timer = act[0].second;
        for (int i = 1; i < n; ++i)
        {
            if (act[i].first >= timer)
            {
                ++counter;
                timer = act[i].second;
            }
        }
        cout << counter << endl;
    }
    return 0;
}