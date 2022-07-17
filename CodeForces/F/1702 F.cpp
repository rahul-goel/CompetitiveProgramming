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

	multiset<int> a, b;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		while (val % 2 == 0) val /= 2;
		a.insert(val);
	}
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		while (val % 2 == 0) val /= 2;
		b.insert(val);
	}

	while (b.size()) {
		auto it1 = b.begin();
		int val = *it1;
		while (val) {
			auto it2 = a.find(val);
			if (it2 != a.end()) {
				a.erase(it2);
				b.erase(it1);
				break;
			}
			val /= 2;
		}
		if (val == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

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
