#include <stdio.h>
#include <stdlib.h>

int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main()
{
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        long long input;
        scanf("%lld",&input);
        if(input<10 && input != 0)
        {
            printf("%lld\n",input);
        }else if(!input)
        {
            printf("10\n");
        }
        else
        {
        int output[10000]={0};
        int i;
        int index=0;
        for(i=9;i>=2;i--)
        {
            if(input%i==0)
            {
                output[index++]=i;
                input/=i;
                i=10;
            }
        }
        if(input==1)
        {
            qsort(output,index,sizeof(int),cmp);
            for(i=0;i<index-1;i++)
            {
                printf("%d",output[i]);
            }
            printf("%d\n",output[index-1]);
        }else
        {
            printf("-1\n");
        }
        }
        test_cases--;
    }

    return 0;
}
