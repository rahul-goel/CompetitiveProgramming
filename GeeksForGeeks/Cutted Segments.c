//Created by Rahul Goel
#include <stdio.h>
#include <string.h>

int memo[4005], vis[4005];
int x, y, z;

int max(int a, int b)
{
	return a > b ? a : b;
}

int solve(int len)
{
	if(len == 0)
		return 0;
	if(len<x && len<y && len<z)
		return -1000000000;

	if(vis[len])
		return memo[len];
	vis[len]++;

	int returnvalue = -1000000000;
	if(len>=x)
		returnvalue = max(returnvalue, 1 + solve(len-x));
	if(len>=y)
		returnvalue = max(returnvalue, 1 + solve(len-y));
	if(len>=z)
		returnvalue = max(returnvalue, 1 + solve(len-z));

	return memo[len] = returnvalue;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(memo, 0, sizeof(memo));
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%d %d %d %d", &n, &x, &y, &z);
		printf("%d\n", solve(n));
	}
	return 0;
}