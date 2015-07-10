#include <stdio.h>
#include <stdlib.h>

long long lookup[60][60];

long long barcode(int x,int y,int n,int k,int m)
{
    if(x==n && y==k){
        return 1;
    }
    if(x>=n || y>=k)
        return 0;

    if(lookup[x][y]!=-1){
        return lookup[x][y];
    }
    int i;
    long long ans = 0;
    for(i=1;i<=m;i++)
    {
         ans+=barcode(x+i,y+1,n,k,m);
         lookup[x][y] = ans;
    }
    return ans;
}

int main()
{
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)==3)
    {
        int i,j;
        for(i=0;i<60;i++){
            for(j=0;j<60;j++){
                lookup[i][j] = -1;
            }
        }

        printf("%lld\n",barcode(0,0,n,k,m));
    }
    return 0;
}
