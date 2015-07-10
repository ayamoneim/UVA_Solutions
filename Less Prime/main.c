#include <stdio.h>
#include <stdlib.h>

int boolean[10001]={0};


int main()
{
    int i,j;
    boolean[0]=1;
    boolean[1]=1;
    for(i=2;i<=10001;i++)
    {
        if(!boolean[i])
        {
            for(j=i*i;j<=10001;j+=i)
            {
                boolean[j]=1;

            }
        }
    }
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        int n;
        scanf("%d",&n);
        for(i=2;i<=n;i++)
        {
            if(!boolean[i])
            {
                if(2*i>n)
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
        test_cases--;
    }

    return 0;
}
