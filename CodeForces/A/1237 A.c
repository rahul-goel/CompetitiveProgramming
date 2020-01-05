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
    int arr[15000] = {0};
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int countodd=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]%2==0)
        {
            arr[i] = arr[i]/2;
        }
        else if(arr[i]%2!=0 && countodd==0)
        {
            arr[i] = (int)floor((double)arr[i]/2);
            countodd=1;
            //printf("%d\n", arr[i]);
        }
        else if(arr[i]%2!=0 && countodd==1)
        {
            arr[i] = (int)ceil((double)arr[i]/2);
            countodd=0;
           // printf("%d\n", arr[i]);
        }
    }
    for(int i=0; i<n; i++)
        printf("%d\n", arr[i]);
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