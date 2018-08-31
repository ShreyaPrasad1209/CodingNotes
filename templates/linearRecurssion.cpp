#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
typedef long long ll;
typedef unsigned long long ull;

vector< vector<ull> > matMul(vector< vector<ull> > A, vector< vector<ull> > B)
{
    vector< vector<ull> > C(A.size(), vector<ull>(B[0].size()));
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

vector< vector<ull> > matPow(vector< vector<ull> > A, int p)
{
    if (p == 1)
        return A;
    if (p&1)
        return matMul(A, matPow(A, p-1));
    else
    {
        vector< vector<ull> > C = matPow(A, p/2);
        return matMul(C, C);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}