#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int boolean[10000000];
long long int primes[10000000];

int main()
{
    long long i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=10000000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=10000000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    long long int index=0;
    for(i=2;i<=10000000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    long long int n;
    while(scanf("%lli",&n)==1 && n)
    {
        long long int pos=fabs(n);
        long long int index=0;
        long long int pf=primes[index++];
        long long int lpd=0;
        int counter=0;
        while(pos!=1 && pf*pf<=pos)
        {
            if(pos%pf==0)
            {
                counter++;
                lpd=pf;
            }
            while(pos%pf==0)
            {
                pos/=pf;
            }
            pf=primes[index++];
        }
        if(pos>1)
        {
            counter++;
            lpd=pos;
        }
        if(counter>1)
        {
            printf("%lli",lpd);
        }else
        {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}
