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
vector < int > start, dest;
int vis[55*55] = {0}, n;

int num(int x, int y)
{
	return (x-1)*n + y;
}

void addedge(int v, int u)
{
	adj[v].push_back(u);
}
 
void dfs1(int v)
{
	if(vis[v])
		return ;
	vis[v] = 1, start.push_back(v);
	for(int u : adj[v])
		dfs1(u);
}

void dfs2(int v)
{
	if(vis[v])
		return ;
	vis[v] = 1, dest.push_back(v);
	for(int u : adj[v])
		dfs2(u);	
}

int main()
{
	int mat[55][55], sr, sc, dr, dc;
	memset(mat, 1, sizeof(mat));
	cin >> n;
	adj.resize((n+5)*(n+5));
	cin >> sr >> sc >> dr >> dc;
	
	for(int i=1; i<=n; i++)
	{
		string str;
		cin >> str;
		for(int j=1; j<=n; j++)
			mat[i][j] = str[j-1]-'0';
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(mat[i][j] == 0)
			{
				if(mat[i+1][j] == 0)
					addedge(num(i, j), num(i+1, j));
				if(mat[i][j+1] == 0)
					addedge(num(i, j), num(i, j+1));
				if(mat[i-1][j] == 0)
					addedge(num(i, j), num(i-1, j));
				if(mat[i][j-1] == 0)
					addedge(num(i, j), num(i, j-1));
			}
		}
	}

	dfs1(num(sr, sc)), dfs2(num(dr, dc));

	int ans = 1000000000;

	// for(int g : start)
	// 	cout << g << ' ';
	// cout << endl;
	// for(int g : dest)
	// 	cout << g << ' ';
	// cout << endl;

	for(int g : start)
	{
		if(g == num(dr, dc))
		{
			ans = 0;
			break;
		}
		for(int h : dest)
		{
			int x1 = (g-1)/n, y1 = (g-1)%n + 1, x2 = (h-1)/n, y2 = (h-1)%n + 1;
			ans = min(ans, (int)(pow(x1-x2, 2) + pow(y1-y2, 2)));
		}
	}
	cout << ans << endl;
	return 0;
}