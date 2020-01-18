//Created by Rahul Goel
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long int max(long long int a, long long int b);
int comparetor (const void * a, const void * b);
long long int main()
{   
    long long int t;  
    scanf("%lld", &t);
    while(t--)
    {
        long long int n;
        scanf("%lld", &n);
        long long int *arr = malloc(sizeof(long long int)*n);
        for(long long int i=0; i<n; i++)
            scanf("%lld", &arr[i]);
        qsort(arr, n, sizeof(long long int), comparetor);
        long long int sum = 0;
        for(long long int i=0; i<=(n-2)/2; i++)
            sum += (arr[n-i-1]-arr[i]);
        printf("%lld\n", sum);
        free(arr);
    }
    return 0;
}

long long int max(long long int a, long long int b)
{
    if(a>=b)
        return a;
    else   
        return b;
}
int comparetor (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}