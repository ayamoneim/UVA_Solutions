#include <stdio.h>
#include <stdlib.h>

int boolean[1000000]={0};
long long primes[1000000]={0};


long long phi(long long n)
{
    int index=0;
    long long pf=primes[index++];
    long long ans=n;
    while(n!=1 && pf*pf<=n)
    {
        if(n%pf==0)
        {
            ans=ans-(ans/pf);

        }
        while(n%pf==0)
        {
            n/=pf;
        }
        pf=primes[index++];
    }
    if(n>1)
    {
        ans=ans-(ans/n);
    }
    return ans;
}
int main()
{
    long long i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=1000000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=1000000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    int index=0;
    for(i=2;i<=1000000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    long long n;
    while(scanf("%lld",&n)==1 && n)
    {
        if(n==1)
        {
            printf("0\n");
        }else
        {
        printf("%lld\n",phi(n));
        }
    }
    return 0;
}
