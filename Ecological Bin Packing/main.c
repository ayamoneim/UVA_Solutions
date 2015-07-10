#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char selected[3]={'\0'};
char bins[3]={'B','C','G'};
int taken[3]={0};
int minmoves=INT_MAX;
int counter;
int k=0;
char visited[7][4];
int green[3]={0};
int white[3]={0};
int brown[3]={0};

void solve_compare()
{
    int moves=0;
    if(selected[0]=='B')
    {
        moves+=brown[1]+brown[2];
    }
    else if(selected[0]=='C')
    {
        moves+=white[1]+white[2];
    }
    else if(selected[0]=='G')
    {
        moves+=green[1]+green[2];
    }
    if(selected[1]=='B')
    {
        moves+=brown[0]+brown[2];

    }
    else if(selected[1]=='C')
    {
        moves+=white[0]+white[2];
    }
    else if(selected[1]=='G')
    {
        moves+=green[0]+green[2];
    }
    if(selected[2]=='B')
    {
        moves+=brown[0]+brown[1];
    }
    else if(selected[2]=='C')
    {
        moves+=white[0]+white[1];

    }
    else if(selected[2]=='G')
    {
        moves+=green[0]+green[1];
    }
    if(moves<minmoves)
    {
        minmoves=moves;
        counter=k;
    }

}

void permutations(int index)
{
    if(index==3)
    {
        strcpy(visited[k],selected);
        k++;
        solve_compare();
        return;
    }
    int i;
    for(i=0;i<3;i++)
    {
        if(!taken[i])
        {
            selected[index]=bins[i];
            taken[i]=1;
            permutations(index+1);
            taken[i]=0;
        }
    }
}

int main()
{
    while(scanf("%d %d %d %d %d %d %d %d %d",&brown[0],&green[0],&white[0],&brown[1],&green[1],&white[1],&brown[2],&green[2],&white[2])==9)
    {
        permutations(0);
        printf("%s %d\n",visited[counter-1],minmoves);
        minmoves=INT_MAX;
        k=0;
    }
    return 0;
}
