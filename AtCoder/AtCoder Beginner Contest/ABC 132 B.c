#include <stdio.h>
int main()
{
    int n; scanf("%d", &n);
    int arr[50] = {0};
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    int count=0;
    for(int i=2; i<=n-1; i++)
    {
        if((arr[i]<arr[i-1] && arr[i]>arr[i+1]) || (arr[i]>arr[i-1] && arr[i]<arr[i+1]))
            count++;
    }
    printf("%d\n", count);
    return 0;
}