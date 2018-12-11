//Recursive Sequence - Page 40
//https://www.spoj.com/problems/SEQ/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mat(x, y, name) vector< vector<ll> > name (x, vector<ll>(y));

ll MOD = 1e9;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    while(c--)
    {
        int k;
        cin >> k;
        mat(k, 1, F);
        mat(k, k, T);
        for (int i = k-1; i >= 0; --i) cin >> F[i][0];
        for (int i = 0; i < k; ++i) cin >> T[0][i];
        int tmp = 1;
        while (tmp < k)
        {
            T[tmp][tmp-1] = 1;
            ++tmp;
        }

        int n;
        cin >> n;
        cout << matMul(matPow(T, n-1), F)[k-1][0] << endl;
    }
    return 0;
}