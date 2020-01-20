/*
	Created by Rahul Goel.
	Problem URL - https://codeforces.com/problemset/problem/1139/C
*/

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
const ll INF = 1000000000;

#define pii pair < ll, ll >
#define vi vector < ll >
#define vvi vector < vector < ll > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

vvi adj;
vi vis;

void add_edge(ll u, ll v)
{
	adj[u].pb(v), adj[v].pb(u);
}

ll dfs(ll v)
{
	ll cnt = 1;
	vis[v] = 1;
	for(ll u : adj[v])
		if(!vis[u])
			cnt += dfs(u);
	return cnt;
}

ll power(ll a, ll b)
{
	ll returnvalue = 1;
	while(b)
	{
		if(b&1)
			returnvalue = (returnvalue*a)%mod;
		b>>=1, a = (a*a)%mod;
	}
	return returnvalue;
}

int main()
{
	ll n, k;
	cin >> n >> k;
	adj.resize(n+1), vis.assign(n+1, 0);
	for(ll i=0; i<n-1; i++)
	{
		ll u, v, colour;
		cin >> u >> v >> colour;
		if(!colour)
			add_edge(u, v);
	}

	ll val = 0;
	for(ll i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			ll size = dfs(i);
			val = (val + power(size, k))%mod;
		}
	}
	ll ans = (power(n, k) - val + mod)%mod;
	cout << ans << endl;	
	return 0;
}