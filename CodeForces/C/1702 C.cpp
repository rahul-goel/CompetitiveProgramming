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

struct query {
	int a, b, idx;
};

int solve() {
	int n, q;
	cin >> n >> q;

	vector<int> vec(n);
	for (int &x : vec) cin >> x;

	map<int,int> first, last;

	for (int i = 0; i < n; ++i) {
		last[vec[i]] = i;
	}

	for (int i = n - 1; i >= 0; --i) {
		first[vec[i]] = i;
	}
	
	vector<query> queries;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		if (first.find(a) == first.end() or last.find(b) == last.end()) {
			cout << "NO" << endl;
		} else {
			cout << (first[a] < last[b] ? "YES" : "NO") << endl;
		}
	}

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
