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
	int n, s;
	cin >> n >> s;

	vector<int> vec(n);
	for (int &x : vec) cin >> x;
	for (int i = 1; i < n; ++i) vec[i] += vec[i - 1];

	int ans = -INF;
	map<int,int> idx;
	idx[0] = -1;

	for (int i = 0; i < n; ++i) {
		if (idx.count(vec[i] - s)) {
			ans = max(ans, i - idx[vec[i] - s]);
		}
		if (!idx.count(vec[i])) idx[vec[i]] = i;
	}

	cout << (ans == -INF ? -1 : n - ans) << endl;
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
