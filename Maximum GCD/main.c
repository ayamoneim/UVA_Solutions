#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[101]={0};
int selected[2]={0};
int taken[101]={0};
int maximum=0;
int m=0;

void check(int test)
{
    if(test>maximum)
    {
        maximum=test;
    }
}

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }else
    {
        return gcd(b,a%b);
    }
}

void permutations(int index,int last)
{
    if(index==2)
    {
        int a=selected[0];
        int b=selected[1];
        int checkme=gcd(a,b);
        check(checkme);
        return;
    }
    int i;
    for(i=last;i<m;i++)
    {
        if(!taken[i])
        {
            selected[index]=arr[i];
            taken[i]=1;
            permutations(index+1,i+1);
            taken[i]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n)
    {
    int i=0;
    char str[101]={'\0'};
    gets(str);
    char *pch;
    pch=strtok(str," ");
    while(pch!=NULL)
    {
        arr[i]=atoi(pch);
        i++;
        pch=strtok(NULL," ");
    }
    m=i;
    permutations(0,0);
    printf("%d\n",maximum);
    maximum=0;
    n--;
    }
    return 0;
}
