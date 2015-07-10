#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,y1,x2,y2;
    while (1)
        {
             scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1==0 && y1==0 && y2==0 && x2==0)
            {
                break;
            }else
            {
            if(x1==x2 && y2==y1)
               {
                   printf("0\n");
               }else
               {
                   printf("%d\n",(abs(x1-x2)==abs(y1-y2) || (x1==x2 &&y1!=y2) || (y1==y2 && x1!=x2))?1:2);
               }
            }

        }
    return 0;
}
