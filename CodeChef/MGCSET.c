//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long min(long long a, long long b);
long long max(long long a, long long b);
int comparetor (const void * a, const void * b);


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int arr[30] = {0};
        int count = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i]%m==0)
                count++;
        }
        printf("%d\n", (int)(pow(2,count)-1));
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