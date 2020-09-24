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


vvpii adj;
vi dist, parent, path;

void add_edge(int u, int v, int len)
{
	adj[u].pb({len, v});
	adj[v].pb({len, u});
}

void dijkstra(int source)
{
	dist[source] = 0;
	priority_queue < pii, vpii, greater < pii > > q;
	q.push({0, source});

	while(!q.empty())
	{
		int v = q.top().second;
		int dist_v = q.top().first;
		q.pop();

		if(dist_v != dist[v])
			continue;

		for(auto edge : adj[v])
		{
			int to = edge.second;
			int len = edge.first;

			if(dist[v] + len < dist[to])
			{
				dist[to] = dist[v] + len, parent[to] = v;
				q.push({dist[to], to});
			}
		}
	}
}

void restore_path(int source, int t)
{
	for(int u=t; u!=source; u=parent[u])
		path.pb(u);
	path.pb(source);
	reverse(path.begin(), path.end());
}

int main()
{

	return 0;
}
