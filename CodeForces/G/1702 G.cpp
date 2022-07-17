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

int tiktok = 0;
const int L = 20;

vector<vector<int>> adj, up;
vector<int> tin, tout;

void dfs(int v, int p) {
	tin[v] = tiktok++;
	up[v][0] = p;
	for (int i = 1; i <= L; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	tout[v] = tiktok++;
}

bool is_ancestor(int up, int low) {
	return tin[low] >= tin[up] and tout[low] <= tout[up];
}

int lca(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (int i = L; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int solve() {
	int n;
	cin >> n;

	adj.resize(n);
	tin.resize(n);
	tout.resize(n);
	up.resize(n);
	up.assign(n, vector<int>(L + 1));

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);

	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		vector<int> vec(k);
		for (int &x : vec) cin >> x, --x;
		sort(vec.begin(), vec.end(), [](int &x, int &y) { return tin[x] < tin[y]; });
		int miscnt = 0;
		bool ok = true;
		for (int i = 1; i < k; ++i) {
			int prev = vec[i - 1];
			int cur = vec[i];
			if (not is_ancestor(prev, cur)) {
				++miscnt;
				if (lca(prev, cur) != lca(cur, vec[0])) {
					ok = false;
				}
			}
		}
		if (miscnt > 1) ok = false;
		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}

signed main() {
	fastio;

	ll t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
