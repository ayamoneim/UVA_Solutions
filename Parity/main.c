
//Parity
//Get the binary Representation of a number


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned long long i;
    scanf("%I64d",&i);
    while(i)
    {
        int sum=0;
        unsigned long long counter=0,j;
        j=i;
        printf("The parity of ");
        while(i)
        {
            if(i&1)
             {
                 sum++;
             }
             counter++;
             i=i>>1;
        }
        int num;
        while(counter)
        {
            num=1<<(counter-1);
            if(num&j)
            {
                printf("1");
            }else
            {
                printf("0");
            }
            counter--;
        }
        printf(" is %d (mod 2).\n",sum);
        scanf("%I64d",&i);
        }

    return 0;
}
