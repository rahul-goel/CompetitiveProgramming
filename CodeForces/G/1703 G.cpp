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
	long long n, k;
	cin >> n >> k;
	vector<long long> vec(n);
	for (long long &x : vec) cin >> x;
	reverse(vec.begin(), vec.end());

	vector<long long> suf(n);
	suf.back() = vec.back();
	for (long long i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + vec[i];
	suf.push_back(0);

	long long ans = -LINF;
	for (long long bad = 0; bad <= n; ++bad) {
		long long curans = 0;
		long long good = n - bad;
		curans += suf[n - good] - (long long) good * k;
		long long div = 2;
		for (long long i = bad - 1, j = 0; i >= 0 and j < 32; --i, ++j) {
			curans += vec[i] / div;
			div *= 2;
		}
		ans = max(ans, curans);
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
