//https://www.spoj.com/problems/PRATA/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, p, l, r[100], sol[100], vals[100], ind[100], counter, temp1, temp2;
int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &p);
        scanf("%lld", &l);
        for (int i = 0; i < l; ++i)
        {
            scanf("%lld", &r[i]);
            vals[i] = r[i];
        }

        if (l == 0 || p == 9)
        {
            printf("0\n");
            continue;
        }

        fill(sol, sol+100, 0);
        fill(ind, ind+100, 0);

        counter = 0, temp1 = 0, temp2 = 0;
        while (counter < p)
        {
            temp1 = vals[0], temp2 = 0;
            for (int i = 1; i < l; ++i)
            {
                if (vals[i] < temp1)
                {
                    temp1 = vals[i];
                    temp2 = i;
                }
            }
            ++ind[temp2];
            sol[temp2] = temp1;
            vals[temp2] = ((ind[temp2] + 1) * (ind[temp2] + 2) * r[temp2]) / 2;
            ++counter;
        }
        printf("%lld\n", *max_element(sol, sol+l));
    }
    return 0;
}