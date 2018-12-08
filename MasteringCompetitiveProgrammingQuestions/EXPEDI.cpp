//Expedition - Page 113
//https://www.spoj.com/problems/EXPEDI/
#include<bits/stdc++.h>
using namespace std;

set< pair<int,int> >st;
vector< pair<int,int> >vec;
int n, dist, fuel, a, b, start, cnt, ans;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vec.clear();
        st.clear();
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> a >> b;
            vec.push_back(make_pair(a, b));
        }
        sort(vec.begin(), vec.end());
        cin >> dist >> fuel;

        start = dist, cnt = n-1, ans = 0;
        for (int i = 0; i < dist; ++i, --fuel)
        {
            if(cnt != -1)
            {
                if(start - vec[cnt].first == i)
                {
                    st.insert(make_pair(vec[cnt].second,vec[cnt].first));
                    --cnt;
                }
            }
            if(fuel == 0)
            {
                if(st.size() == 0)
                {
                    cout << "-1" << endl;
                    goto x;
                    break;
                }
                auto it = st.end();
                ++ans, --it;
                fuel = fuel + ((*it).first);
                st.erase(it);
            }
        }
        cout << ans << endl;
        x:;
    }
    return 0;
}