#include <stdio.h>
#include <math.h>
#include <string.h>
typedef long long ll;
ll memo[105][100005], wt[100005], v[100005], vis[105][100005];

ll max(ll a, ll b)
{
    return a>b ? a : b;
}

ll solve(ll n, ll w)
{
    if(n==0 && w>=wt[0])
        return memo[n][w] = v[0];
    else if(n==0)
        return memo[n][w] = 0;
    if(vis[n][w])
        return memo[n][w];
    vis[n][w]=1;
    if(w>=wt[n])
        return memo[n][w] = max(solve(n-1, w), solve(n-1, w-wt[n])+v[n]);
    else
        return memo[n][w] = solve(n-1, w);
}

int main()
{
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    memset(memo, 0, sizeof(memo));
    memset(wt, 0, sizeof(wt));
    memset(v, 0, sizeof(v));
    memset(vis, 0, sizeof(vis));
    ll n, w;   scanf("%lld %lld", &n, &w);
    for(ll i=0; i<n; i++)
        scanf("%lld %lld", &wt[i], &v[i]);
    printf("%lld\n", solve(n-1, w));
    return 0;
}