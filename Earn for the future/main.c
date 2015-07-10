#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,card,x=1;
    scanf("%d",&t);
    while(t)
    {
        int maximum=0;
        scanf("%d",&n);
        while(n)
        {
            scanf("%d",&card);
            if (card>maximum)
            {
                maximum=card;
            }
            n--;
        }
        printf("Case %d: %d\n",x,maximum);
        x++;
        t--;
    }
    return 0;
}
