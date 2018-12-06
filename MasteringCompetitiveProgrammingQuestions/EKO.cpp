//EKO - page 98
//https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll woodCut(vector<ll> &v, ll h)
{
    ll sum = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] > h)
            sum += v[i]-h;
    }
    return sum;
}
ll binarySearch(vector<ll> &v, ll required)
{
    ll low = 0 , mid , high = LLONG_MAX/10;
    ll ans = LLONG_MIN;
    while(low < high)
    {
        mid = low + (high - low)/2;
        ll wood = woodCut(v , mid);
        if(wood >= required)
        {
            low = mid+1;
            ans = max(ans , mid);
        }
        else high = mid;
    }
    return ans;
}
int main()
{    
    ll n , m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    cout << binarySearch(v, m) << endl;
    return 0;
}