#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2 && n && k)
    {
        float up = 0.0;
        float down = 0.0;
        int i;
        for(i=0;i<k;i++)
        {
            up+=log10(n*1.0);
            n--;
        }

        for(i=1;i<=k;i++)
        {

            down+=log10(i*1.0);
        }

        printf("%d\n",(int)(up-down+1));
    }
    return 0;
}
