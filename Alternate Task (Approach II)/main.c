#include <stdio.h>
#include <stdlib.h>

int v[1000];
long long primes[1001]={0};

long long powFn(long long base, long long power) {
        if (power == 0)
                return 1;
        if (power & 1)
                return base * powFn(base, power - 1);

        long long res = powFn(base, power / 2);
        return res * res;
}


long long sumDiv(long long N) {
        int index=0;
        long long ans = 1;
        long long pf = primes[index++];
        while (N != 1 && pf * pf <= N) {
                long long power = 0;
                while (N % pf == 0) {
                        N /= pf;
                        power++;
                }
                ans *= (powFn(pf, power + 1) - 1) / (pf - 1);
                pf = primes[index++];
        }
        if (N != 1)
                ans *= (powFn(N, 2) - 1) / (N - 1);
        return ans;
}


int main() {
        v[0] = 1;
        v[1] = 1;
        long long i, j;

        for (i = 2; i * i < 1000; i++) {
                if (!v[i]) {
                        for (j = i * i; j < 1000; j += i) {
                                v[j] = 1;
                        }
                }
        }

        int index = 0;
        for (i = 2; i < 1000; i++) {
                if (!v[i]) {
                        primes[index++] = i;
                }
        }
    int s;
    int cases=1;
    while(scanf("%d",&s)==1 && s)
    {
        int flag=0;
        for(i=s;i>=0;i--)
        {
            long long returnvalue=sumDiv(i);
            if(returnvalue==s)
            {
                flag=1;
                printf("Case %d: %lld",cases,i);
                break;
            }
        }
        if(!flag)
        {
            printf("Case %d: -1",cases);
        }
        printf("\n");
    }
    return 0;
}
