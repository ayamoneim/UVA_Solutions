#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        long long int g,l;
        scanf("%lld %lld",&g,&l);
        if(l%g==0)
        {
            printf("%lld %lld\n",g,l);
        }else
        {
            printf("-1\n");
        }
        test_cases--;
    }
    return 0;
}
