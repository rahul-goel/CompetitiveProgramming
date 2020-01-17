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
vector < int > parent, dist_s, dist_t;
vector < bool > vis;

queue < int > q;

void add_edge(int v, int u)
{
	adj[v].push_back(u);
	adj[u].push_back(v); 
}

int main()
{
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	adj.resize(n+5), parent.assign(n+5, -1), vis.assign(n+5, false), dist_s.assign(n+5, -1), dist_t.assign(n+5, -1);

	for(int i=0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
	
	q.push(s), vis[s] = true, dist_s[s] = 0;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int u : adj[v])
			if(!vis[u])
				vis[u] = true, q.push(u), parent[u] = v, dist_s[u] = dist_s[v] + 1;
	}	

	vis.assign(n+5, false), parent.assign(n+5, -1);

	q.push(t), vis[t] = true, dist_t[t] = 0;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int u : adj[v])
			if(!vis[u])
				vis[u] = true, q.push(u), parent[u] = v, dist_t[u] = dist_t[v] + 1;
	}

	int count = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			int flag = 1;
			for(int k=0; k<adj[i].size(); k++)
			{
				if(adj[i][k] == j)
				{
					flag = 0;
					break;
				}
			}

			if(flag && dist_s[t] <= dist_s[i] + dist_t[j] + 1 && dist_s[t] <= dist_s[j] + dist_t[i] + 1)
				count++;
		}
	}
	cout << count << endl;
	return 0;
}