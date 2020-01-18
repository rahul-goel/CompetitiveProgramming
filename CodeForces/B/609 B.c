//Created by Rahul Goel
#include <stdio.h>

int main()
{
    int n, m;   scanf("%d %d", &n, &m);
    int arr[11]={0};
    for(int i=0, x; i<n; i++)
    {
        scanf("%d", &x);
        arr[x]++;
    }
    int productsum = 0;
    for(int i=1; i<=m; i++)
    {
        for(int j=i+1; j<=m; j++)
            productsum += arr[i]*arr[j];
    }
    int ans = productsum;
    printf("%d\n", ans);
    return 0;
}