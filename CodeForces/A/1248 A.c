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
int main()
{
    long long t;  scanf("%lld", &t);
    while(t--)
    {
        long long n;  scanf("%lld", &n);
        long long arr1[100005] = {0};
        long long count1odd=0, count2odd=0;
        for(long long i=0; i<n; i++)
        {
            scanf("%lld", &arr1[i]);
            if(arr1[i]%2==1)
                count1odd++;
        }
        long long m;  scanf("%lld", &m);
        long long arr2[100005] ={0};
        for(long long i=0; i<m; i++)
        {
            scanf("%lld", &arr2[i]);
            if(arr2[i]%2==1)
                count2odd++;
        }
        long long ans = (count1odd*count2odd)+((n-count1odd)*(m-count2odd));
        printf("%lld\n", ans);
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