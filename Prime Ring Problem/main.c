#include <stdio.h>
#include <stdlib.h>

int n;
int boolean[1000]={0};
int selected[20]={0};
int taken[20]={0};
int cases=0;


void permutations(int index)
{
    if(index==n && !boolean[selected[0]+selected[n-1]])
    {
        int i;
        for(i=0;i<n-1;i++)
        {
            printf("%d ",selected[i]);
        }
        printf("%d",selected[n-1]);
        printf("\n");
        return;

    }
    int i;
    for(i=2;i<=n;i++)
    {
        if(!taken[i])
        {
            if(!boolean[selected[index-1]+i])
            {
                selected[index]=i;
                taken[i]=1;
                permutations(index+1);
                taken[i]=0;
            }
        }
    }
}

int main()
{
    int i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i*i<=1000;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=1000;j+=i)
            {
                boolean[j]=1;
            }
        }
    }
    selected[0]=1;
    while(scanf("%d",&n)==1 && n)
    {
        cases++;
        if(cases>1)
            printf("\n");
        printf("Case %d:\n",cases);
        permutations(1);
    }
    return 0;
}
