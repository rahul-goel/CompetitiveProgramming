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

ll possible(vector<ll> &freq, ll time) {
	ll done = 0;
	for (ll f : freq) {
		if (time >= f) done += f + (time - f) / 2;
		else done += time;
	}
	return done;
}

int solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> vec(m);
	for (ll &x : vec) cin >> x, --x;

	vector<ll> freq(n);
	for (ll &x : vec) freq[x]++;

	ll left = 0, right = 1e8, ans = 2 * m;
	while (left <= right) {
		ll mid = (left + right) >> 1;
		if (possible(freq, mid) >= m) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
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
