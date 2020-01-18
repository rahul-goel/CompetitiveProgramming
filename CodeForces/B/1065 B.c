//Created by Rahul Goel
#include <stdio.h>
#include <math.h>

int main()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if(m==0)
    {
        printf("%lld %lld\n", n, n);
        return 0;
    }
    long long mx = n-(int)ceil((1+sqrt(1+8*m))/2);
    long long mn;
    if(n&1)
    {
        if(m>=(n+1)/2)
            mn=0;
        else
            mn = n - 2*m;
    }
    else
    {
        if(m>=n/2)
            mn=0;
        else
            mn = n - 2*m;
    }
    printf("%lld %lld\n", mn, mx);
    return 0;
}