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
vi vis, parent, dist;
queue < int > q;

void add_edge(int u, int v)
{
	adj[u].pb(v), adj[v].pb(u);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		adj.clear(), adj.resize(n+5), vis.clear(), vis.resize(n+5, 0);
		parent.clear(), parent.resize(n+5, -1), dist.clear(), dist.resize(n+5, INF);

		for(int i=0; i<m; i++)
		{
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
		}

		q.push(1), dist[1]=0, vis[1]=1;

		while(!q.empty())
		{
			int v = q.front();
			q.pop();

			for(auto u : adj[v])
			{
				if(!vis[u])
					q.push(u), dist[u] = dist[v] + 1, parent[u] = v, vis[u]=1;
			}
		}

		vi odd, even;
		for(int i=1; i<=n; i++)
		{
			if(dist[i] & 1)
				odd.pb(i);
			else
				even.pb(i);
		}

		if(odd.size() <= n/2)
		{
			cout << odd.size() << endl;
			for(int i : odd)
				cout << i << ' ';
			cout << endl;
		}
		else
		{
			cout << even.size() << endl;
			for(int i : even)
				cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}