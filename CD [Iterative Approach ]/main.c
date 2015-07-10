#include <stdio.h>
#include <stdlib.h>
int n;
int counter=0;
int maximum=0;
int  total_tracks;
int maxtime=0;
int bestmask=0;
int maxcounter=0;

void mytape(int mask,int cd[])
{
    int i;
    for(i=0;i<total_tracks;i++)
    {
        if((mask & (1<<i))==1)
        {
            maxtime+=cd[i];
            counter++;
        }
    }
    if((maximum<maxtime && n>=maxtime )||(maximum==maxtime && n>=maxtime && counter>maxcounter))
    {
        maxcounter=counter;
        maximum=maxtime;
        bestmask=mask;
    }
    maxtime=0;
    counter=0;
}

void print(int cd[])
{
    int i;
    for(i=0;i<total_tracks;i++)
    {
        if(bestmask &(1<<i))
        {
            printf("%d ",cd[i]);
        }
    }
    printf("sum:%d\n",maximum);

}

void update(int cd[])
{
    int mask;
    for(mask=1;mask<(1<<total_tracks);mask++)
    {
        mytape(mask,cd);
    }
    print(cd);
}


int main()
{
    printf("%d",(7&(1<<2))?1:0);
    while(scanf("%d",&n)==1)
    {
        scanf(" %d",&total_tracks);
        int cd[20]={0};
        int i;
        for(i=0;i<total_tracks;i++)
        {
            scanf("%d",&cd[i]);
        }

        update(cd);
        maximum=0;
        bestmask=0;
        maxcounter=0;
    }
    return 0;
}
