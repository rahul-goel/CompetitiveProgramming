#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll memo[2005][2005], vis[2005][2005];
ll n, k;

int solve(int r, int curr)
{
	if(r==k)
		return 1;

	if(vis[r][curr])
		return memo[r][curr];
	vis[r][curr] = 1;


	for(int i=curr; i<=n; i+=curr)
	{
		memo[r][curr] = (memo[r][curr] + solve(r+1, i))%mod;
	}

	//cout << r << ' ' << curr << ' ' << memo[r][curr] << endl;

	return memo[r][curr];
}

int main()
{
	memset(memo, 0, sizeof(memo));
	memset(vis, 0, sizeof(vis));

	cin >> n >> k;
	ll ans = 0;
	for(ll i=1; i<=n; i++)
		ans = (ans + solve(1, i))%mod;
	cout << ans << endl;
	return 0;
}