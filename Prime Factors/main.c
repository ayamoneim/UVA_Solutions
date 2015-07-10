#include <stdio.h>
#include <stdlib.h>

int boolean[10000001]={0};
long long primes[10000001]={0};
long long factors[10000001]={0};
int main()
{
    long long g;
    long long i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i==10000001;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<10000001;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    long long index=0;
    for(i=2;i<10000001;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    while(scanf("%lld",&g)==1 && g)
    {
        if(g==1)
        {
            printf("1 = 1");
        }else if(g==-1)
        {
            printf("-1 = -1 * 1");
        }else{
        index=0;
        int counter;
        long long pf=primes[index++];
        long long n=llabs(g);
        counter=0;
        while(n!=1 && pf*pf<=n){
                while(n%pf==0)
                {
                    factors[counter++]=pf;
                    n/=pf;
                    factors[counter]=0;

                }
            pf=primes[index++];
            }
        if(n>1)
        {
            factors[counter]=n;
        }
        if(g<0)
        {
            printf("%lld = -1 ",g);
            for(i=0;i<=counter;i++)
            {
                if(factors[i]==0)
                {
                    break;
                }else
                {
                    printf("x %lld",factors[i]);
                if(i<=counter-1 && factors[i+1]!=0)
                    printf(" ");
                }
            }
        }else
        {
            printf("%lld = %lld",g,factors[0]);
            if(counter>0)
                printf(" ");
            for(i=1;i<=counter;i++)
            {
                if(factors[i]==0){
                    break;
                }else
                {
                    printf("x %lld",factors[i]);
                if(i<=counter-1 && factors[i+1]!=0)
                    printf(" ");
                }

            }
        }
        }
        printf("\n");
    }
    return 0;
}
