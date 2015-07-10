#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int rungs;
int check (int moves,int ladder[])
{
    int i;
    for(i=1;i<=rungs;i++)
    {
        if(ladder[i]-ladder[i-1]==moves)
        {
            moves--;
        }else if(ladder[i]-ladder[i-1]>moves)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int test_cases,cases=0;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        scanf("%d",&rungs);
        int i;
        int ladder[rungs+1];
        ladder[0]=0;
        for(i=1;i<=rungs;i++)
        {
            scanf("%d",&ladder[i]);
        }
        int lo=0;
        int hi=ladder[rungs];
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(mid,ladder))
            {
                hi=mid;

            }else
            {
                lo=mid+1;
            }
        }
        cases++;
        printf("Case %d: %d\n",cases,lo);
        test_cases--;
    }
    return 0;
}
