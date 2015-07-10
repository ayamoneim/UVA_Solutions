#include <stdio.h>
#include <stdlib.h>

int main()
{
int sum,n;
while(scanf("%d",&n)==1)
{
    sum=n;
    while(n>=3)
    {
    sum=sum+(n/3);
    n=(n/3)+(n%3);
    }
    if(n==2)
    {
        sum++;
    }
    printf("%d\n",sum);
}
return 0;
}
/*
sum=n+n/2;*/
