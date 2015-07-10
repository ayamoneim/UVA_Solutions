#include <stdio.h>
#include <stdlib.h>

int n,l;
int g[200][200];
int color[1000];

int isBipartite(int i)
{
    int answer = 1;
    int j;
    for(j = 0; j<n; j++)
        if(g[i][j])
        {
            if(color[j]==color[i]){
                return 0;
            }
            else if(color[j]==0)
            {
                color[j]=3-color[i];
                if(answer && isBipartite(j)){
                    answer = 1;
                }
            }
        }
    return answer;
}
int bipartiteCheck()
{
    int i;

    for(i = 0; i<n; i++)
        if(color[i]==0)
        {
            color[i]=1;
            if(!isBipartite(i)) {
                return 0;
            }
        }
    return 1;
}
int main()
{

    while(scanf("%d",&n)==1 && n)
    {


        scanf("%d",&l);

        int i,j;
        for(i=0;i<200;i++)
        {
            for(j=0;j<200;j++)
            {
                g[i][j] = 0;
            }
            color[i] = 0;
        }
        for(i=0;i<l;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);

            g[x][y] = 1;
            g[y][x] = 1;
        }


    if(!bipartiteCheck())
    {
        printf("NOT BICOLORABLE.\n");
    }else
    {
        printf("BICOLORABLE.\n");
    }

    }
    return 0;
}
