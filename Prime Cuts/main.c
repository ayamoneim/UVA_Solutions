#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n,c;
    while(scanf("%d %d",&n,&c)==2)
    {
    printf("%d %d: ",n,c);
    int boolean[100000]={0};
    int primes[1000]={0};
    int i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=n;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=n;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    int index=1;
    primes[0]=1;
    for(i=2;i<=n;i++)
    {
        if(!boolean[i])
        {
            primes[index++]=i;
        }
    }
    if(index&1)
    {
        if(((c*2)-1)>=index)
        {
            for(i=0;i<index-1;i++)
            {
                printf("%d ",primes[i]);
            }
            printf("%d",primes[index-1]);
        }else
        {
            int counter=(c*2)-1;
            for(i=((index/2) +1)-((((c*2)-1)/2)+1);counter!=1;i++)
            {
                printf("%d ",primes[i]);
                counter--;
            }
            printf("%d",primes[i]);
        }
    }else
    {
        if(((c*2))>=index)
        {
            for(i=0;i<index-1;i++)
            {
                printf("%d ",primes[i]);
            }
            printf("%d",primes[index-1]);
        }else
        {
            int counter=c*2;
            for(i=(index/2) -c;counter!=1;i++)
            {
                printf("%d ",primes[i]);
                counter--;
            }
            printf("%d",primes[i]);
        }
    }
    printf("\n\n");
    }
    return 0;

}
