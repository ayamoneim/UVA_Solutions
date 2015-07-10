
//The Sultan's Successor


#include <stdio.h>

int rows[8]={0};
int visited_row[8]={0};
int pos_diagonal[17]={0};
int neg_diagonal[17]={0};
int board[92][8];
int solutions=0;
int num_board[8][8];


void queens(int row)
{
    if(row==8)
    {
        int k;
        for(k=0;k<8;k++)
        {
           board[solutions][k]=rows[k]+1;
        }
        return ;
    }else
    {
        int column;
        for(column=0;column<8;column++)
        {
            if(!visited_row[column] && !pos_diagonal[column+row] && !neg_diagonal[8-row+column])
            {
                rows[row]=column;
                visited_row[column]=1;
                pos_diagonal[column+row]=1;
                neg_diagonal[8+column-row]=1;
                queens(row+1);
                visited_row[column]=0;
                pos_diagonal[column+row]=0;
                neg_diagonal[8+column-row]=0;

            }
        }
    }
}

int main()
{
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        int i=0,j=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                scanf("%d",&num_board[i][j]);
            }
        }
        queens(0);
        
      
        
        int sum=0;
        int max_sum=0;
        for(i=0;i<solutions;i++)
        {
            for(j=0;j<8;j++)
            {
                sum+=num_board[j][board[i][j]-1];
            }
            if(sum>max_sum)
            {
                max_sum=sum;
                sum=0;
            }else
            {
                sum=0;
            }
        }
        printf("%5d\n",max_sum);
        solutions=0;
        for(i=0;i<8;i++)
        {
            rows[i]=0;
            visited_row[i]=0;
        }
        for(i=0;i<15;i++)
        {
            pos_diagonal[i]=0;
            neg_diagonal[i]=0;
        }
        test_cases--;
    }
    return 0;
}

//
