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
    int q;  scanf("%d", &q);
    while(q--)
    {
        char s[105], t[105];
        scanf("%s", s);
        scanf("%s", t);
        int len = strlen(s);
        int as[256]={0}, at[256]={0};
        for(int i=0; i<len; i++)
        {
            as[s[i]]++;
            at[t[i]]++;
        }
        int flag=0;
        for(int i=0; i<256; i++)
        {
            if(as[i]>0 && at[i]>0)
                flag=1;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
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