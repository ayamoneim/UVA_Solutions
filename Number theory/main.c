#include <stdio.h>
#include <stdlib.h>

int v[10000001];
long long primes[664580];


long long numDiv(long long N) {
        long long ans = 1;
        int index = 0;
        long long pf = primes[index++];
        while (N != 1 && pf * pf <= N) {
                long long power = 0;
                while (N % pf == 0) {
                        N /= pf;
                        power++;
                }
                ans *= (power + 1);
                pf = primes[index++];
        }
        if (N != 1)
                ans *= 2;
        return ans;
}



long long EulerPhi(long long N) {
        int index = 0;
        long long pf = primes[index++];
        long long ans = N;
        while (N != 1 && pf * pf <= N) {
                if (N % pf == 0)
                        ans = ans - (ans / pf);
                while (N % pf == 0)
                        N /= pf;
                pf = primes[index++];
        }
        if (N != 1)
                ans = ans - (ans / N);
        return ans;
}



int main() {

        v[0] = 1;
        v[1] = 1;
        long long i, j;


        for (i = 2; i * i < 10000001; i++) {
                if (!v[i]) {
                        for (j = i * i; j < 10000001; j += i) {
                                v[j] = 1;
                        }
                }
        }

        int index = 0;
        for (i = 2; i < 10000001; i++) {
                if (!v[i]) {
                        primes[index++] = i;
                }
        }


        long long input;
        while(scanf("%lld",&input)==1)
        {
            long long divisors=numDiv(input);
            long long coprimes=EulerPhi(input);
            if(divisors+coprimes-1 >=input)
            {
                printf("0\n");
            }else
            {
                printf("%lld\n",input-divisors-coprimes+1);
            }
        }
        return 0;
}
