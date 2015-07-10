#include <stdio.h>
#include <stdlib.h>
int m,n;
int check(long mycapacity,long vessels[])
{
    int i;
    long capacity=0;
    int containers=1;
    for(i=0;i<n;i++)
    {
        if(capacity+vessels[i]<=mycapacity)
        {
            capacity+=vessels[i];
        }else
        {
            capacity=vessels[i];
            containers++;
            if(vessels[i]>mycapacity || containers>m)
            {
                return 0;
            }

        }
    }

    return 1;

}

int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
    long vessels[n];
    int i;
    long sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&vessels[i]);
        sum+=vessels[i];
    }
    long lo=0;
    long hi=sum;
    while(lo<hi)
    {
        long mid=lo+(hi-lo)/2;
        if(check(mid,vessels))
        {
            hi=mid;
        }else
        {
            lo=mid+1;
        }
    }
    printf("%ld\n",lo);
    }
    return 0;
}
