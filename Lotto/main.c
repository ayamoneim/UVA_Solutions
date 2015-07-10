


//lotto
//Combinations code ...Given a set of n elements you need to find all subsets of length k


#include <stdio.h>
#include <stdlib.h>
int k;
int s[14]={0};
int selected[6]={0};
int taken[14]={0};

void combinations(int index,int last)
{
    if(index==6)
    {
        int j;
        for(j=0;j<5;j++)
        {
            printf("%d ",selected[j]);
        }
        printf("%d\n",selected[5]);

        return;
    }
    int i;
    for(i=last;i<k;i++)
    {
        if(taken[i]==0)
        {
        selected[index]=s[i];
        taken[i]=1;
        combinations(index+1,i+1);
        taken[i]=0;
        }
    }

}
int main()
{
    int i,flag=0;
    while(scanf("%d",&k)==1 && k)
    {
        if(flag==0)
        {
            flag++;
        }else
        {
            puts("");
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",&s[i]);
        }

        combinations(0,0);
    }
    return 0;
}
