#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int rows[30]={0};
int columns[30]={0};
int diagonal1[30]={0};
int diagonal2[30]={0};
int arr[30]={0};
int fin[100][100];
int sol=0;
int n,m;
void Queens(int r,int n,int m){

    if(r==8 ){
        int w;
        if(sol+1<10){
           printf(" %d     ",sol+1);
        }
        else{
             printf("%d     ",sol+1);
        }
           for(w=0;w<8;w++){

                printf(" %d",arr[w]+1);



           }
           printf("\n");

            sol++;
        return;
    }
    int i;
    if(r==m){
        Queens(r+1,n,m);
    }
    for(i=0;i<8;i++){


     if( rows[i]==0 && columns[r]==0 && diagonal1[8+(i-r)]==0 && diagonal2[(i+r)]==0){



        rows[i]=1;
        columns[r]=1;
        diagonal1[8+(i-r)]=1;
        diagonal2[(i+r)]=1;
		arr[r]=i;

        Queens(r+1,n,m);


        rows[i]=0;
        columns[r]=0;
        diagonal1[8+(i-r)]=0;
        diagonal2[(i+r)]=0;
    }

    }
}

int main()
{
   int trials;
   scanf("%d",&trials);

	int i;
   for(i = 0 ; i < trials ; i++){


        int k;
   for(k=0;k<30;k++){
    rows[k]=0;
    columns[k]=0;
    diagonal1[k]=0;
    diagonal2[k]=0;
    arr[k]=0;
   }
   sol=0;

    scanf("%d%d",&n,&m);


    n-=1;
    m-=1;
    rows[n]=1;
    columns[m]=1;
    diagonal1[8+(n-m)]=1;
    diagonal2[n+m]=1;
    printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    Queens(0,n,m);
	if(i < trials-1)
        printf("\n");
	}
    return 0;
}
