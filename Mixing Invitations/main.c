#include <stdio.h>
#include <stdlib.h>

long long fact[21];

long long dearrangement(int n)
{

    int i;
    long long ways = 0;
    int sign = 1;
    for(i=0;i<=n;i++)
    {
        ways+=sign*(fact[n]/(fact[n-i]*fact[i]))*fact[n-i];
        sign*=-1;

    }

    return ways;
}
int main()
{

    int n,guests;
    fact[0] = 1;
    fact[1] = 1;
    int j;
    for(j=2;j<=20;j++)
    {
        fact[j] = fact[j-1]*j;
    }

    while(scanf("%d%d",&n,&guests)==2)
    {
        int i;
        long long  res=0;
        for(i=guests;i>=0;i--)
        {
            res+=(fact[n]/(fact[n-i]*fact[i]))*dearrangement(n-i);

        }

        printf("%lld\n",res);

    }
    return 0;
}
