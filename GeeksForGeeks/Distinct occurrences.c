#include <stdio.h>
#include <string.h>
int dp[105][105];

int recur(char s[], char t[], int n, int m)
{
    if(m==-1)
        return 1;
    else if(n==-1)
        return 0;

    if(dp[n][m]!=-1)
        return dp[n][m];
    
    if(s[n]==t[m])
        return dp[n][m] = recur(s, t, n-1, m-1) + recur(s, t, n-1, m);
    else
        return dp[n][m] = recur(s, t, n-1, m);    
}

int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        char s[105], t[105];
        scanf("%s %s", s, t);
        printf("%d\n", recur(s, t, strlen(s), strlen(t)));
    }
    return 0;
}