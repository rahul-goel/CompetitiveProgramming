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
	vector<int> vec(n);
	for (int &x : vec) cin >> x;

	ll sum = 0;
	int nz = 0;
	for (int i = 0; i < n - 1; ++i) {
		nz += (vec[i] == 0);
		sum += vec[i];
	}

	int trailing = 0;
	for (int i = 0; i < n - 1 and vec[i] == 0; ++i) {
		trailing += 1;
	}

	cout << sum + nz - trailing << endl;

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
