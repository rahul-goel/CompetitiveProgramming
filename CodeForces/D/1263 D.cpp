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

const int N = (int)2e5 + 100;

vector < int > adj[N];
int used[N]; 

void addedge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int v)
{
	used[v] = 1;

	for(int u : adj[v])
	{
		if(!used[u])
			dfs(u);
	}
}

int main()
{
	memset(used, 0, sizeof(used));
	int n;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;

		for(char c : s)
			addedge(i, n+c-'a');
	}

	int count = 0;
	for(int i=n; i<n+26; i++)
	{
		if(!adj[i].empty() && !used[i])
		{
			dfs(i);
			count++;
		}
	}

	cout << count << endl;
	return 0;
}