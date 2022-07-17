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
	set<int> s;
	for (int i = 1; i <= n; ++i) s.insert(i);

	vector<int> ans;
	for (int i = 1; i <= n; i = i << 1) {
		ans.push_back(i);
		s.erase(i);
	}

	while (s.size()) {
		int x = ans.back();
		if (s.find(x * 2) != s.end()) {
			ans.push_back(x * 2);
			s.erase(x * 2);
		} else {
			ans.push_back(*s.begin());
			s.erase(s.begin());
		}
	}

	cout << 2 << endl;
	for (int x : ans) cout << x << " ";
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
