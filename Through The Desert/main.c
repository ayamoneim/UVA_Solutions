#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length;
int start=1;
int i;
int check(double mid,int events[length][3])
{
    double tank=mid;
    int consumption=events[start-1][2];
    int leaks=0;
    int km=0;
    for(i=start;i<length;i++)
    {
        mid=mid-leaks*(events[i][1]-km)-(events[i][1]-km)/100.00*consumption;
        if(events[i][0]==1)
        {
            consumption=events[i][2];
        }else if(events[i][0]==2)
        {
            leaks++;
        }else if(events[i][0]==4)
        {
            leaks=0;
        }else if(events[i][0]==3 && mid>=0)
        {
            mid=tank;
        }else if(events[i][0]==5)
        {
            break;
        }
        km=events[i][1];
    }
        if(mid<0)
        {
            return 0;
        }else
        {
            return 1;
        }
}

int main()
{
    int events[55][3];
    char test[50]={'\0'};
    int z=0;
    while(gets(test))
    {

        char temp1[20]={'\0'};
        char temp2[20]={'\0'};
        int count_input=sscanf(test,"%d %s %s %d",&events[z][1],temp1,temp2,&events[z][2]);
        if(count_input!=4 && temp1[0]=='L')
        {
            events[z][0]=2;
        }else if(count_input==3 && temp1[0]=='G')
        {
            events[z][0]=3;
        }else if(count_input==2 && temp1[0]=='M')
        {
            events[z][0]=4;
        }else if(count_input==2 && temp1[0]=='G')
        {
            events[z][0]=5;
            length=z+1;
        int x;
        double lo=0;
        double hi=100000;
        for(x=0;x<300;x++)
        {
            double mid=(lo+hi)/2;
            if(check(mid,events))
            {
                hi=mid;
            }else
            {
                lo=mid;
            }
        }
        printf("%.3lf\n",lo);
        z=-1;
        }else if(count_input==4 &&events[z][1]!=0 && events[z][2]!=0)
        {
            events[z][0]=1;
        }else if(count_input==4 && events[z][1]==0 && events[z][2]==0)
        {
            break;
        }
        z++;
    }
    return 0;
}
