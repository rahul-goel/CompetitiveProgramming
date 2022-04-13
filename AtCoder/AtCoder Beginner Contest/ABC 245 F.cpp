#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

vector<vector<int>> adj, radj;
vector<bool> vis;
vector<int> tin, tout;
vector<int> cycle;

int tiktok = 0;

void dfs(int v) {
	vis[v] = true;
	tin[v] = tiktok++;
	for (int u : adj[v]) {
		if (!vis[u]) {
			dfs(u);
		}
		if (vis[u] and tout[u] == 0 and tin[u] < tin[v]) {
			// this branch
			cycle.push_back(v);
		}
	}
	tout[v] = tiktok++;
}

void solve() {
	int n, m;
	cin >> n >> m;

	adj.resize(n);
	radj.resize(n);
	vis.resize(n);
	tin.resize(n);
	tout.resize(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i);
	}

	queue<int> q;
	vis.clear();
	vis.resize(n, 0);
	for (int v : cycle) q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : radj[v]) {
			if (!vis[u]) {
				q.push(u);
				vis[u] = true;
			}	
		}
	}
	
	cout << count(vis.begin(), vis.end(), true) << endl;
	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
