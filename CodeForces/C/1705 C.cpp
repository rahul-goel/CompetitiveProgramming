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

vector<ll> l, r, len;
string str;

char f(ll pos) {
	for (int i = len.size() - 1; i >= 0; --i) {
		if (pos < len[i]) {
			ll curlen = r[i] - l[i] + 1;
			ll prevlen = len[i] - curlen;
			if (pos >= prevlen) {
				pos = pos - prevlen + l[i];
			}
		}
	}
	return str[pos];
}

ll solve() {
	ll n, c, q;
	cin >> n >> c >> q;

	l.clear(), r.clear(), len.clear();
	l.resize(c), r.resize(c), len.resize(c);
	cin >> str;

	for (ll i = 0; i < c; ++i) {
		cin >> l[i] >> r[i];
		--l[i], --r[i];
		if (i == 0) len[i] = r[i] - l[i] + 1 + str.size();
		else len[i] = r[i] - l[i] + 1 + len[i - 1];
	}

	for (int i = 0; i < q; ++i) {
		ll k;
		cin >> k;
		--k;
		cout << f(k) << endl;
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
