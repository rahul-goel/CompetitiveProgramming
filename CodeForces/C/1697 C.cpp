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

	string s, t;
	cin >> s >> t;

	string ss = s, tt = t;
	sort(ss.begin(), ss.end());
	sort(tt.begin(), tt.end());

	if (ss != tt) {
		cout << "NO" << endl;
		return 0;
	}

	ss = "", tt = "";
	for (int i = 0; i < n; ++i) {
		if (s[i] != 'b') {
			ss += s[i];
		}
		if (t[i] != 'b') {
			tt += t[i];
		}
	}

	if (ss != tt) {
		cout << "NO" << endl;
		return 0;
	}

	map<int,vector<int>> smap, tmap;

	for (int i = 0; i < s.size(); ++i) {
		smap[s[i]].push_back(i);
		tmap[t[i]].push_back(i);
	}

	for (int i = 0; i < smap['a'].size(); i++) {
		if (smap['a'][i] > tmap['a'][i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	for (int i = 0; i < smap['c'].size(); i++) {
		if (smap['c'][i] < tmap['c'][i]) {
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
