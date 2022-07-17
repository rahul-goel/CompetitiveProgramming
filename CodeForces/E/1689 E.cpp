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

bool connected(vector<int> &vec) {
	int n = vec.size();
	vector<set<int>> adj(32);

	int mask = 0;
	for (int x : vec) {
		mask |= x;
		vector<int> bits;
		while (x) {
			int bit = x & -x;
			bits.push_back(__builtin_popcount(bit - 1));
			x = x & (~bit);
		}
		for (int i = 1; i < bits.size(); ++i) {
			int b1 = bits[i - 1];
			int b2 = bits[i];
			adj[b1].insert(b2);
			adj[b2].insert(b1);
		}
	}

	queue<int> q;
	vector<int> vis(32);
	for (int i = 0; i < 30; ++i) {
		if (mask >> i & 1) {
			q.push(i);
			vis[i] = 1;
			break;
		}
	}

	while (q.size()) {
		int bit = q.front();
		q.pop();

		for (int u : adj[bit]) {
			if (!vis[u]) {
				q.push(u);
				vis[u] = 1;
			}
		}
	}

	for (int i = 0; i < 30; ++i) {
		if ((mask >> i & 1) and !vis[i]) {
			return false;
		}
	}
	return true;
}

int solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int &x : vec) cin >> x;

	int ans = 0;
	for (int &x : vec) {
		if (x == 0) {
			ans += 1;
			x += 1;
		}
	}

	if (connected(vec)) {
		cout << ans << endl;
		for (int &x : vec) cout << x << " ";
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		vec[i] += 1;
		if (connected(vec)) {
			cout << ans + 1 << endl;
			for (int &x : vec) cout << x << " ";
			cout << endl;
			return 0;
		}
		vec[i] -= 1;
	}

	for (int i = 0; i < n; ++i) {
		vec[i] -= 1;
		if (connected(vec)) {
			cout << ans + 1 << endl;
			for (int &x : vec) cout << x << " ";
			cout << endl;
			return 0;
		}
		vec[i] += 1;
	}

	vector<int> idxs;
	for (int i = 0; i < n; ++i) {
		if (idxs.size() == 0) {
			idxs.push_back(i);
		} else if ((vec[idxs[0]] & -vec[idxs[0]]) == (vec[i] & -vec[i])) {
			idxs.push_back(i);
		} else if ((vec[idxs[0]] & -vec[idxs[0]]) < (vec[i] & -vec[i])) {
			idxs.clear();
			idxs.push_back(i);
		}
	}

	assert(idxs.size() >= 2);
	vec[idxs[0]] -= 1;
	vec[idxs[1]] += 1;

	cout << ans + 2 << endl;
	for (int &x : vec) cout << x << " ";
	cout << endl;

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
