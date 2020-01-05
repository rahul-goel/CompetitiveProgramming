#include <stdio.h>
#include <math.h>
int main (void)
{
    long long n[60];
    n[0]=0;
    n[1]=1;
    for(int i=2; i<60; i++)
        n[i] = (n[i-1] + n[i-2])%10;
    long long T;
    scanf("%lld", &T);
    while (T--)
    {
        long long N;
        scanf("%lld", &N);
        long long k = 1;
        while (k <= N) 
        {
            k <<= 1;
        }
        k >>= 1;
        printf("%lld\n",n[((k-1)%60)]);
    }
    
    return 0;
}