#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Topo {
	int n;
	vector<vector<int>> &adj;
	vector<bool> visited;
	vector<int> topo;

	Topo(vector<vector<int>> &adj) : adj(adj){
		n = adj.size();
		visited.assign(n, false);
		for (int i = 0; i < n; ++i) {
			if (!visited[i])
			dfs(i);
		}
		reverse(topo.begin(), topo.end());
	}

	void dfs(int v) {
		visited[v] = true;
		for (int u : adj[v]) {
			if (!visited[u])
			dfs(u);
		}
		topo.push_back(v);
	}
};
