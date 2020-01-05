#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pr 0.0000001
long long max(long long a, long long b);
long long min(long long a, long long b);
int comparetor (const void * a, const void * b);//for qsort in ascending order
unsigned long long highestpowerof2lessthan(unsigned long long a);
//above function has unsigned for more acciracy. so use type casting.
unsigned long long leastpowerof2greaterthan(unsigned long long a);
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long int l, r;
        scanf("%lld %lld", &l, &r);
        if(l==r)
        {
            if(l%2==1)
                printf("Odd\n");
            else
                printf("Even\n");
            continue;
        }
        if(l%2==1 && r%2==1)
        {
            if(((r-l)/2)%2==0)
                printf("Odd\n");
            else
                printf("Even\n");
        }
        else if(l%2==0 && r%2==0)
        {
            if(((r-l)/2)%2==1)
                printf("Odd\n");
            else
                printf("Even\n");
        }
        else if(l%2==0 && r%2==1)
        {
            if(((r-l)/2)%2==1)
                printf("Even\n");
            else
                printf("Odd\n");
        }
        else
        {
            if(((r-l)/2)%2==1)
                printf("Even\n");
            else
                printf("Odd\n");
        }
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
unsigned long long highestpowerof2lessthan(unsigned long long a)
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