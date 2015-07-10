#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long input[1000001]={0};
int checker[1000001]={0};
int v[1000001]={0};
long long primes[664580]={0};
int last_pf=0;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void check(long long n,int power)
{
    if(checker[n]<power)
    {
        checker[n]=power;
    }
}

void numPF(long long N) {
        int index = 0;
        long long pf = primes[index++];
        while (N != 1 && pf * pf <= N) {
                int counter = 0;
                while (N % pf == 0) {
                        N /= pf;
                        counter++;
                }
                check(pf,counter);
                pf = primes[index++];
                last_pf=pf;
        }
        if (N != 1){
                check(N,1);
                last_pf=N;
        }

}

int main()
{
         v[0] = v[1] = 1;
        long long i, j;

        for (i = 2; i * i < 1000001; i++) {
                if (!v[i]) {
                        for (j = i * i; j < 1000001; j += i) {
                                v[j] = 1;
                        }
                }
        }

        int index = 0;
        for (i = 2; i < 1000001; i++) {
                if (!v[i]) {
                        primes[index++] = i;
                }
        }

        int test_cases;
        scanf("%d",&test_cases);
        int cases=0;
        while(test_cases)
        {
        long long n;
        long long up;
        long long down=0;
        scanf("%lld",&n);
        cases++;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&input[i]);
            numPF(input[i]);
        }
        long long lcm=1;
        for(i=0;i<=last_pf;i++)
        {
            if(checker[i]!=0)
            {
                while(checker[i])
                {
                    lcm*=i;
                    checker[i]--;
                }
            }
        }
        up=n*lcm;
        for(i=0;i<n;i++)
        {
            down+=lcm/input[i];
        }
        long long g=gcd(up,down);
        printf("Case %d: %lld/%lld\n",cases,up/g,down/g);
        test_cases--;
        }
    return 0;
}
