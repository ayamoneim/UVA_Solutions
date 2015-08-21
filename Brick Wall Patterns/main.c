#include <stdio.h>
#include <stdlib.h>
long long table[51]={0};
long long brickWall(int n)
{

    if(n<0)
    {
        return 0;
    }else if(n==0)
    {

        return 1;
    }else if(table[n]!=0)
    {
        return table[n];
    }

    return (table[n] = brickWall(n-1)+brickWall(n-2));
}

int main()
{
    int n;

    while(scanf("%d",&n) && n){
        printf("%lld\n",brickWall(n));

    }
    return 0;
}
