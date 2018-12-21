//https://www.spoj.com/problems/WILLITST/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll num;
    cin >> num;
    if ((num & -num) == num) cout << "TAK" << endl;
    else cout << "NIE" << endl;
    return 0;
}