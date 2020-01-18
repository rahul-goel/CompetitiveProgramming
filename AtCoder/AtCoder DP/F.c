//Created by Rahul Goel
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef long long ll;

int memo[3005][3005], vis[3005][3005], k;
char s[3005], t[3005], str[3005];

int max(int a, int b)
{
    return a>b ? a : b;
}
int solve(int i, int j)
{
    if(i==0 && j==0)
    {
        if(t[j]==s[i])
            return memo[i][j] = 1;
        else
            return memo[i][j] = 0;
    }
    if(i==0)
    {
        if(t[j]==s[i])
            return memo[i][j] = 1;
        else
            return memo[i][j] = solve(i, j-1);
    }
    if(j==0)
    {
        if(t[j]==s[i])
            return memo[i][j] = 1;
        else
            return memo[i][j] = solve(i-1, j);
    }
    if(vis[i][j])
        return memo[i][j];
    vis[i][j]++;
    if(s[i]==t[j])
        return memo[i][j] = 1+solve(i-1, j-1);
    else
        return memo[i][j] = max(solve(i, j-1), solve(i-1, j));
}

void solvestr(int i, int j)
{
    //printf("i=%d j=%d\n", i, j);
    if(i==0 && j==0 && s[i]==t[j])
    {
        str[k++] = s[i];
        return;
    }
    if(i==0 && j==0)
    {
        return ;
    }
    if(i==0 && s[i]==t[j])
    {
        str[k++] = s[i];
        return;
    }
    if(j==0 && s[i]==t[j])
    {
        str[k++] = s[i];
        return;
    }
    if(i==0)
    {
        solvestr(i, j-1);
        return ;
    }
    if(j==0)
    {
        solvestr(i-1, j);
        return;
    }
    if(s[i]==t[j])
    {
        str[k++] = s[i];
        solvestr(i-1, j-1);
        return ;
    }
    if(memo[i][j] == memo[i-1][j])
    {
        solvestr(i-1, j);
        return ;
    }
    if(memo[i][j] == memo[i][j-1])
    {
        solvestr(i, j-1);
        return ;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(memo, 0, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    scanf("%s %s", s, t);
    int len = solve(strlen(s)-1, strlen(t)-1);
    //printf("%d\n", len);
    k=0;
    solvestr(strlen(s)-1, strlen(t)-1);
    for(int i=k-1; i>=0; i--)
        printf("%c", str[i]);
    printf("\n");
    // for(int i=0; i<4; i++)
    // {
    //     for(int j=0; j<4; j++)
    //         printf("%d ", memo[i][j]);
    //     printf("\n");
    // }
    return 0;
}