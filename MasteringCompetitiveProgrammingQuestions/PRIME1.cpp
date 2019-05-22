//https://www.spoj.com/problems/PRIME1/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void segmentedSeive(ll m, ll n)
{
    ll range = n - m;
    vector<bool> is_prime(range + 1, true);

    for (ll prime : primes)
    {
        ll increment = prime + prime;
        ll start = max(((m + prime - 1) / prime) * prime, prime * prime);
        if ((start & 1) == 0)
            start += prime;
        start -= m;
        for (int i = start; i <= range; i += increment)
            is_prime[i] = false;
    }

    if (m <= 2 && n >= 2) printf("2\n");
    for (int k = (m & 1) ? 0 : 1; k <= range; k += 2)
    {
        if (is_prime[k])
            printf("%d\n", m + k);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    findPrimes(sqrt(1000000000));
    while (t--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        if (m == 1) m++;
        segmentedSeive(m, n);
        printf("\n");
    }
    return 0;
}