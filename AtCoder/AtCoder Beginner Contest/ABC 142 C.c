//Created by Rahul Goel
#include <stdio.h>
int main()
{
    int n;  scanf("%d", &n);
    int arr[100005] = {0};
    int ans[100005] = {0};
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    for(int i=1; i<=n; i++)
        ans[arr[i]]=i;
    for(int i=1; i<=n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}