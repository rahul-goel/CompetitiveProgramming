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

vector < vector < int > > adj;
vector < int > vis;
priority_queue < int, vector < int > , greater < int > > pq;

void add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n+5), vis.assign(n+5, false);
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}

	vector < int > ans;

	pq.push(1), vis[1] = 1;
	while(!pq.empty())
	{
		int v = pq.top();
		ans.push_back(v), pq.pop();
		for(int u : adj[v])
			if(!vis[u])
				pq.push(u), vis[u] = 1;
	}

	for(int u : ans)
		cout << u << " ";
	cout << endl;

	return 0;
}