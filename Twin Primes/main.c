#include <stdio.h>
#include <math.h>
int boolean[31622];
int primes[3401];
void getPrimes()
{
    int i,j,counter = 0;
    for(i = 2 ; i <= 31622; i++)
    {
        if(!boolean[i])
        {
            primes[counter++] = i;
            for(j = i*i ; j<=31622 ; j+=i)
            {
                boolean[j] = 1;
            }
        }
    }
}
int main()
{
    int t,i,j,l,h,factors,max,currentPrime,cuurentNumber,best,c,counter;
    getPrimes();
    scanf("%d", &t);
    for(i = 0 ; i < t ; i++)
    {
        max = 0;
        scanf("%d %d", &l,&h);
        for(j = l ; j <= h ; j++)
        {
            counter = 0;
            factors = 1;
            cuurentNumber = j;
            while(counter < 3401 && primes[counter] <= cuurentNumber)
            {
                c=0;
                currentPrime = primes[counter];
                while(cuurentNumber %  currentPrime ==0)
                {
                    c++;
                    cuurentNumber/=currentPrime;
                }
                factors *= (c+1);
                counter++;
            }
            if(cuurentNumber != 1)
            {
                factors *= 2;
            }
            if(max < factors)
            {
                max = factors;
                best = j;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l,h,best,max);
    }

    return 0;
}
