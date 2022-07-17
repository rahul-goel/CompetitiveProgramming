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
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

map<pair<int,int>,int> q2hash;

char q1(int idx) {
	cout << "? 1 " << idx + 1 << endl;
	char x;
	cin >> x;
	return x;
}

int q2(int l, int r) {
	if (q2hash.count(make_pair(l, r))) {
		return q2hash[make_pair(l, r)];
	}
	cout << "? 2 " << l + 1 << " " << r + 1 << endl;
	int cnt;
	cin >> cnt;
	q2hash[make_pair(l, r)] = cnt;
	return cnt;
}

int solve() {
	int n;
	cin >> n;

	string str;
	str += q1(0);

	map<char,int> last;
	last[str[0]] = 0;

	while (str.size() < n) {
		vector<int> idxs;
		for (auto &[key, val] : last) idxs.push_back(val);
		sort(idxs.begin(), idxs.end());
		int left = 0, right = idxs.size() - 1;
		int cur = -1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (q2(idxs[mid], str.size()) == idxs.size() - mid + 1) {
				right = mid - 1;
			} else {
				cur = mid;
				left = mid + 1;
			}
		}
		if (cur == -1) {
			str.push_back(q1(str.size()));
		} else {
			str += str[idxs[cur]];
		}
		last[str.back()] = str.size() - 1;
	}

	cout << "! " << str << endl;
	return 0;
}

signed main() {
	fastio;

	ll t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
