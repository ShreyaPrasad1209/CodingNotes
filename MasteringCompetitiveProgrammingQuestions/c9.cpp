//Fibonacci Sum - Page 59
//https://www.spoj.com/problems/FIBOSUM/
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define mat(x, y, name) vector< vector<lli> > name (x, vector<lli>(y));

lli MOD = 1000000007;

vector< vector<lli> > matMul(vector< vector<lli> > A, vector< vector<lli> > B)
{
    vector< vector<lli> > C(A.size(), vector<lli>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < B.size(); k++)
                C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
        }
    }
    return C;
}

vector< vector<lli> > matPow(vector< vector<lli> > A, int p)
{
    if (p == 1)
        return A;
    if (p&1)
        return matMul(A, matPow(A, p-1));
    else
    {
        vector< vector<lli> > C = matPow(A, p/2);
        return matMul(C, C);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mat(2, 1, F);
    mat(2, 2, T);
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 1;
    F[0][0] = 1;
    F[1][0] = 1;
    int t;
    cin >> t;
    while(t--)
    {
        lli n, m;
        cin >> n >> m;
        lli minSum = (n == 0) ? 0 : ((matMul(matPow(T, n), F)[0][0]) - 1) % MOD;
        lli maxSum = (m == 0) ? 0 : ((matMul(matPow(T, m+1), F)[0][0]) - 1) % MOD;
        lli ans = (maxSum - minSum) % MOD;
        if (ans < 0)
        {
            ans += MOD;
            ans = ans % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}