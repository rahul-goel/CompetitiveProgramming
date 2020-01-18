//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
    return (a<=b) ? a : b;
}
int max(int a, int b)
{
    return (a>=b) ? a : b;
}
int comparetor (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    int mn=200, mx=-10;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count=1;
    qsort(arr, n, sizeof(int), comparetor);
    mx = arr[n-1]; mn = arr[0];
    int mid=-1;
    //printf("%d\n", arr[1]);
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]!=arr[i+1])
            count++;
        if(arr[i]!=mn && arr[i]!=mx)
            mid = arr[i];
    }
    //printf("%d %d %d\n", mn, mid, mx);
    if(count>3)
        printf("-1\n");
    else if(count<3 && (mx-mn)%2==0)
        printf("%d\n", (mx-mn)/2);
    else if(count<3 && (mx-mn)%2==1)
        printf("%d\n", mx-mn);
    else if((mx+mn)==2*mid)
        printf("%d\n", (mx-mid));
    else
        printf("-1\n");
    free(arr);
    return 0;
}