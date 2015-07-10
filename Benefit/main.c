#include <stdio.h>
#include <stdlib.h>


int gcd(long long int a,long long int b)
{
    if(b==0)
    {
        return a;
    }else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    int test_cases;
    long long int a,c;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        scanf("%lld %lld",&a,&c);
        if(c%a)
        {
            printf("NO SOLUTION\n");
        }else
        {
            long long int i;
            for(i=c/a;i<=10000000;i+=c/a)
            {
                if(c==(a/gcd(a,i))*i)
                {
                    printf("%lld\n",i);
                    break;
                }
            }
        }
        test_cases--;
    }
    return 0;
}
