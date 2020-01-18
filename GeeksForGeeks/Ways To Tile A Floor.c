//Created by Rahul Goel
#include <stdio.h>
#include <string.h>
typedef long long ll;
ll dp[75];
ll tile(ll n)
{
	if(dp[n]!=-1)
		return dp[n];
	else if(n==1)
			return dp[n] = 1;
	else if(n==2)
			return dp[n] = 2; 
	else 
		return dp[n] = tile(n-1) + tile(n-2);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	tile(74);
	ll t;	scanf("%lld", &t);
	while(t--)
	{
		ll n;	scanf("%lld", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}