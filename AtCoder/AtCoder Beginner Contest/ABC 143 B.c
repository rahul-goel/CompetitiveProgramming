#include <stdio.h>
int main()
{
    int n;  scanf("%d", &n);
    int arr[55]={0};
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            ans += arr[i]*arr[j];
    printf("%d\n", ans);
    return 0;
}