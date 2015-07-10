#include <stdio.h>
#include <stdlib.h>


int s,t;
int taken[101]={0};
int selected[101]={0};
int cases=0;

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

int test_gcd(int index,int test)
{
    int i;
    for(i=0;i<index;i++)
    {
        if (gcd(selected[i],test)!=1)
        {
            return 0;
        }
    }
    return 1;
}
void output()
{
    int i;
    for(i=0;i<t-1;i++)
    {
        printf("%d ",selected[i]);
    }
    printf("%d\n",selected[t-1]);
}

void combinations(int index,int last,int sum)
{
    if(index==t && sum==0)
    {
        output();
        return;
    }
    if(index==t || sum==0)
    {
        return;
    }
    int i;
    for(i=last;i<=sum;i++)
    {
      if(index>0)
      {
            if( test_gcd(index,i)==1)
            {
                selected[index]=i;
                combinations(index+1,i,sum-i);
      }
      }else
      {
          selected[index]=i;
        combinations(index+1,i,sum-i);
      }
        }

}

int main() {
        int test_cases;
        scanf("%d",&test_cases);
        while(test_cases)
        {
            scanf("%d %d",&s,&t);
            cases++;
            printf("Case %d:\n",cases);
            combinations(0,1,s);
            test_cases--;
        }
        return 0;
}
