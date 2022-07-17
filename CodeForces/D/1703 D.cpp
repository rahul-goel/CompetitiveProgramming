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

	vector<string> vec(n);
	for (string &x : vec) cin >> x;

	set<string> s(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i) {
		bool ok = false;
		for (int len = 1; len <= vec[i].size() - 1; ++len) {
			string pre = vec[i].substr(0, len);
			string suf = vec[i].substr(len);
			if (s.find(pre) != s.end() and s.find(suf) != s.end()) {
				ok = true;
				break;
			}
		}
		cout << (int) ok;
	}
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
