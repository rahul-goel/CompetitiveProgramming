#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <queue>
#include <map>

using namespace std;
const int INF = 1000000000;

vector<vector<pair<int,int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	adj.resize(n);
	vector<vector<int>> edges;

	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		edges.push_back({u, v, c});
	}

	vector<vector<int>> dis(n, vector<int>(n));
	vector<vector<int>> par(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		dijkstra(i, dis[i], par[i]);
	}

	int ans = 0;
	for (auto edge : edges) {
		int u = edge[0], v = edge[1], c = edge[2];
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			if (i != u and i != v and dis[u][i] + dis[i][v] <= c) {
				flag = true;
				break;
			}
		}
		ans += flag;
	}

	cout << ans << endl;
	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
