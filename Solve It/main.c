#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int p,q,r,s,u,t;

int predicate(double x)
{

    if((p*exp(-x)+q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2.0) + u)<0 )
    {
        return 1;
    }else
    {
        return 0;
    }
}


int main()
{

    while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6)
    {
    double lo = 0.0;
    double hi = 1.0;
    int i;
    for(i=0;i<200;i++)
    {
        double mid = (hi+lo)/2;
        if(!predicate(mid))
        {
            lo = mid;
        }else
        {
            hi = mid;
        }
    }
    if(fabs(p*exp(-lo)+ q*sin(lo) + r*cos(lo) + s*tan(lo) + t*pow(lo,2.0) + u)> 1e-10)
        printf("No solution\n");
    else
        printf("%.4lf\n",lo);
    }
    return 0;
}
