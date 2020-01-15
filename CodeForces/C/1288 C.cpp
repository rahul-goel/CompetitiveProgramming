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

ll n, m;
ll memo[25][2005], vis[25][2005];

ll solve(ll index, ll prev)
{
	if(index == 0)
		return 1;
	if(vis[index][prev])
		return memo[index][prev];
	vis[index][prev] = 1;


	ll value = 0;
	for(ll i=1; i<=prev; i++)
		value = (value + solve(index-1, i))%mod;
	return memo[index][prev] = value;
}

int main()
{
	memset(memo, 0, sizeof(memo));
	memset(vis, 0, sizeof(vis));

	cin >> n >> m;
	ll ans = solve(m*2, n);
	cout << ans << endl;
	return 0;
}