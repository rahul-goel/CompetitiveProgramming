//Created by Rahul Goel
#include <string.h>
#include <stdio.h>
#include <math.h>
typedef long long ll;

ll memo[10005], vis[10005], arr[100005];

ll max(ll a, ll b)
{
    return a>b ? a : b;
}

ll dp(ll n)
{
    if(vis[n])
        return memo[n];
    vis[n]++;
    if(n==0)
        return memo[0] = arr[0];
    if(n==1)
        return memo[1] = arr[1];
    return memo[n] = max(dp(n-2) + arr[n], dp(n-1));
}

int main()
{
    int t;  scanf("%d", &t);
    int c = 1;
    while(c <= t)
    {
        memset(memo, 0, sizeof(memo)); 
        memset(vis, 0, sizeof(vis));
        memset(arr, 0, sizeof(arr));
        ll n;   scanf("%lld", &n);
        for(ll i=1; i<=n; i++)
            scanf("%lld", &arr[i]);
        printf("Case %d: ", c++);
        printf("%lld\n", dp(n));
    }   
    return 0;
}