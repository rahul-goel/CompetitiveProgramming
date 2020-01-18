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
    int l, r, flag = 0, number=0;
    scanf("%d %d", &l, &r);
    for(int i=l; i<=r; i++)
    {   
        flag = 0;
        int no = i;
        int arr[200000] = {0};
        int r = 0;
        while(no)
        {
            arr[r] = no%10;
            no/=10;
            r++;
        }
        /*
        for(int j=0; j<r; j++)
        {
            printf("%d %d\n",i, arr[i]);
        }
        */
        for(int j=0; j<r; j++)
        {
            for(int k=0; k<r; k++)
            {
                if(j==k)
                    continue;
                if(arr[j]==arr[k])
                    flag = -1;
            }
        }
        if(flag==0)
        {
            number = i;
            break;
        }
    }
    if(flag==0)
        printf("%d\n", number);
    else
        printf("%d\n", -1);
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