#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int boolean[10000]={0};
int primes[10000]={0};
int printme=INT_MAX;
int flag=0;


void checker(int power_m,int power_n)
{
    if(!flag)
    {
        if((power_n/power_m)<printme)
        {
            printme=(power_n/power_m);
        }
    }
}

void fact(int factor_m,int power_m,int factorial)
{
    int power_n=0;
    while(factorial)
    {
        power_n+=factorial/factor_m;
        factorial=factorial/factor_m;
    }
    if(power_m>power_n)
    {
        flag=1;
    }else
    {
        checker(power_m,power_n);
    }
}



void factorize(int n,int factorial)
{
    int index=0;
    int pf=primes[index++];
    while(n!=1 && pf*pf<=n)
    {
        int power=0;
        while(n%pf==0)
        {
            power++;
            n/=pf;
        }
        if(power!=0)
        {
            fact(pf,power,factorial);
        }
        pf=primes[index++];

    }
    if(n>1)
    {
        fact(n,1,factorial);
    }
}

int main()
{
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

    int index=0;
    for(i=2;i<=10000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }


    int test_cases;
    scanf("%d",&test_cases);
    int cases=0;
    while(test_cases)
    {
        int n,m;
        scanf("%d %d",&m,&n);
        cases++;
        if(m==0)
        {
            printf("Case %d:\nImpossible to divide\n",cases);
        }else
        {
            factorize(m,n);
            if(!flag)
            {
                printf("Case %d:\n%d\n",cases,printme);
            }else
            {
                printf("Case %d:\nImpossible to divide\n",cases);
            }
        }
        printme=INT_MAX;
        flag=0;
        test_cases--;
    }
    return 0;
}
