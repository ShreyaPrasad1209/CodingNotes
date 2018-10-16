//Array Sub - Page 21
//https://www.spoj.com/problems/ARRAYSUB/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
#define mat(x, y, name) vector< vector<ull> > name (x, vector<ull>(y));
#define printMat(name) for (int i = 0; i < name.size(); i++) {for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " "; cout << endl;}

int MOD = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    deque<int> Q(k);
    for (int i = 0; i < k; i++)
    {
        while(!Q.empty() && a[i] >= a[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << a[Q.front()] << " ";
        while((!Q.empty()) && (Q.front() <= i-k)) Q.pop_front();
        while((!Q.empty()) && (a[i] >= a[Q.back()])) Q.pop_back();
        Q.push_back(i);
    }
    cout << a[Q.front()] << endl;
    return 0;
}