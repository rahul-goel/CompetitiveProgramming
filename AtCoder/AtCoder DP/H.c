#include <string.h>
#include <stdio.h>
typedef long long ll;
ll m = 1000000007;
char mat[1005][1005];
int vis[1005][1005], memo[1005][1005];

ll solve(int i, int j)
{
    if(vis[i][j])
        return memo[i][j];
    vis[i][j]++;
    if(i==1 && j>1)
        return memo[i][j] = solve(i, j-1);
    if(i>1 && j==1)
        return memo[i][j] = solve(i-1, j);
    if(i==1 && j==1)
        return memo[i][j] = 1;
    
    return memo[i][j] = (solve(i-1, j) + solve(i, j-1))%m;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(vis, 0, sizeof(vis));
    memset(memo, 0, sizeof(memo));
    int h, w;
    char dummy;
    scanf("%d %d", &h, &w);
    scanf("%c", &dummy);
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
            scanf("%c", &mat[i][j]);
        scanf("%c", &dummy);
    }
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(mat[i][j] == '#')
                vis[i][j]++;
        }            
    }
    printf("%lld\n", solve(h, w));
    // for(int i=1; i<=h; i++)
    // {
    //     for(int j=1; j<=w; j++)
    //     {
    //         printf("%d ", memo[i][j]);
    //     }            
    //     printf("\n");
    // }
    return 0;
}