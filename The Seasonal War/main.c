#include <stdio.h>
#include <stdlib.h>

void dfs(int dimension,char image[dimension][dimension],int visited[dimension][dimension],int i,int j)
{
    visited[i][j] = 1;

    if(i+1<dimension && j+1<dimension && !visited[i+1][j+1] && image[i+1][j+1]=='1')
    {
        dfs(dimension,image,visited,i+1,j+1);
    }
    if(i+1<dimension && !visited[i+1][j] && image[i+1][j]=='1')
    {
        dfs(dimension,image,visited,i+1,j);
    }
    if(i-1>=0 && !visited[i-1][j] && image[i-1][j]=='1')
    {
        dfs(dimension,image,visited,i-1,j);
    }
    if(j-1>=0 && !visited[i][j-1] && image[i][j-1]=='1')
    {
        dfs(dimension,image,visited,i,j-1);
    }
    if(j+1<dimension && !visited[i][j+1] && image[i][j+1]=='1')
    {
        dfs(dimension,image,visited,i,j+1);
    }
    if(i+1<dimension && j-1>=0 && !visited[i+1][j-1] && image[i+1][j-1]=='1')
    {
        dfs(dimension,image,visited,i+1,j-1);
    }
    if(i-1>=0 && j-1>=0 && !visited[i-1][j-1] && image[i-1][j-1]=='1')
    {0
        dfs(dimension,image,visited,i-1,j-1);
    }
    if(i-1>=0 && j+1<dimension && !visited[i-1][j+1] && image[i-1][j+1]=='1')
    {
        dfs(dimension,image,visited,i-1,j+1);
    }
}



int main()
{
    int dimension;
    int cases = 0;
    while(scanf("%d",&dimension)==1)
    {
        int i,j;
        cases++;
        char image[dimension][dimension];
        getchar();
        for(i=0;i<dimension;i++)
        {
            gets(image[i]);
        }


        int visited[dimension][dimension];
        for(i=0;i<dimension;i++)
        {
            for(j=0;j<dimension;j++)
            {
                visited[i][j] = 0;
            }
        }

        int counter = 0;
        for(i=0;i<dimension;i++)
        {
            for(j=0;j<dimension;j++)
            {

                if(image[i][j]=='1' && !visited[i][j])
                {
                    dfs(dimension,image,visited,i,j);
                    counter++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",cases,counter);
    }
    return 0;
}
