#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mat(x, y, name) vector< vector<ll> > name (x, vector<ll>(y));
#define printMat(name) for (int i = 0; i < name.size(); ++i) {for (int j = 0; j < res[i].size(); ++j) cout << res[i][j] << " "; cout << endl;}

#define MOD 98765431

vector< vector<ll> > matMul(vector< vector<ll> > A, vector< vector<ll> > B)
{
    vector< vector<ll> > C(A.size(), vector<ll>(B[0].size()));
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B[0].size(); ++j)
        {
            C[i][j] = 0;
            for (int k = 0; k < B.size(); ++k)
                C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
        }
    }
    return C;
}

vector< vector<ll> > matPow(vector< vector<ll> > A, int p)
{
    if (p == 1)
        return A;
    if (p&1)
        return matMul(A, matPow(A, p-1));
    else
    {
        vector< vector<ll> > C = matPow(A, p/2);
        return matMul(C, C);
    }
}

int main()
{
    flash;
    mat(2, 1, F);
    mat(2, 2, T);
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 1;
    F[0][0] = 1;
    F[1][0] = 1;
    for (int i = 1; i < 10; ++i)
        cout << (matMul(matPow(T, i), F)[0][0]) % MOD << " ";
    return 0;
}