//Created by Rahul Goel
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

vector < ll > parent, size;

void make_set(ll v)
{
	parent[v] = v;
	size[v] = 1;
}

ll find_set(ll v)
{
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b)
{
	a = find_set(a), b = find_set(b);

	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);
		
		parent[b] = a, size[a] += size[b];
	}
}

int main()
{
	ll n, m;
	cin >> n >> m;
	parent.resize(n+5, 0), size.resize(n+5, 0);
	for(ll i=1; i<=n; i++)
		make_set(i);
	for(ll i=0; i<m; i++)
	{
		ll x, y;
		cin >> x >> y;
		union_sets(x, y);
	}
	ll ans = 1, check[55] = {0};
	for(ll i=1; i<=n; i++)
	{
		ll p = find_set(i);
		if(!check[p])
			check[p] = 1, ans = ans*(ll)(pow(2, size[p]-1));
	}
	cout << ans << endl;
	return 0;
}