#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX (1<<20)

char boolean[MAX];

int main() {
        long long i, j;
        memset(boolean,0,sizeof boolean);

        for (i = 2; i * i <= MAX; i++) {
                if (!boolean[i]) {
                        for (j = i * i; j < MAX; j += i) {
                                boolean[j] = 1;
                        }
                }
        }

        for (i = 4; i < MAX; i++) {
                if (boolean[i]) {
                        for (j = i * 2; j < MAX; j += i) {
                                boolean[j] = 0;
                        }
                }
        }
        int n,k;
        while(scanf("%d",&n)==1)
        {
            int input;
            int counter=0;
            for(k=0;k<n;k++)
            {
                scanf("%d",&input);
                counter+=boolean[input];
            }
            printf("%d\n",counter);
        }
        return 0;
}
