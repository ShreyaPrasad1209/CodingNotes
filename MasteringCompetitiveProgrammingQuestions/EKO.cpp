//EKO - page 98
//https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, l, r, mid, temp, temp2, temp3, curH, arr[1000005], freq[1000005];
int main()
{
    scanf("%lld %lld", &n, &m);
    temp = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &arr[i]);
        temp += arr[i];
    }
    sort(arr, arr+n+1);
    freq[0] = temp;
    temp2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        freq[i] = temp - temp2 - (arr[i] * (n-i+1));
        temp2 += arr[i];
    }
    l = 0, r = temp;
    while (l <= r)
    {
        mid = l + (r-l)/2;
        temp = 0, temp2 = 0;
        for (int i = n; i >= 0; --i)
        {
            if (freq[i] < mid) temp2 = freq[i], temp = arr[i];
            else
            {
                temp3 = n-i;
                break;
            }
        }
        if (mid < m) l = mid+1;
        else
        {
            double tempC = ((mid-temp2) / (double)temp3);
            temp2 = ((mid-temp2) / temp3);
            if (tempC - temp2 > 0)
                r = mid-1, curH = temp - temp2 - 1;
            else
                r = mid-1, curH = temp - temp2;
        }
    }
    printf("%lld\n", curH);
    return 0;
}