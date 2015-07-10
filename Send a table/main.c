#include <stdio.h>
#include <stdlib.h>


int boolean[55000]={0};
long long primes[55000]={0};
long long coprimes[55000]={0};

long long phi(long long n)
{
    int index=0;
    long long ans=n;
    long long pf=primes[index++];
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
    for(i=2;i*i<55000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<55000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }

    int index=0;
    for(i=2;i<55000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    coprimes[0]=1;
    long long global=1;
    for(i=1;i<50000;i++)
    {
        coprimes[i]=2*phi(i+1);
    }

    long long input;
    while(scanf("%lld",&input)==1 && input)
    {
        long long output=0;
        for(i=input-1;i>=0;i--)
        {
            output+=coprimes[i];
        }
        printf("%lld\n",output);
    }
    return 0;
}
