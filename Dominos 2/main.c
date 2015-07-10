#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int n;
int adj[100000][1000+10];
int visited[100000];
int len[100000];
void dfs(int i)
{
    visited[i] = 1;
    int j;
    for(j = 0; j<len[i]; j++)
    {
        int child = adj[i][j];
        if(!visited[child]){
            counter++;
            dfs(child);
        }
    }
}



int main()
{
    int t;

    scanf("%d",&t);
    while(t--)
    {
        int m,l;
        scanf("%d%d%d",&n,&m,&l);
        int i;


        for(i=0;i<n+5;i++){
            len[i] = 0;
            visited[i] = 0;
        }
        int j;
        for(i=0;i<n+5;i++)
        {
            for(j=0;j<n+5;j++)
            {
                adj[i][j] = 0;
            }
        }

        for(i=0;i<m;i++)
        {
            int from,to;
            scanf("%d%d",&from,&to);
            from--;
            to--;
            adj[from][len[from]] = to;
            len[from]++;

        }

        for(i=0;i<l;i++)
        {
            int fall ;
            scanf("%d",&fall);
            fall--;
            if(!visited[fall]){
                counter++;
            }
            dfs(fall);

        }

        printf("%d\n",counter);
        counter=0;

    }
    return 0;
}
