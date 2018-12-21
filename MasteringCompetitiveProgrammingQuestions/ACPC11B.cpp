//https://www.spoj.com/problems/ACPC11B/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1;
        int arr1[n1];
        for (int i = 0; i < n1; ++i) cin >> arr1[i];
        cin >> n2;
        int arr2[n2];
        for (int i = 0; i < n2; ++i) cin >> arr2[i];
        sort(arr1, arr1+n1);
        sort(arr2, arr2+n2);
        int i = 0, j = 0;
        int ans = 1000000000;
        while (i < n1 && j < n2)
        {
            if (i >= n1) i = n1;
            if (j >= n2) j = n2;
            int dist = arr1[i] - arr2[j];
            if (dist > 0) ++j;
            else ++i;
            dist = abs(dist);
            ans = min(ans, dist);
        }
        cout << ans << endl;
    }
    return 0;
}