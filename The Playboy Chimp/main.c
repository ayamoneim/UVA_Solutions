#include <stdio.h>
#include <stdlib.h>

long after(int target,int chimps[],long length)
{
    long lo=0;
    long hi=length-1;
    while (lo<hi)
    {
        long mid=lo+(hi-lo+1)/2;
        if(target<chimps[mid])
        {
            hi=mid-1;
        }else if(target>chimps[mid])
        {
            lo=mid+1;
        }else
        {
            lo=mid;
        }
    }
    return lo;
}

int before(long target,int chimps[],long length)
{
    int lo=0;
    int hi=length-1;
    while (lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if(target<chimps[mid])
        {
            hi=mid-1;
        }else if(target>chimps[mid])
        {
            lo=mid+1;
        }else
        {
            hi=mid;
        }
    }
    return lo;
}

int binarysearch(long target,int chimps[],long length)
{
    long lo=0;
    long hi=length-1;
    while(lo<=hi)
    {
        long mid=lo+(hi-lo)/2;
        if(target==chimps[mid])
        {
            return 1;
        }else if( target<chimps[mid])
        {
            hi=mid-1;
        }else if(target>chimps[mid])
        {
            lo=mid+1;
        }
    }
    return 0;
}
int biggerme(long target,int chimps[],long length)
{
    int lo=0;
    int hi=length-1;
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if(target>=chimps[mid])
        {
            lo=mid+1;
        }else
        {
            hi=mid;
        }
    }
    return lo;
}

int main()
{
    long n;
    scanf("%ld",&n);
    long i;
    int chimps[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&chimps[i]);
    }
    long q;
    scanf("%ld",&q);
    int queries[q];
    for(i=0;i<q;i++)
    {
        scanf("%d",&queries[i]);
        if(!binarysearch(queries[i],chimps,n))
        {
            int index=biggerme(queries[i],chimps,n);
            if(index==n-1 && queries[i]>chimps[n-1])
            {
                printf("%d X",chimps[n-1]);
            }else if(index==0 && queries[i]<chimps[0])
            {
                printf("X %d",chimps[0]);
            }else if(index>0 && index <=n-1)
            {
                printf("%d %d",chimps[index-1],chimps[index]);
            }else
            {
                printf("X X");
            }
        }else
        {
            int first=before(queries[i],chimps,n);
            int last=after(queries[i],chimps,n);
            if(first>0)
            {
                printf("%d ",chimps[first-1]);
            }else
            {
                printf("X ");
            }
            if(last<n-1)
            {
                printf("%d",chimps[last+1]);
            }else
            {
                printf("X");
            }
        }
        printf("\n");
    }

    return 0;
}
