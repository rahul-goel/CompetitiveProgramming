#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CycleFind {
	int n;
	vector<vector<int>> &adj;
	vector<char> color;
	vector<int> parent;
	vector<int> cycle;

	int cycle_start = -1;
	int cycle_end = -1;

	bool cycle_exist = false;

	CycleFind(vector<vector<int>> &adj) : adj(adj){
		n = adj.size();
		color.assign(n, 0);
		parent.assign(n, -1);
		cycle_start = -1;

		for (int v = 0; v < n; v++) {
			if (color[v] == 0 && dfs(v))
				break;
		}

		cycle_exist = (cycle_start != -1);
		if (cycle_exist) {
			cycle.push_back(cycle_start);
			for (int v = cycle_end; v != cycle_start; v = parent[v])
				cycle.push_back(v);
			reverse(cycle.begin(), cycle.end());
		}
	}

	bool dfs(int v) {
		color[v] = 1;
		for (int u : adj[v]) {
			if (color[u] == 0) {
				parent[u] = v;
				if (dfs(u))
				return true;
			} else if (color[u] == 1) {
				cycle_end = v;
				cycle_start = u;
				return true;
			}
		}
		color[v] = 2;
		return false;
	}
};
