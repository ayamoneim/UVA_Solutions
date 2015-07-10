#include <stdio.h>
#include <stdlib.h>

double f(double r,double t,int n,double players[n][2])
{
    double k = t-r;
    double myTime = r/players[n-1][0] + k/players[n-1][1];
    double theirTime = 10000000;
    int i;
    for(i=0;i<n-1;i++)
    {
        if(r/players[i][0] + k/players[i][1] < theirTime)
        {
            theirTime = r/players[i][0] + k/players[i][1];
        }
    }

    return theirTime - myTime;

}


int main()
{
    double t;
    while(scanf("%lf",&t)==1)
    {
        int n;
        scanf("%d",&n);
        int i;
        double players[n][2];
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&players[i][0],&players[i][1]);

        }

        double left = 0;
        double right = t;

        for(i=0;i<200;i++)
        {
            double m1 = left+(right-left)/3;
            double m2 = left+2*(right-left)/3;

            if(f(m1,t,n,players)>f(m2,t,n,players))
            {
                right = m2;
            }
            else
            {
                left = m1;
            }
        }
        if(f(left,t,n,players)<0.0)
        {
            printf("The cheater cannot win.\n");
        }else
        {
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n",f(left,t,n,players)*3600,left,t-left);
        }

    }
    return 0;
}
