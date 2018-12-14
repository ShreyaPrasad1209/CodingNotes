//https://www.spoj.com/problems/SUMSUMS/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mat(x, y, name) vector< vector<ll> > name (x, vector<ll>(y));
#define prllMat(name) for (ll i = 0; i < name.size(); ++i) {for (ll j = 0; j < name[i].size(); ++j) cout << name[i][j] << " "; cout << endl;}

#define MOD 98765431

vector< vector<ll> > matMul(vector< vector<ll> > A, vector< vector<ll> > B)
{
    vector< vector<ll> > C(A.size(), vector<ll>(B[0].size()));
    for (ll i = 0; i < A.size(); ++i)
    {
        for (ll j = 0; j < B[0].size(); ++j)
        {
            C[i][j] = 0;
            for (ll k = 0; k < B.size(); ++k)
                C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
        }
    }
    return C;
}

vector< vector<ll> > matPow(vector< vector<ll> > A, ll p)
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
    ll n, t, sum = 0;
    cin >> n >> t;
    ll arr[n];
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    mat(2, 2, F);
    mat(2, 2, T);
    T[0][0] = n-2, T[0][1] = 1, T[1][0] = n-1, T[1][1] = 0;

    auto resMat = matPow(T, t);
    for (ll i = 0; i < n; ++i)
    {
        F[0][0] = (sum - arr[i]) % MOD, F[0][1] = arr[i], F[1][0] = 1, F[1][1] = 1;
        cout << ((matMul(F, resMat)[0][1] % MOD) + MOD) % MOD << endl;
    }
    return 0;
}

//OR THIS, It gives TLE though for higher values of N
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
    int n, t;
    cin >> n >> t;
    mat(n, 1, F);
    mat(n, n, T);
    for (int i = 0; i < n; ++i) cin >> F[i][0];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) T[i][j] = 0;
            else T[i][j] = 1;
        }
    }

    auto resMat = (matMul(matPow(T, t), F));
    for (int i = 0; i < n; ++i)
        cout << resMat[i][0] % MOD << endl;
    return 0;
}