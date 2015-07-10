#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int access_points,houses;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int check(double coverage,int homes[])
{
    int i;
    int required=1;
    double distance=homes[0]+coverage;
    for(i=0;i<houses;i++)
    {
        if(fabs(distance-homes[i])>coverage)
        {
            required++;
            if(required>access_points)
                return 0;
            distance=homes[i]+coverage;
        }
    }
    return 1;
}



int main()
{
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        scanf("%d %d",&access_points,&houses);
        int house[houses];
        int i;
        for(i=0;i<houses;i++)
        {
            scanf("%d",&house[i]);
        }
        qsort (house, houses, sizeof(int), compare);
        double lo=0.0;
        double hi=1000000;
        for(i=0;i<300;i++)
        {
            double mid=(hi+lo)/2.0;
            if(check(mid,house))
            {
                hi=mid;
            }else
            {
                lo=mid;
            }
        }
        printf("%.1lf\n",lo);
        test_cases--;

    }
    return 0;
}
