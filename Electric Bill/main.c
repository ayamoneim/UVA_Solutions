#include <stdio.h>
#include <stdlib.h>


long long to_cwh(long long a)
{
    if(a<=200)
    {
        return a/2.0;
    }else if(a<=29900)
    {
        return (a-200)/3+100;
    }else if(a<=4979900)
    {
        return (a-29900)/5+10000;
    }else
    {
        return (a-4979900)/7+1000000;
    }
}

long long to_dollar(long long a)
{
    if(a<=100)
    {
        return 2*a;
    }else if(a<=10000)
    {
        return 200+3*(a-100);
    }else if(a<=1000000)
    {
        return 29900+(a-10000)*5;
    }else
    {
        return 4979900+(a-1000000)*7;
    }
}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    while(a || b)
    {
        long long lo=0;
        long long hi=to_cwh(a)/2.0;
        long long neighbor_cwh;
        while(lo<hi)
        {
        long long me_cwh=(lo+hi)/2;
        neighbor_cwh=to_cwh(a)-me_cwh;
        long long diff=to_dollar(neighbor_cwh)-to_dollar(me_cwh);
        if(diff<=b)
        {
            hi=me_cwh;
        }else
        {
            lo=me_cwh+1;
        }
        }
        printf("%lld\n",to_dollar(lo));
        scanf("%lld %lld",&a,&b);
    }
    return 0;
}
