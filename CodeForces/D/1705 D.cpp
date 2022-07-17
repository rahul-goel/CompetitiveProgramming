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
	ll n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	vector<ll> vecs, vect;

	string ss, tt;
	for (ll i = 0; i < n; ) {
		ll j = i;
		while (j < n and s[j] == s[i]) ++j;
		ss += s[i];
		vecs.push_back(j - i);
		i = j;
	}
	for (ll i = 0; i < n; ) {
		ll j = i;
		while (j < n and t[j] == t[i]) ++j;
		tt += t[i];
		vect.push_back(j - i);
		i = j;
	}

	if (ss != tt) {
		cout << -1 << endl;
		return 0;
	}

	assert(vecs.size() == vect.size());
	vector<ll> delta(vecs.size());
	for (ll i = 0; i < delta.size(); ++i) {
		delta[i] = vecs[i] - vect[i];
	}

	ll ans = 0;
	for (ll i = 0; i < delta.size() - 1; ++i) {
		ans += abs(delta[i]);
		delta[i + 1] += delta[i];
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
