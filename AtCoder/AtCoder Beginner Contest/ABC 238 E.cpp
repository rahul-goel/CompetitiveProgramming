#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <queue>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u - 1].push_back(v);
		adj[v].push_back(u - 1);
	}

	queue<int> q;
	q.push(0);
	vector<bool> vis(n + 1);
	vis[0] = true;

	while (q.size()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!vis[u]) {
				q.push(u);
				vis[u] = true;
			}
		}
	}

	if (vis[n]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
