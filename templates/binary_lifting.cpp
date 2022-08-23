#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct BinaryLifting {
	vector<vector<int>> adj, par;
	vector<int> tin, tout, dep, sz;
	int n = 0, L = 0, tiktok = 0;

	BinaryLifting(vector<vector<int>> &adjacency_list, int root = 0) {
		n = adjacency_list.size();
		L = ceil(log2(n));
		adj = adjacency_list;
		tin.resize(n), tout.resize(n), dep.resize(n), sz.resize(n);
		par.resize(n, vector<int>(L + 1));
		dfs(root, root);
	}

	void dfs(int v, int p) {
		tin[v] = tiktok++;
		par[v][0] = p;
		dep[v] = dep[p] + 1;
		sz[v] = 1;
		for (int i = 1; i <= L; ++i) {
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
		for (int &u : adj[v]) {
			if (u != p) {
				dfs(u, v);
				sz[v] += sz[u];
			}
		}
		tout[v] = tiktok++;
	}

	bool is_ancestor(int up, int low) {
		return tin[up] <= tin[low] and tout[low] <= tout[up];
	}

	int getlca(int u, int v) {
		if (is_ancestor(u, v)) return u;
		if (is_ancestor(v, u)) return v;

		for (int i = L; i >= 0; --i) {
			if (not is_ancestor(par[u][i], v)) {
				u = par[u][i];
			}
		}
		return par[u][0];
	}

	int kth(int u, int k) {
		assert(k >= 0);
		for (int i = 0; i <= L; ++i) {
			if (k >> i & 1) {
				u = par[u][i];
			}
		}
		return u;
	}

	int dist(int u, int v) {
		int l = getlca(u, v);
		return dep[u] + dep[v] - dep[l] * 2;
	}
};
