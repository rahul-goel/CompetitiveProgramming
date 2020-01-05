#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll mat[105][105], sum[105][105], vis[105][105];
ll store[105][105];

ll max(ll a, ll b)
{
	return a>b ? a : b;
}

ll preprocess(ll i, ll j)
{
	if(vis[i][j])
			return sum[i][j];	
	vis[i][j]++;
	if(i==1 && j==1)
		return sum[i][j] = mat[i][j];
	if(i==1)
		return sum[i][j] = preprocess(i, j-1) + mat[i][j];
	if(j==1)
		return sum[i][j] = preprocess(i-1, j) + mat[i][j];

	return sum[i][j] = preprocess(i-1, j) + preprocess(i, j-1) - preprocess(i-1, j-1) + mat[i][j];
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	memset(mat, 0, sizeof(mat));
	memset(sum, 0, sizeof(sum));
	memset(vis, 0, sizeof(vis));

	ll n; scanf("%lld", &n);

	for(ll i=1; i<=n; i++)
	{
		for(ll j=1; j<=n; j++)
				scanf("%lld", &mat[i][j]);
	}

	preprocess(n, n);

	for(ll i=n; i>=1; i--)
	{
		for(ll j=n; j>=1; j--)
		{
			ll mx = -10000000000000;
			for(ll k=i; k>=1; k--)
			{
				for(ll l=j; l>=1; l--)
					mx = max(mx, sum[i][j] - sum[i][l-1] - sum[k-1][j] + sum[k-1][l-1]);
			}
			store[i][j] = mx;
		}
	}
	ll mx = -1000000000000;
	// for(ll i=1; i<=n; i++)
	// {
	// 	for(ll j=1; j<=n; j++)
	// 		printf("%lld ", store[i][j]);
	// 	printf("\n");
	// }
	for(ll i=1; i<=n; i++)
	{
		for(ll j=1; j<=n; j++)
			mx = max(mx, store[i][j]);
	}
	printf("%lld\n", mx);
	return 0;
}