#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int compare (const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}

int main()
{
    int t,n;

    while(scanf("%d%d",&t,&n) && n)
    {
        int arr[100]= {0};
        int i;

        for(i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }

        int c,d;

        int len[1000]= {0};

        int output[1000][100];

        long long mask;
        int row = 0;
        for(mask = 0; mask<((long long)(1<<n)); mask++)
        {
            int sum = 0;
            int col = 0;
            for(i=0; i<n; i++)
            {

                if(mask &(1<<i))
                {


                    sum+=(arr[i]);
                    output[row][col++] = arr[i];

                }

            }
            if(sum==t)
            {

                len[row++] = col;
            }

        }

        int j;
        c=0;
        for(j=0; j<12; j++)
        {
            for (c = 0 ; c < ( row - 1 ); c++)
            {
                for (d = 0 ; d < row - c - 1; d++)
                {
                    if(j<len[d] || (d+1<row && j<len[d+1] )){

                        if(j>0 && output[d][j] < output[d+1][j] )
                        {
                            for(i=0; i<=j-1; i++)
                            {
                                if(output[d][i] != output[d+1][i])
                                    break;
                            }
                            if(i>j-1)
                            {
                            for(i=0; i<len[d] || i<len[d+1]; i++)
                            {
                                int temp = output[d][i];
                                output[d][i] = output[d+1][i];
                                output[d+1][i] = temp;

                            }

                            int temp = len[d];
                            len[d] = len[d+1];
                            len[d+1] = temp;
                            }

                        }else if(j==0 && output[d][0] < output[d+1][0])
                        {
                            for(i=0; i<len[d] || i<len[d+1]; i++)
                            {
                                int temp = output[d][i];
                                output[d][i] = output[d+1][i];
                                output[d+1][i] = temp;

                            }

                            int temp = len[d];
                            len[d] = len[d+1];
                            len[d+1] = temp;
                        }
                    }
                }



            }

        }
        int taken[1000]= {0} ;
        for(c=0; c+1<row; c++)
        {

            for(d=0; d<len[c]; d++)
            {

                if(output[c][d]!=output[c+1][d])
                    break;
            }
            if(d==len[c])
            {
                taken[c] = 1;
            }
        }
        printf("Sums of %d:\n",t);
        if(row==0)
        {
            printf("NONE\n");
        }
        else
        {


            for(c=0; c<row; c++)
            {
                if(!taken[c])
                {
                    for(d=0; d<len[c]; d++)
                    {

                        printf("%d",output[c][d]);
                        if(len[c]-1!=d)
                        {
                            printf("+");
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
