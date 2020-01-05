#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long min(long long a, long long b);
long long max(long long a, long long b);
int comparetor (const void * a, const void * b);


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long int a, b, n;
        scanf("%lld %lld %lld", &a, &b, &n);
        if(n%2==0)
            printf("%lld\n", max(a,b)/min(a,b));
        else
            printf("%lld\n", max(a*2,b)/min(a*2,b));
    }
    return 0;
}




long long max(long long a, long long b)
{
    if(a>=b)
        return a;
    else
        return b;
}
long long min(long long a, long long b)
{
    if(a<=b)
        return a;
    else
        return b;
}
int comparetor (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}