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
	vector<int> b(n);
	for (int &x : b) cin >> x;
	vector<int> l(n), r(n);

	for (int i = 1; i <= n; ++i) {
		int val = b[i - 1];
		l[i - 1] = i / (val + 1) + 1;
		r[i - 1] = (val == 0 ? n : i / val);
	}

	set<int> s;
	for (int i = 1; i <= n; ++i) s.insert(i);

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&l, &r] (const int &a, const int &b) {
		return make_pair(r[a], -l[a]) < make_pair(r[b], -l[b]);
	});

	vector<int> a(n);
	for (int i : ord) {
		auto it = s.lower_bound(l[i]);
		a[i] = *it;
		s.erase(it);
	}

	for (int i = 0; i < n; ++i) cout << a[i] << " ";
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
