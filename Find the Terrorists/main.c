#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int boolean[100001]={0};
int primes[100000]={0};

int factors(int n)
{
    int index=0;
    int ans=1;
    int pf=primes[index++];
    while(n!=1 && pf*pf<=n)
    {
        int power=0;
        while(n%pf==0)
        {
            power++;
            n/=pf;
        }
        ans*=(power+1);
        pf=primes[index++];
    }
    if(n>1)
    {
        ans*=2;
    }
    return ans;
}

int main()
{
    int i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=100001;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=100001;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    int index=0;
    for(i=2;i<=100001;i++)
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
        int lo,hi;
        scanf("%d %d",&lo,&hi);
        int k,flag=0;
        int returnvalue;
        index=0;
        int printme[100000]={0};
        for(k=lo;k<=hi;k++)
        {
            returnvalue=factors(k);
           if(!boolean[returnvalue])
            {
                flag=1;
                printme[index++]=k;
            }
        }
        if(!flag){
            printf("-1");
        }else
        {
            for(i=0;i<index-1;i++)
            {
                printf("%d ",printme[i]);
            }
            printf("%d",printme[index-1]);
        }
        printf("\n");
        test_cases--;
    }
    return 0;
}
