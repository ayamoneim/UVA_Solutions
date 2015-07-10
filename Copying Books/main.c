#include <stdio.h>
#include <stdlib.h>
int m,k;
int check(long target,long books[])
{
    long total=0;
    int required_scribers=1;
    int i;
    for(i=0;i<m;i++){
        if(books[i]>target)
        {
            return 0;
        }
    }

    for(i=0;i<m;i++)
    {
        if(total+books[i]>target)
        {
            required_scribers++;
            if(required_scribers>k)
                return 0;
            total=0;
        }
        total+=books[i];
    }
    return 1;
}


int main()
{
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        scanf("%d %d",&m,&k);
        long books[m];
        int i;
        long total_pages=0;
        for(i=0;i<m;i++)
        {
            scanf("%ld",&books[i]);
            total_pages+=books[i];
        }
        long hi=total_pages;
        long lo=0;
        while(lo<hi)
        {
            long mid=lo+(hi-lo)/2;
            if(check(mid,books))
            {
                hi=mid;
            }else
            {
                lo=mid+1;
            }
        }
        int boolean[m];
        long sum=0;
        int scripers=k-1;
        for(i=m-1;i>=0;i--)
        {
            if(i+1>scripers && sum+books[i]<=lo)
            {
                sum+=books[i];
                boolean[i]=0;
            }else
            {
                sum=books[i];
                boolean[i]=1;
                scripers--;
            }
        }
        for(i=0;i<m-1;i++)
        {
            printf("%ld ",books[i]);
            if(boolean[i])
            {
                printf("/ ");
            }

        }
        printf("%ld\n",books[i]);
        test_cases--;
    }
    return 0;
}
