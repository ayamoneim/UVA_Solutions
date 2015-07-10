#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int taken[1000000];
int selected[20];
int maxi = INT_MIN;
int arr[20];
int save;
int sum = 0;
void combinations(int index,int last,int n,int len,int tracks[],int target)
{

    if(index == n)
    {
        int j;
        sum=0;
        for(j = 0;j<n;j++)
        {

            sum+=selected[j];
        }

        if(sum>maxi && sum <=target)
        {

            maxi = sum;
            save = n;
            for(j= 0;j<n;j++)
            {

                arr[j] = selected[j];
            }

        }
      return;
    }

    int i;
    for(i=last;i<len;i++)
    {
        if(!taken[i])
        {

            selected[index] = tracks[i];
            taken[i] = 1;
            combinations(index+1,i+1,n,len,tracks,target);
            taken[i]  =0;
        }
    }


}
int main()
{

   int n,length;
   scanf("%d%d",&n,&length);
   while(n&& length)
   {
   int tracks[length];
   int i;
   for(i= 0;i<length;i++)
    scanf("%d",&tracks[i]);
   for(i=1;i<length;i++)
    combinations(0,0,i,length,tracks,n);
   for(i = 0;i<save;i++)
   {

       printf("%d ",arr[i]);
   }
   printf("sum:%d\n",maxi);
   maxi = INT_MIN;
   sum = 0;
      scanf("%d%d",&n,&length);
   }
    return 0;
}
