//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

ll memo[105][105], vis[105][105];
char s[105], t[105];

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

ll solve(ll m, ll n)
{
	if(m==0 && n==0 && s[m]==t[n])
		return 1;
	else if(m==0 && n==0)
		return 0;

	if(vis[m][n])
		return memo[m][n];
	vis[m][n]++;

	if(m==0)
	{
		if(s[m]==t[n])
			return memo[m][n]=1;
		else return memo[m][n] = solve(m, n-1);
	}
	else if(n==0)
	{
		if(s[m]==t[n])
			return memo[m][n]=1;
		else return memo[m][n] = solve(m-1, n);
	}

	if(s[m]==t[n])
		return memo[m][n] = solve(m-1, n-1) + 1;
	else
		return memo[m][n] = max(solve(m-1, n), solve(m, n-1));
}

int main()
{
	ll q;
	scanf("%lld", &q);
	while(q--)
	{
		memset(memo, 0, sizeof(memo));
		memset(vis, 0, sizeof(vis));
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));

		ll m, n;
		scanf("%lld %lld", &m, &n);

		scanf("%s %s", s, t);

		printf("%lld\n", solve(m-1, n-1));
	}
	return 0;
}