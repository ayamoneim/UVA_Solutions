#include <stdio.h>
#include <stdlib.h>
int n;
int marbles[100000][2];

int binarysearch(int target)
{
    int lo=0;
    int hi=n-1;
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if (target>marbles[mid][1])
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
    int q,cases=1;
    scanf("%d %d",&n,&q);
    while(n && q)
    {
        int i;
        for(i=0;i<n;i++)
        {
            marbles[i][0]=i;
            scanf("%d",&marbles[i][1]);
        }
        int flag=0,j;
        for(i=0;flag==0;i++)
        {
            flag=-1;
            for(j=1;j<n-i;j++)
            {
                if(marbles[j][1]<marbles[j-1][1])
                {
                    int temp=marbles[j][1];
                    marbles[j][1]=marbles[j-1][1];
                    marbles[j-1][1]=temp;
                    temp=marbles[j][0];
                    marbles[j][0]=marbles[j-1][0];
                    marbles[j-1][0]=temp;
                    flag=0;
                }
            }
        }
        int query[q];
        printf("CASE# %d:\n",cases);
        for(i=0;i<q;i++)
        {
            scanf("%d",&query[i]);
            int printme=binarysearch(query[i]);
            if(marbles[printme][1]==query[i])
            {
                printf("%d found at %d",query[i],printme+1);
            }else
            {
                printf("%d not found",query[i]);
            }
            if(i<q)
            {
                printf("\n");
            }
        }
        scanf("%d %d",&n,&q);
        cases++;
    }
    return 0;
}
