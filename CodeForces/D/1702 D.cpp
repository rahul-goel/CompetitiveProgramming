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
	string str;
	cin >> str;
	int p;
	cin >> p;

	string store = str;

	sort(str.begin(), str.end());
	int sum = 0;
	for (char &x : str) sum += (x - 'a' + 1);

	multiset<char> rmv;
	while (sum > p) {
		sum -= (str.back() - 'a' + 1);
		rmv.insert(str.back());
		str.pop_back();
	}

	str = store;
	vector<bool> ers(str.size());
	for (int i = 0; i < ers.size(); ++i) {
		auto it = rmv.find(str[i]);
		if (it != rmv.end()) {
			ers[i] = true;
			rmv.erase(it);
		}
	}

	string ans;
	for (int i = 0; i < str.size(); ++i) {
		if (not ers[i]) {
			ans += str[i];
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
