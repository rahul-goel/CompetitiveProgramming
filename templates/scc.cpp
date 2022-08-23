#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct SCC {
	vector<vector<int>> &adj;
	vector<vector<int>> rev_adj, comp;
	vector<int> ord;
	vector<int> root;
	int n;
	int ssc_cnt = 0;

	SCC(vector<vector<int>> &adj) : adj(adj), n(adj.size()) {
		rev_adj.resize(n);
		comp.resize(n);
		root.resize(n);
		for (int v = 0; v < n; ++v) {
			for (int &u : adj[v]) {
				rev_adj[u].push_back(v);
			}
		}

		get_ssc();
	}

	void get_ssc() {
		vector<bool> vis(n, false);
		for (int v = 0; v < n; ++v) {
			if (!vis[v]) {
				dfs1(v, vis);
			}
		}
		reverse(ord.begin(), ord.end());

		vis.assign(n, false);
		for (int &v : ord) {
			if (!vis[v]) {
				++ssc_cnt;
				dfs2(v, vis, comp[v]);
				for (int &u : comp[v]) {
					root[u] = v;
				}
			}
		}
	}

	void dfs1(int v, vector<bool> &vis) {
		vis[v] = true;
		for (int &u : adj[v]) {
			if (!vis[u]) {
				dfs1(u, vis);
			}
		}
		ord.push_back(v);
	}

	void dfs2(int v, vector<bool> &vis, vector<int> &comp) {
		vis[v] = true;
		comp.push_back(v);
		for (int &u : rev_adj[v]) {
			if (!vis[u]) {
				dfs2(u, vis, comp);
			}
		}
	}
};
