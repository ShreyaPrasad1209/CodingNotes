//Recursive Sequence - Page 40
//https://www.spoj.com/problems/SEQ/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
#define mat(x, y, name) vector< vector<ull> > name (x, vector<ull>(y));

int MOD = 1000000000;

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

    int c;
    cin >> c;
    while(c--)
    {
        int k;
        cin >> k;
        mat(k, 1, F);
        mat(k, k, T);
        int x = k-2;
        while(x >= 0)
        {
            T[x][x+1] = 1;
            x--;
        }
        for (int i = 0; i < k; i++) cin >> F[i][0];
        for (int i = k-1; i >= 0; i--) cin >> T[k-1][i];
        
        int n;
        cin >> n;
        cout << matMul(matPow(T, n-1), F)[0][0] << endl;
    }
    return 0;
}