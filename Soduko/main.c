#include <stdio.h>
#include <stdlib.h>

int solved = 0;

int sq(int r,int c,int n)
{
    if(n==2)
    {
        if(r>=0 && r<=1 && c>=0 && c<=1)
        {
            return 1;
        }
        else if(r>=0 && r<=1 && c>=2 && c<=3)
        {
            return 2;
        }
        else if(r>=2 && r<=3 && c>=0 && c<=1)
        {
            return 3;
        }
        else if(r>=2 && r<=3 && c>=2 && c<=3)
        {
            return 4;
        }
    }
    else if(n==3)
    {
        if(r>=0 && r<=2 && c>=0 && c<=2)
        {
            return 1;
        }
        else if(r>=0 && r<=2 && c>=3 && c<=5)
        {
            return 2;
        }
        else if(r>=0 && r<=2 && c>=6 && c<=8)
        {

            return 3;
        }
        else if(r>=3 && r<=5 && c>=0 && c<=2)
        {
            return 4;
        }
        else if(r>=3 && r<=5 && c>=3 && c<=5)
        {

            return 5;
        }
        else if(r>=3 && r<=5 && c>=6 && c<=8)
        {

            return 6;
        }
        else if(r>=6 && r<=8 && c>=0 && c<=2)
        {
            return 7;


        }
        else if(r>=6 && r<=8 && c>=3 && c<=5)
        {

            return 8;

        }
        else if(r>=6 && r<=8 && c>=6 && c<=8)
        {

            return 9;
        }
    }
    return 0;
}
void sudoko(int board[10][10],int given[10][10],int taken[10][10],int square[10][10],int row[10][10],int column[10][10],int r,int c,int n)
{
    if(r==n*n )
    {
        int i,j;
        for(i=0; i<n*n; i++)
        {
            for(j=0; j<n*n-1; j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("%d\n",board[i][j]);
        }
        solved =1;
        return;
    }
    if(c==n*n)
    {
        sudoko( board,given,taken,square,row,column,r+1,0,n);
        return;
    }
    if(given[r][c])
    {
        sudoko( board,given,taken,square,row,column,r,c+1,n);
        return;
    }
    int num;
    for(num=1; num<=9 && !solved; num++)
    {
        if(!row[c][num] && !column[r][num] && (sq(r,c,n)!=0 && !square[sq(r,c,n)][num]) && !taken[r][c]&& !given[r][c])
        {
            taken[r][c] = 1;
            board[r][c] = num;
            row[c][num] = 1;
            column[r][num] = 1;
            square[sq(r,c,n)][num] = 1;
            sudoko( board,given,taken,square,row,column,r,c+1,n);
            if(solved)
                break;
            taken[r][c] = 0;
            row[c][num] = 0;
            column[r][num] = 0;
            square[sq(r,c,n)][num] = 0;

        }
    }






}

int main()
{
    int n;
    int cases=0;
    while(scanf("%d",&n)==1)
    {
        int i,j;
        if(cases>0)
            printf("\n");
        cases++;
        int given[10][10];
        int board[10][10];
        int taken[10][10];
        int square[10][10];
        int row[10][10];
        int column[10][10];
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)
            {

                square[i][j] = 0;
                row[i][j] = 0;
                column[i][j] = 0;
                board[i][j] = 0;
                taken[i][j] = 0;
                given[i][j] = 0;

            }
        }
        int done =0;
        for(i=0; i<n*n; i++)
        {

            for(j=0; j<n*n; j++)
            {

                scanf("%d",&board[i][j]);

                if(board[i][j]!=0)
                {
                    if(row[j][board[i][j]] || column[i][board[i][j]] )
                    {
                        done = 1;
                    }
                    given[i][j] = 1;
                    row[j][board[i][j]] = 1;
                    column[i][board[i][j]] = 1;
                    taken[i][j]=1;
                    if(square[sq(i,j,n)][board[i][j]])
                    {
                        done = 1;
                    }
                    else
                    {
                        square[sq(i,j,n)][board[i][j]] = 1;
                    }

                }

            }
        }
        if(n==1 && board[0][0]==0){
            printf("1\n");
        }else if(n==1 && board[0][0]!=0)
        {
            printf("%d\n",board[0][0]);
        }
        if(!done && n>1)
        {
            sudoko(board,given,taken,square,row,column,0,0,n);
        }
        if((solved==0 || done) && n>1)
        {
            printf("NO SOLUTION\n");
        }
        solved = 0;
    }

    return 0;
}
