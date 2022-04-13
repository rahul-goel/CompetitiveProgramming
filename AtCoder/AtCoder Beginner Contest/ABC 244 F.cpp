#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

vector<vector<int>> adj(17);
int dist[1 << 17][17];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int N = 1 << n;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = 1e9;
	queue<pair<int,int>> q;
	for (int i = 0; i < n; ++i) {
		dist[1 << i][i] = 1;
		q.push({1 << i, i});
	}

	while (!q.empty()) {
		int s = q.front().first;
		int v = q.front().second;
		q.pop();
		for (int u : adj[v]) {
			int ns = s ^ (1 << u);
			if (dist[ns][u] > dist[s][v] + 1) {
				dist[ns][u] = dist[s][v] + 1;
				q.push({ns, u});
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i < N; ++i) {
		ans += *min_element(dist[i], dist[i] + n);
	}
	cout << ans << endl;
	return;
}

int main() {
	int t = 1;
	while (t--) solve();
	return 0;
}
