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
	int n, k;
	cin >> n >> k;

	vector<long long> vec(n + 1);
	vec[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i];
	}

	vector<int> check(n + 1);
	for (int i = 1; i <= n; ++i) {
		if (vec[i] * 2 > vec[i - 1]) {
			check[i] = 1;
		}
		check[i] += check[i - 1];
	}

	int ans = 0;
	for (int i = 1; i <= n - k; ++i) {
		int sum = check[i + k] - check[i];
		ans += sum == k;
	}

	cout << ans << endl;

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
