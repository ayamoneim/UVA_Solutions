#include <stdio.h>
#include <stdlib.h>

long long input[1000001]={0};
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}


int main()
{
        int test_cases;
        scanf("%d",&test_cases);
        int cases=0;
        while(test_cases)
        {
        long long n;
        long long up;
        long long down=0;
        long long lcm=1;
        scanf("%lld",&n);
        cases++;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&input[i]);
            lcm*=input[i];
        }
        up=n*lcm;
        for(i=0;i<n;i++)
        {
            down+=lcm/input[i];
        }
        long long g=gcd(up,down);
        printf("Case %d: %lld/%lld\n",cases,up/g,down/g);
        test_cases--;
        }

    return 0;
}
