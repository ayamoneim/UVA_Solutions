#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char str[3000+10]={'\0'};
    scanf("%d",&n);
    getchar();
    gets(str);
    int i=0;
    char ch=str[0];
    int counter=0;
    int index=-1;
    int l=-1;
    int last=n-1;
    while(n--)
    {
        if(str[i]=='R')
        {
            if(ch=='L' && l!=-1 || ch=='.')
            {
                counter+=(i-l-1);
            }
            l=-1;
            ch='R';
            index=i;
            if(ch=='.')
            {
                counter+=(i);
            }

        }
        if(str[i]=='L')
        {
        if(ch=='R' && index!=-1)
        {
            if((index-i-1)%2 !=0)
            {
                counter++;
            }
        }
        ch='L';
        index=-1;
        l=i;
        }

        i++;
    }
    if(ch=='L')
    {
        counter+=(last-l);
    }
    if(ch=='.')
    {
        counter+=(i);
    }
    printf("%d",counter);
    return 0;
}
