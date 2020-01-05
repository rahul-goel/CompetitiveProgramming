#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int max(long long int p, long long int q);
long long int gcd(long long int p, long long int q);
int main()
{   
    int n;
    scanf("%d", &n);
    long long int a[1000000] = {0};
    long long int mx = 0, sum = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
        sum+=a[i];
        mx = max(mx, a[i]);
    }
    long long int x = mx;
    for(int i=0; i<n; i++)
        a[i] = x-a[i];
    long long int z = 0;
    for(int i=0; i<n; i++)
        z = gcd(a[i], z);
    printf("%lld %lld\n", (n*mx-sum)/z, z );

    return 0;
}
long long int max(long long int p, long long int q)
{
    if(p>=q)
        return p;
    else
        return q;
}

long long int gcd(long long int p, long long int q)
{
    if(p==0)
        return q;
    else
    return gcd(q%p, p);
}