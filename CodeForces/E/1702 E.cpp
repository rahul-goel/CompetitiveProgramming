#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<vector<int>> idx(n);

	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		idx[u].push_back(i);
		idx[v].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		if (idx[i].size() != 2) {
			cout << "NO" << endl;
			return 0;
		}
		int u = idx[i][0];
		int v = idx[i][1];
		if (u == v) {
			cout << "NO" << endl;
			return 0;
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> side(n, -1);
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 0; st < n; ++st) {
		if (side[st] == -1) {
			q.push(st);
			side[st] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : adj[v]) {
					if (side[u] == -1) {
						side[u] = side[v] ^ 1;
						q.push(u);
					} else {
						is_bipartite &= side[u] != side[v];
					}
				}
			}
		}
	}

	cout << (is_bipartite ? "YES" : "NO") << endl;
	return 0;
}

signed main() {
	fastio;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
