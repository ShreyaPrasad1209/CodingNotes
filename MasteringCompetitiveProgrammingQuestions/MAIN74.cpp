//Euclids algorithm revisited - page 89
//https://www.spoj.com/problems/MAIN74/
#include<stdio.h>

long long MAX=1000000007;
 
void multiply(long long F[2][2],long long M[2][2]);
void power(long long F[2][2],long long n);
long long fib(long long n);
 
long long fib(long long n)
{
    long long F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(F,n-1);
    return F[0][0];
}
 
void multiply(long long F[2][2],long long M[2][2])
{
 
    long long x = ((F[0][0]*M[0][0])%MAX + (F[0][1]*M[1][0])%MAX)%MAX;
    long long y =  ((F[0][0]*M[0][1])%MAX + (F[0][1]*M[1][1])%MAX)%MAX;
    long long z =  ((F[1][0]*M[0][0])%MAX + (F[1][1]*M[1][0])%MAX)%MAX;
    long long w =  ((F[1][0]*M[0][1])%MAX + (F[1][1]*M[1][1])%MAX)%MAX;
 
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
 
}
 
void power(long long F[2][2], long long n)
{
    if( n == 0 || n == 1)
        return;
    long long M[2][2] = {{1,1},{1,0}};
 
    power(F, n/2);
    multiply(F, F);
 
    if( n&1)
    multiply(F, M);
}
 
int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n==0)printf("0\n");
        else if(n==1)printf("2\n");
        else printf("%lld\n",(fib(n+3))%MAX);
    }
 
    return 0;
} 