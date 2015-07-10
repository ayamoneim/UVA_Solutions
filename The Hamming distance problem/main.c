//Hamming Distance problem
//Generate a binary sequence with fixed number of ones and length n

#include <stdio.h>

int main()
{
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        int n,h;
        scanf("%d %d",&n,&h);
        int mask,j;
        for(mask=0;mask<(1<<n);mask++)
        {
            int ones=0;
            for(j=0;j<n;j++)
            {
                if(mask &(1<<j))
                {
                    ones++;
                }
            }
            if(ones==h)
            {
                for(j=n-1;j>=0;j--)
                {
                    if(mask&(1<<j))
                    {
                        printf("1");
                    }else
                    printf("0");
                }
                printf("\n");
            }
        }
        test_cases--;
        if(test_cases)
            printf("\n");
    }
    return 0;
}
