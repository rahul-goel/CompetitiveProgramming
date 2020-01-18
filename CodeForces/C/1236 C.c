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
    int arr[305][305] = {0};
    int n;  scanf("%d", &n);
    int k=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            arr[j][i] = k++;
    }
    for(int j=1; j<n; j+=2)
    {
        for(int i=0; i<n/2; i++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[n-i-1][j];
            arr[n-i-1][j] = temp;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
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