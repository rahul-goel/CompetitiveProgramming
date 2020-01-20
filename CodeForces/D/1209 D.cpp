/*
	Created by Rahul Goel.
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
#include <map>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1000000000;

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

vvi adj;
vi vis;

void add_edge(int u, int v)
{
	adj[u].pb(v), adj[v].pb(u);
}
void dfs(int v)
{
	vis[v] = 1;

	for(int u : adj[v])
	{
		if(!vis[u])
			dfs(u);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n+1), vis.assign(n+1, 0);
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}

	int components = 0;
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
			components++;
		}
	}	
	cout << m - n + components << endl;
	return 0;
}