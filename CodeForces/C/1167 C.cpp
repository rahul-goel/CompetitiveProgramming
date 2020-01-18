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

const int N = (int)5e5 + 10;

vector < int > adj[N], vis1, vis2, ans; 

void addedge(int v, int u)
{
	adj[u].push_back(v), adj[v].push_back(u); 
}

int dfs1(int v)
{
	if(vis1[v])
		return 0;
	vis1[v] = 1;

	int cnt = 1;
	for(int u : adj[v])
		cnt += dfs1(u);
	return cnt;
}

void dfs2(int v, int r)
{
	if(vis2[v])
		return ;
	vis2[v] = 1, ans[v] = r;
	for(int u : adj[v])
		dfs2(u, r);
	return ;
}

int main()
{
	vis1.resize(N, 0), vis2.resize(N, 0), ans.resize(N, 0);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int k, first;
		cin >> k;
		if(k!=0)
		{
			cin >> first;
			k--;
		}
		while(k--)
		{
			int temp;
			cin >> temp;
			addedge(first, temp);
		}
	}

	for(int i=1; i<=n; i++)
	{
		if(!vis1[i])
		{
			int r = dfs1(i);
			dfs2(i, r);
		}
	}
	for(int i=1; i<=n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}