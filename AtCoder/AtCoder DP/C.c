#include <stdio.h>
#include <math.h>
#include <string.h>
int memo[100005][3], arr[100005][3], vis[100005][3];

int max(int a, int b)
{
    return a>b ? a : b;
}

int min(int a, int b, int c)
{
    return a<b ? a : b;
}

int dp(int n, int r)
{
    if(n==0)
        return max(arr[0][0], max(arr[0][1], arr[0][2]));
    if(vis[n][r]==1)
        return memo[n][r];
    vis[n][r]=1;
    if(r==0)
        return memo[n][r] = arr[n][0]+max(dp(n-1, 1), dp(n-1, 2));
    if(r==1)
        return memo[n][r] = arr[n][1]+max(dp(n-1, 0), dp(n-1, 2));
    if(r==2)
        return memo[n][r] = arr[n][2]+max(dp(n-1, 0), dp(n-1, 1));
}

int main()
{
    memset(memo, 0, sizeof(memo));
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    int n;  scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    printf("%d\n", max(dp(n-1, 0), max(dp(n-1, 1), dp(n-1, 2))));
    return 0;
}