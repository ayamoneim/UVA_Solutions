#include <stdio.h>
#include <stdlib.h>

int boolean[10000001]={0};
long long primes[664580]={0};



int check(long long n,long long factorial)
{
    int counter=0;
    while(factorial)
    {
        counter+=factorial/n;
        factorial/=n;
    }
    return counter;
}

int factorize(long long n,long long factorial)
{
    int index=0;
    long long pf=primes[index++];
    while(n!=1 && pf*pf<=n)
    {
        int power=0;
        while(n%pf==0)
        {
            power++;
            n/=pf;
        }
        if(check(pf,factorial)<power)
        {
            return -1;
        }
        pf=primes[index++];
    }
    if(n>1)
    {
        if(check(n,factorial)<1)
        {
            return -1;
        }
    }
    return 0;
}


int main()
{
    long long i,j;
    boolean[0]=1;
    boolean[1]=1;


    for(i=2;i*i<=10000001;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=10000001;j+=i)
            {
                boolean[j]=1;
            }
        }
    }

    int index=0;
    for(i=2;i<=10000001;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }


    long long n,m;
    while(scanf("%lli %lli",&n,&m)==2)
    {
        if(m==0)
        {
            printf("%lli does not divide %lli!",m,n);
        }
        else
        {
            if(!factorize(m,n))
            {
                printf("%lli divides %lli!",m,n);
            }else
            {
                printf("%lli does not divide %lli!",m,n);
            }
        }
        printf("\n");

    }
    return 0;
}
