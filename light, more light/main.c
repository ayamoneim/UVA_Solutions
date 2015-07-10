#include <stdio.h>
#include <stdlib.h>
int boolean[10000001];
long long primes[664580];

long long countdiv(long long n)
{
        long long ans = 1;
        int index = 0;
        long long pf = primes[index++];
        while (n != 1 && pf * pf <= n) {
                long long power = 0;
                while (n % pf == 0) {
                        n /= pf;
                        power++;
                }
                ans *= (power + 1);
                pf = primes[index++];
        }
        if (n != 1)
                ans *= 2;
        return ans;
}


int main()
{

        boolean[0] = 1;
        boolean[1] = 1;
        long long i, j;


        for (i = 2; i * i < 10000001; i++) {
                if (!v[i]) {
                        for (j = i * i; j < 10000001; j += i) {
                                boolean[j] = 1;
                        }
                }
        }

        int index = 0;
        for (i = 2; i < 10000001; i++) {
                if (!boolean[i]) {
                        primes[index++] = i;
                }
        }
        long long n;
        while(scanf("%lli",&n)==1 && n)
        {
            if(countdiv(n)&1)
            {
                printf("yes");
            }else
            {
                printf("no");
            }
            printf("\n");

        }
        return 0;
}
