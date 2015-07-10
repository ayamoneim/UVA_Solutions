#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int test,counter=1;
    scanf("%d",&test);
    while(test)
    {
    int i,k,x;
    scanf("%d",&k);
    x=sqrt(k);
    int arr[4]={0};
    int index=0;
    for(i=2;i<=x;i++)
    {
        if((k%i)==0)
        {
            arr[index++]=i;
            arr[index++]=k/i;
        }
        if(index==4)
        {
            break;
        }
    }
    printf("Case #%d: %d = %d * %d = %d * %d\n",counter,k,arr[0],arr[1],arr[2],arr[3]);
    counter++;
    test--;
    }
    return 0;
}
