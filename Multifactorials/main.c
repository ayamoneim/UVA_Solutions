#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int boolean[10000];
int primes[10000];

void multifact(int n,int arr[],int k)
{
    while(n>0)
    {
        int step_n=n;
        int index=0;
        int pf=primes[index++];
        while(step_n!=1 && pf*pf<=step_n)
        {
            long long power=0;
            while(step_n%pf==0)
            {
                power++;
                step_n/=pf;
            }
            arr[pf]+=power;
            pf=primes[index++];
        }
        if(step_n>1)
        {
            arr[step_n]+=1;
        }
        n-=k;
    }
}



int main()
{
    int i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<10000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<10000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }


    int index=0;

    for(i=2;i<10000;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }


    int test_cases;
    int cases=0;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        int n;
        cases++;
        char temp[21]={'\0'};
        scanf("%d%s",&n,temp);
        int counter=strlen(temp);
        int factors[10001]={0};
        multifact(n,factors,counter);
        double output=1;//leh lama 2st5demt doubles mshyet?
        for(i=0;i<=1000;i++)
        {
            output*=(factors[i]+1.0);
        }
        if(output > 1e18)
        {
            printf("Case %d: Infinity\n",cases);

        }else
        {
            printf("Case %d: %.0lf\n",cases,output);
        }
        test_cases--;
    }
    return 0;
}
