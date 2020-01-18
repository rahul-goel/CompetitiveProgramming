//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
int comparetor (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
    int n, k;   scanf("%d %d", &n, &k);
    int *arr = malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    long long count = 0;
    qsort(arr, n, sizeof(int), comparetor);
    for(int i=0; i<=n-2; i++)
    {
        int low = i+1, high = n-1, mid, pos = -1;
        while(low<=high)
        {
            mid = (high+low)/2;
            if(arr[mid]>=k + arr[i])
            {
                pos = mid;
                high = mid-1;
            }
            else if(arr[mid]<k + arr[i])
                low = mid+1;
        }
        if(pos!=-1)
            count += n-pos;
    }
    printf("%lld\n", count);
    free(arr);
    return 0;
}