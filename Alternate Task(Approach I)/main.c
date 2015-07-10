#include <stdio.h>
#include <stdlib.h>

int boolean[10000]={0};
int primes[10000]={0};
long long factors_sum[1002]={0};

long long powfn(int base,int power)
{
    if(power==0)
    {
        return 1;
    }
    if(power&1)
    {
        return base *powfn(base,power-1);

    }
    long long res=powfn(base,power/2);
    return res*res;
}



long long summition(long long n)
{
    int index=0;
    long long sum=1;
    int pf=primes[index++];
    while(n!=1 && pf*pf<=n)
    {
        int power=0;
        while(n%pf==0)
        {
            n/=pf;
            power++;
        }
        sum*=((powfn(pf,power+1)-1)/(pf-1));
        pf=primes[index++];
    }
    if(n>1)
    {
        sum*=(n+1);
    }
    return sum;
}


int main()
{
    int index=0;
    int i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=10000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=10000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    for(i=2;i<=10000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    factors_sum[0]=0;
    factors_sum[1]=1;
    long long  k;
    for(k=2;k<1001;k++)
    {
        long long sum=summition(k);
        if(sum<1001)
        {
            factors_sum[sum]=k;
        }
    }
    int s,cases=1;
    while(scanf("%d",&s)==1 && s)
    {
        if(factors_sum[s])
            printf("Case %d: %lld\n",cases,factors_sum[s]);
        else
            printf("Case %d: -1\n",cases);
        cases++;

    }
    return 0;
}
