#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int predicate(double c,double x,double y,double z)
{
    if((c*1.0/sqrt(pow(x,2.0)-pow(z,2.0))) + (c/sqrt(pow(y,2.0)-pow(z,2.0)))-1<=0.0000001f)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main()
{
    double x,y,c;
    while(scanf("%lf%lf%lf",&x,&y,&c)==3)
    {
        double lo = 0.0;
        double hi = 1000000000;
        int i;
        for(i=0; i<200; i++)
        {

            double mid = lo + (hi-lo)/2;
            if(predicate(c,x,y,mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        printf("%.3lf\n",lo);


    }
    return 0;
}
