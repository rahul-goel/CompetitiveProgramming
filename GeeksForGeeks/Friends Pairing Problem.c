//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

ll m = 1000000007;
ll memo[105], vis[105];

ll solve(ll n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;

	if(vis[n])
		return memo[n];
	vis[n]++;

	return memo[n] = (solve(n-1)%m + ((solve(n-2)%m)*((n-1)%m))%m )%m;
}

int main()
{
	ll t;
	scanf("%lld", &t);
	while(t--)
	{
		memset(memo, 0, sizeof(memo));
		memset(vis, 0, sizeof(vis));
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", solve(n));
	}
	return 0;
}