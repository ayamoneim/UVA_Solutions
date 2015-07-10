#include <stdio.h>
#include <stdlib.h>

int boolean[100000]={0};
long long primes[100000]={0};

int main()
{
    long long i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=100000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=100000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    long long index=0;
    for(i=2;i<=100000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    long long n;
    long long result;
    while(scanf("%lld",&n)==1 && n)
    {
        index=0;
        result=n;
        long long pf=primes[index++];
        while(n!=1 && pf*pf<=n)
        {
            if(n%pf==0)
            {
                result=result-(result/pf);
            }
            while(n%pf==0)
            {
                n/=pf;
            }
            pf=primes[index++];
        }
        if(n>1)
        {
            result=result-result/n;
        }
        printf("%lld\n",result);
    }

    return 0;
}
