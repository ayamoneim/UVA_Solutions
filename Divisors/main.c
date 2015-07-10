#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int boolean[100000]={0};
int primes[100000]={0};
int max_divisors=0;
long long numofmax=0;

void check(int divisors,long long num)

{
    if(divisors>max_divisors)
    {
        max_divisors=divisors;
        numofmax=num;
    }
}


void numdivisors(long long n)
{
    long long x=n;
    int index=0;
    int pf=primes[index++];
    int res=1;
    while(n!=1 && pf*pf<=n)
    {
        int power=0;
        while(n%pf==0)
        {
            n/=pf;
            power++;
        }
        res*=(power+1);
        pf=primes[index++];
    }
    if(n>1)
    {
        res*=2;
    }
    check(res,x);
}
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
    int index=0;
    for(i=2;i<=100000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        long long lo,up;
        scanf("%lld %lld",&lo,&up);
        if((lo==0 && up==1)||(lo==0 && up==2)||(lo==0 && up==3))
        {
            printf("Between 0 and %lld, 0 has a maximum of 2 divisors.\n",up);
        }else{
        for(i=lo;i<=up;i++)
        {
            numdivisors(i);
        }
        printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n",lo,up,numofmax,max_divisors);
        }
        max_divisors=0;
        numofmax=0;
        test_cases--;
    }
    return 0;
}
