#include <stdio.h>
#include <stdlib.h>
int comparetor (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int binsearch1(int *arr, int low, int high, int search)    //just greater than or equal to
{
    int mid, pos = -1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]>search)
        {
            pos = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return pos;
}
int binsearch2(int *arr, int low, int high, int search)    //just less than or equal to
{
    int mid, pos = -1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]<search)
        {
            pos = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return pos;
}
int main()
{
    int n;  scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), comparetor);
    long long count = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int l = binsearch1(arr, j+1, n-1, arr[j]-arr[i]);
            int r = binsearch2(arr, j+1, n-1, arr[j]+arr[i]);
            if(l==-1 || r==-1)
                continue;
            else
                count += r-l+1;
        }
    }
    printf("%lld\n", count);
    free(arr);
    return 0;
}