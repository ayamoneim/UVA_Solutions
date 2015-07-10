#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


void dfs2(int h,int w,char image[100][100],int dot[100][100],int i,int j)
{
    dot[i][j] = 1;
    if(i+1<h && !dot[i+1][j] && image[i+1][j]=='X')
    {
        dfs2(h,w,image,dot,i+1,j);
    }
    if(i-1>=0 && !dot[i-1][j] && image[i-1][j]=='X')
    {
        dfs2(h,w,image,dot,i-1,j);
    }
    if(j-1>=0 && !dot[i][j-1] &&  image[i][j-1]=='X')
    {
        dfs2(h,w,image,dot,i,j-1);
    }
    if(j+1<w && !dot[i][j+1] &&  image[i][j+1]=='X')
    {
        dfs2(h,w,image,dot,i,j+1);
    }

}
void dfs1(int h,int w,char image[100][100],int die[100][100],int i,int j)
{
    die[i][j] = 1;
    if(i+1<h && !die[i+1][j] &&( image[i+1][j]=='*' || image[i+1][j]=='X'))
    {
        dfs1(h,w,image,die,i+1,j);
    }
    if(i-1>=0 && !die[i-1][j] && (image[i-1][j]=='*' || image[i-1][j]=='X'))
    {
        dfs1(h,w,image,die,i-1,j);
    }
    if(j-1>=0 && !die[i][j-1] && (image[i][j-1]=='*' || image[i][j-1]=='X'))
    {
        dfs1(h,w,image,die,i,j-1);
    }
    if(j+1<w && !die[i][j+1] && (image[i][j+1]=='*' || image[i][j+1]=='X'))
    {
        dfs1(h,w,image,die,i,j+1);
    }

}


int main()
{

    int w,h;

    int thro = 0;
    char wh[100]={'\0'};
    while(gets(wh)){


    int i,j;
    if(wh[0]=='0' && wh[2]=='0')
        break;
    thro++;
    char image[100][100];
    sscanf(wh,"%d%d",&w,&h);
    for(i=0;i<h; i++)
    {
        gets(image[i]);
    }

    int die[100][100];
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            die[i][j] = 0;
        }
    }
    int counter = 0;
    int dot[100][100];
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            dot[i][j] = 0;
        }
    }
    int sortme[100] = {0};
    int index = 0;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {

            if((image[i][j]=='*' || image[i][j]=='X') && (!die[i][j]))
            {
                dfs1(h,w,image,die,i,j);
                int a,b;

                for(a=0; a<h; a++)
                {
                    for(b=0; b<w; b++)
                    {
                        if(die[a][b])
                        {
                            if(!dot[a][b] && image[a][b]=='X')
                            {
                                dfs2(h,w,image,dot,a,b);
                                counter++;
                            }
                        }

                    }
                }


                sortme[index++] = counter;
                counter = 0;
            }
        }
    }


    qsort(sortme,index,sizeof(int),compare);

    printf("Throw %d\n",thro);
    for(i=0;i<index-1;i++)
        printf("%d ",sortme[i]);
    printf("%d\n\n",sortme[i]);
    }
    return 0;
}
