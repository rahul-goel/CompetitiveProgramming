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

vector < pair < int, int > > adj;//first = node, second = edge weight;
vector < int > dist, pred;
vector < vector < int > > path;

void add_edge(int from, int to, int len)
{
	adj[from].push_back(make_pair(to, len));
	adj[to].push_back(make_pair(from, len));
}

void dijkstra(int s, int n)
{
	dist.assign(n, INF), pred.assign(n, -1);
	vector < bool > used(n, false);

	dist[s] = 0;
	for(int i=0; i<n; i++)
	{
		int v = -1;
		for(int j=0; j<n; j++)
			if(!used[j] && (v == -1 || dist[j] < dist[v]))
				v = j;	
	}

	if(dist[v] == INF)
		break;

	used[v] = true;

	for(int edge : adj[v])
	{
		int to = edge.first;
		int len = edge.second;

		if(dist[v] + len < dist[to])
		{
			dist[to] = dist[v] + len;
			pred[to] = v;
		}
	}
}

void restore_path(int s, int t)
{
	for(int v = t; v!=s; v = p[v])
		path[t].push_back(v);
	path[t].push_back(s);
	reverse(path[t].begin(), path[t].end());
}

int main()
{

	return 0;
}