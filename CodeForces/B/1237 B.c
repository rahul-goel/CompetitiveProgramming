//Created by Rahul Goel
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
    int n;  scanf("%d", &n);
    int enter[100005] = {0};
    int exit[100005] = {0};
    int index[100005];
    memset(index, -1, 100005);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &enter[i]);
        index[enter[i]] = i;
    }
    for(int i=1; i<=n; i++)
        scanf("%d", &exit[i]);
    int pen=1, pex=1;
    long long fine=0;
    while(pen<=n)
    {
        if(enter[pen]==-1)
        {
            pen++;
            continue;
        }
        while(exit[pex]!=enter[pen])
        {
            enter[index[exit[pex]]]=-1;
            fine++;
            pex++;
            if(pex>n)
            break;
        }
        if(pex>n)
            break;
        pen++;
        pex++;
    }  
    printf("%lld\n", fine);
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