

//23 out of 5


#include <stdio.h>
#include <stdlib.h>

char operators[3]={'+','-','*'};
long int tuple_5[5]={0};
long int selected[5]={0};
int taken[5]={0};
int flag=-1;
int i,j,k,l;



void solve_compare()
{
    long int result;
    if(operators[l]=='+')
    {
        result=selected[0]+selected[1];
    }else if(operators[l]=='-')
    {
        result=selected[0]-selected[1];
    }
    else if(operators[l]=='*')
    {
        result=selected[0]*selected[1];
    }
    if(operators[i]=='+')
    {
        result=result+selected[2];
    }else if(operators[i]=='-')
    {
        result-=selected[2];
    }else if(operators[i]=='*')
    {
        result*=selected[2];
    }
    if(operators[j]=='+')
    {
        result+=selected[3];
    }else if(operators[j]=='-')
    {
        result-=selected[3];
    }else if(operators[j]=='*')
    {
        result*=selected[3];
    }
    if(operators[k]=='+')
    {
        result+=selected[4];
    }else if(operators[k]=='-')
    {
        result-=selected[4];
    }else if(operators[k]=='*')
    {
        result*=selected[4];
    }
    if(result==23)
    {
        flag=0;
    }
}


void permutations(int index)
{
    if(index==5)
    {
    for(l=0;l<3 ;l++)
        {
            for(i=0;i<3 ;i++)
            {
                for(j=0;j<3 ;j++)
                {
                    for(k=0;k<3 && flag!=0 ;k++)
                    {
                        solve_compare();
                    }
                }
            }
        }
        return;
    }else if(flag==-1){
    int a;
    for(a=0;a<5;a++)
    {
        if(!taken[a])
        {
            if(a>0 && tuple_5[a]==tuple_5[a-1] && !taken[a-1])
            {
                continue;
            }
            else
            {
                selected[index]=tuple_5[a];
                taken[a]=1;
                permutations(index+1);
                taken[a]=0;
            }
        }
    }
    }else if(flag==0)
    {
        return;
    }
}


int main()
{
    scanf("%ld %ld %ld %ld %ld",&tuple_5[0],&tuple_5[1],&tuple_5[2],&tuple_5[3],&tuple_5[4]);
    while(!(tuple_5[0]==0 && tuple_5[1]==0 && tuple_5[2]==0 && tuple_5[3]==0 && tuple_5[4]==0) )
    {
        permutations(0);
        if(flag==0)
        {
            printf("Possible\n");
        }else
        {
            printf("Impossible\n");
        }
        flag=-1;
        scanf("%ld %ld %ld %ld %ld",&tuple_5[0],&tuple_5[1],&tuple_5[2],&tuple_5[3],&tuple_5[4]);
    }
    return 0;
}

