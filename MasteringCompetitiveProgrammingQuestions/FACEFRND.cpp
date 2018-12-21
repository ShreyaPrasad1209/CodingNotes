//https://www.spoj.com/problems/FACEFRND/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_set<int> f, fof;
    for (int i = 0; i < n; ++i)
    {
        int cur;
        cin >> cur;
        f.insert(cur);
        if (fof.find(cur) != f.end()) fof.erase(fof.find(cur));
        int count;
        cin >> count;
        for (int j = 0; j < count; ++j)
        {
            int id;
            cin >> id;
            if (f.find(id) == f.end()) fof.insert(id);
        }
    }
    cout << fof.size() << endl;
    return 0;
}