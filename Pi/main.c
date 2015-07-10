#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int scanned[50]={0};
int selected[2]={0};
int taken[50]={0};
int coprimes=0;
int pairs=0;
int n;


int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }else
    {
        return gcd(b,a%b);
    }
}

void permutations(int index,int last)
{
    if(index==2)
    {
        if(gcd(selected[1],selected[0])==1)
        {
            coprimes++;
        }
        pairs++;
        return;
    }
    int i;
    for(i=last;i<n;i++)
    {
        if(!taken[i])
        {
            selected[index]=scanned[i];
            taken[i]=1;
            permutations(index+1,i+1);
            taken[i]=0;
        }
    }
}
int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        coprimes=0;
        pairs=0;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&scanned[i]);

        }
        permutations(0,0);
        if(coprimes==0)
        {
            printf("No estimate for this data set.\n");
        }else{
        double ans=sqrt((double)(6*pairs)/(double)coprimes);
        printf("%.6lf\n",ans);
        }
    }

    return 0;
}
