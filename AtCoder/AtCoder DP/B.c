//Created by Rahul Goel
#include <stdio.h>
#include <string.h>
#include <math.h>
int memo[100005], arr[100005], vis[100005];
int min(int a, int b)
{
    return a<b ? a : b;
}
int dp(int n, int k)
{
    if(vis[n]==1)
        return memo[n];
    vis[n]=1;
    int mn = 1000000000;
    for(int i=n-k; i<n; i++)
        mn = min(mn, dp(i, k) + fabs(arr[n]-arr[i]));
    return memo[n] = mn;
}
int main()
{
    memset(memo, 0, sizeof(memo));
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    int n, k;   scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<k; i++)
    {
        memo[i] = fabs(arr[i]-arr[0]);
        vis[i]=1;
    }
    printf("%d\n", dp(n-1, k));
    return 0;
}