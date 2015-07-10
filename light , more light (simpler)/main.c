#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long n;
    while(scanf("%lli",&n)==1 && n)
    {
        double x=sqrt(n);
        if(x == (long long) x)
        {
            printf("yes");
        }else
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
