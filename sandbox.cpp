#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int answer = 0, count = 0;
    for (int i : arr)
    {
        if (count == 0) answer = i;
        if (i == answer) ++count;
        else --count;
    }
    return 0;
}