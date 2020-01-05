#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pr 0.0000001
typedef long long ll;
long long max(long long a, long long b);
long long min(long long a, long long b);
int comparetor (const void * a, const void * b);//for qsort in ascending order
unsigned long long greatestpowerof2lessthan(unsigned long long a);
//above function has unsigned for more acciracy. so use type casting.
unsigned long long leastpowerof2greaterthan(unsigned long long a);
//above function has unsigned for more acciracy. so use type casting.
long long pw(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b&1==1)
            ans = ans*a;
        a = a*a;
        b/=2;
    }
    return ans;
}
int main()
{
    int n;  scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), comparetor);
    long long hor = 0, ver = 0;
    for(int i=0; i<n/2; i++)
        ver += arr[i];
    for(int i=n/2; i<n; i++)
        hor += arr[i];
    long long ans = pw(hor, 2) + pw(ver, 2);
    printf("%lld\n", ans);
    free(arr);
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
unsigned long long greatestpowerof2lessthan(unsigned long long a)
{
    unsigned long long ans=1, curr=1;
    for(int i=0, upperlimit=8*sizeof(unsigned long long); i<upperlimit; i++)
    {
        curr = 1<<i;
        if(curr>a)
            break;
        ans = curr;
    }
    return ans;
}
unsigned long long leastpowerof2greaterthan(unsigned long long a)
{
    unsigned long long curr=1;
    for(int i=0, upperlimit=8*sizeof(unsigned long long); i<upperlimit; i++)
    {
        curr = 1<<i;
        if(curr>=a)
            break;
    }
    return curr;
}