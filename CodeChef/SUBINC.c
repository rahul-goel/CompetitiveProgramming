#include <stdio.h>
#include <string.h>
typedef long long ll;

ll memo[100005], arr[100005], vis[100005], dec[100005];

ll dp(ll n)
{
	if(vis[n])
		return memo[n];
	vis[n]++;
	if(n==1)
		return memo[n]=1;
	if(arr[n]<arr[n-1])
		return memo[n] = dp(n-1) + 1;
	else
		return memo[n] = dp(n-1) + (n-dec[n]+1);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll t;	scanf("%lld", &t);
	while(t--)
	{
		memset(memo, 0, sizeof(memo));
		memset(vis, 0, sizeof(vis));
		memset(arr, 0, sizeof(arr));
		memset(dec, 0, sizeof(dec));
		ll n;	scanf("%lld", &n);
		for(ll i=1; i<=n; i++)
			scanf("%lld", &arr[i]);
		for(ll i=2, k=1; i<=n; i++)
		{
			if(arr[i]<arr[i-1])
			{
				k = i;
				dec[i] = k;
			}
			else
				dec[i] = k;
		}
		printf("%lld\n", dp(n));
	}
	return 0;
}