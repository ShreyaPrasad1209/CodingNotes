//Recursive Sequence - Version II
//https://www.spoj.com/problems/SPP/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll base[16][16], X[16], MOD;
int d, n;

void mul(ll a[16][16], ll b[16][16])
{
	int i, j, k;
	ll r[16][16];
	for(i = 0; i < d; i++)
    {
		for(j = 0; j < d; j++)
        {
			r[i][j] = 0;
			for(k = 0; k < d; k++)
            {
				r[i][j] += a[i][k]*b[k][j];
				if(r[i][j] >= MOD) r[i][j] %= MOD;
			}
		}
	}
    memcpy(a, r, sizeof(r));
}

void pwr(ll r[16][16], ll e)
{
	ll b[16][16];
	for(int i = 0; i < d; i++)
    {
		for(int j = 0; j < d; j++)
        {
			r[i][j] = 0;
			b[i][j] = base[i][j];
		}
		r[i][i] = 1;
	}
	while(e > 0)
    {
		if(e & 1) mul(r, b);
		e >>= 1;
		mul(b, b);
	}
}

ll sum(ll x)
{
	ll ret = 0;
	if(x <= n)
    {
		for(int i = 1; i <= x; i++)
        {
			ret += X[n-i];
			if(ret >= MOD) ret %= MOD;
		}
	}
	else
    {
		ll r[16][16];
		pwr(r, x-n);
		for(int i = 0; i < d; i++)
        {
			ret += r[n][i] * X[i];
			if(ret >= MOD) ret %= MOD;
		}
	}
	return ret;
}

int main()
{
	int test, i;
	ll a, b, tot;
	scanf("%d", &test);
	while(test--)
    {
		scanf("%d", &n);
		d = n + 1;
		
		X[n] = 0;
		for(i = n - 1; i >= 0; i--)
        {
			scanf("%lld", &X[i]);
			X[n] += X[i];
		}
		
        memset(base, 0, sizeof(base));
		for(i = 1; i < n; i++) base[i][i-1] = 1;
		for(i = 0; i < n; i++)
        {
			scanf("%lld", &base[0][i]);
			base[n][i] = base[0][i];
		}
		base[n][n] = 1;
		
		scanf("%lld%lld%lld", &a, &b, &MOD);
		tot = ( sum(b) - sum(a - 1) ) % MOD;
		if(tot < 0) tot += MOD;
		printf("%lld\n", tot);
	}
	return 0;
}