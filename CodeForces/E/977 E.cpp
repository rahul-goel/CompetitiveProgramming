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

void add_edge(int u, int v)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}

int dfs(int v)
{
	int flag = 0;
	vis[v] = 1;
	if(adj[v].size() == 2)
		flag = 1;
	for(int u : adj[v])
	{
		if(!vis[u])
		{
			//cout << v << " is v and u is " << u << endl;
			int newflag = dfs(u);
			flag = flag && newflag;
		}
	}
	return flag;
}


int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n+5), vis.resize(n+5, 0);
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		add_edge(x, y);
	}

	int count = 0;

	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			if(dfs(i) == 1)
			{
				//cout << i << " is cyclic" << endl;
				count ++;
			}
		}
		
	}
	cout << count << endl;
	return 0;
}