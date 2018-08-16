#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int factorial(int n) { return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n; }

//Articulation point is a point by removing it all the vertex of the graph will disconnect
//What it does is it finds a backedge
//  A ---- B ---- C
//Clearly in this B is articulation point
//  A ---- B ---- C
//  |-------------|
//However in this there is a backedge so B is no longer an articulation point

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}