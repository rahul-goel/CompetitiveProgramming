//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
#include <string.h>
int memo[100005], arr[100005], vis[100005];
int min(int a, int b)
{
    return a<b ? a : b;
}
int dp(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return fabs(arr[1]-arr[0]);
    if(vis[n]==1)
        return memo[n];
    vis[n]=1;
    return memo[n] = min(dp(n-1)+fabs(arr[n]-arr[n-1]), dp(n-2)+fabs(arr[n]-arr[n-2]));
}
int main()
{
    memset(arr, 0, sizeof(arr));
    memset(memo, 0, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    int n;  scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", dp(n-1));
    return 0;
}