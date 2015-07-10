#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n){
        char str[2000000]={'\0'};
        int i, flag = 0, r= -1, d= -1, distance = 1e9;
        for(i = 0; i < n; i++){
            scanf(" %c", &str[i]);
            if(str[i] == 'Z')   flag = 1;
            if(str[i] == 'R')   r = i;
            if(str[i] == 'D')    d = i;
            if(r >= 0 && d >= 0)   distance = abs(r-d)<distance?abs(r-d):distance;
        }
        printf("%d\n", flag?0:distance);
    }
    return 0;
}
        /*int distance=abs(strchr(str,'R')-strchr(str,'D'));
        char *pch=str;
        if(strchr(str,'R')>strchr(str,'D'))
        {
            ch='R';
            ptr=strchr(str,'R');
        }else
        {
            ch='D';
            ptr=strchr(str,'D');
        }
        int index=ptr-pch;*/
