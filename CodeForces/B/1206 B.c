//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pr 0.0000001
long long max(long long a, long long b);
long long min(long long a, long long b);
int comparetor (const void * a, const void * b);//for qsort in ascending order
unsigned long long greatestpowerof2lessthan(unsigned long long a);
//above function has unsigned for more acciracy. so use type casting.
unsigned long long leastpowerof2greaterthan(unsigned long long a);
//above function has unsigned for more acciracy. so use type casting.
int main()
{
    long long n;  scanf("%lld", &n);
    long long arr[1000000] = {0};
    long long count0=0, countn1=0, countp1=0;
    long long coins=0;
    for(long long i=0; i<n; i++)
    {
        scanf("%lld", &arr[i]);
        if(arr[i]<-1)
        {   coins += (-1-arr[i]);
            countn1++;
        }
        else if(arr[i]==-1)
            countn1++;
        else if(arr[i]==0)
            count0++;
        else
        {
            countp1++;
            coins+=(arr[i]-1);
        }
    }
    if(countn1 && countn1%2==1)
    {
        if(count0!=0)
        {
            coins++; count0--; //change this 0 to -1
        }
        else
            coins+=2; //one -1 changes to 1
    }
    coins += count0;

    printf("%lld\n", coins);
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