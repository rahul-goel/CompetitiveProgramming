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
    int n, k; scanf("%d %d", &n, &k);
    int arr[1000000] = {0};
    int convo[1000000] = {0};
    int count=0;
    for(int i=1; i<=n; i++)
    {
        int flag=0, rise;
        scanf("%d", &arr[i]);
        for(int j=0; j<k; j++)
        {
            if(arr[i]==convo[j])
            {
                flag=1;          
                rise = j;
                break;
            }
        }
        if(flag==0)
        {
            count++;
            for(int j=n-1; j>0; j--)
                convo[j]=convo[j-1];
            convo[0] = arr[i];
        }
        // else
        // {
        //     for(int j=rise; j>0; j--)
        //         convo[j]=convo[j-1];
        //     convo[0] = arr[i];
        // }
    }
    count = min(count, min(n,k));
    printf("%d\n", count);
    for(int i=0; i<count; i++)
        printf("%d ", convo[i]);
    printf("\n");
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