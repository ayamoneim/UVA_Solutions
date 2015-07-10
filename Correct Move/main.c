#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,q,mov;
    while(scanf("%d %d %d",&k,&q,&mov)==3)
    {
        char chess[8][8];
        int x_mov,y_mov,x_k,y_k,x_q,y_q;
        y_k=k/8;
        x_k=k%8;
        y_mov=mov/8;
        x_mov=mov%8;
        y_q=q/8;
        x_q=q%8;
        int i,j;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                chess[i][j]='.';
            }
        }
        if(k==q)
        {
            printf("Illegal state\n");
        }else
        {
            chess[y_k][x_k]='k';
            if(y_k+1<8)
            {
                chess[y_k+1][x_k]='o';
            }
            if(y_k-1>0)
            {
                chess[y_k-1][x_k]='o';

            }
            if(x_k+1<8)
            {
                chess[x_k][x_k+1]='o';
            }
            if(x_k-1>0)
            {
                chess[y_k][x_k+1]='o';
            }
            chess[y_q][x_q]='q';
            for(i=y_q;chess[i][x_q]!='k'&& i>=0;i--)
            {
                if(chess[i][x_q]=='.')
                {
                    chess[i][x_q]='x';
                }else if(chess[i][x_q]=='o')
                {
                    chess[i][x_q]='$';

                }
            }
            for(i=y_q;chess[i][x_q]!='k'&& i<8;i++)
            {
                if(chess[i][x_q]=='.')
                {
                    chess[i][x_q]='x';
                }else if(chess[i][x_q]=='o')
                {
                    chess[i][x_q]='$';

                }
            }
            for(i=x_q;(chess[y_q][i]!='k')&& (i<8);i++)
            {
                if(chess[y_q][i]=='.')
                {
                    chess[y_q][i]='x';
                }else if(chess[y_q][i]=='o')
                {
                    chess[y_q][i]='$';

                }
            }
            for(i=x_q;chess[y_q][i]!='k'&& i>=0;i--)
            {
                if(chess[y_q][i]=='.')
                {
                    chess[y_q][i]='x';
                }else if(chess[y_q][i]=='o')
                {
                    chess[y_q][i]='$';

                }
            }
            if(chess[y_mov][x_mov]=='$')
            {
                printf("Move not allowed\n");
            }else if(chess[y_mov][x_mov]!='x')
            {
                printf("Illegal move\n");
            }else if(chess[y_mov][x_mov]=='x')
            {
            if((mov==49 && k==56) || (mov==54 && k==63) || (mov==14 && k==7 )||( mov==9 && k==0))
            {
                printf("Stop\n");
            }else
            {
                printf("Continue\n");
            }
            }
        }
    }
    return 0;
}
