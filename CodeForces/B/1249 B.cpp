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

const int N = (int) 2e5 + 10;

int adj[N], vis[N], depth[N];

void addedge(int v, int u)
{
	adj[v] = u;
}

int dfs(int v)
{
	if(vis[v])
		return 0;
	vis[v] = 1;
	return 1 + dfs(adj[v]);
}

int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		memset(adj, 0, sizeof(adj));
		memset(vis, 0, sizeof(vis));
		memset(depth, 0, sizeof(depth));

		int n;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			int temp;
			cin >> temp;
			addedge(i, temp);
		}

		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				int d = dfs(i);
				int node = i;
				depth[node] = d;
				node = adj[node];
				while(node != i)
					depth[node] = d, node = adj[node];
			}
		}

		for(int i=1; i<=n; i++)
			cout << depth[i] << ' ';
		cout << endl;
	}
	return 0;
}