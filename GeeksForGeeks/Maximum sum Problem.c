#include <string.h>
#include <stdio.h>
int max(int a, int b)
{
    return a>b ? a : b;
}
int dp[100005];
int main()
{
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<12; i++)
        dp[i] = i;
    dp[12] = 13;
    for(int i=13; i<100005; i++)
        dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}