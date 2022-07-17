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
	int mat[8][8];

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			char x;
			cin >> x;
			mat[i][j] = x == '#';
		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (mat[i - 1][j - 1] and mat[i - 1][j + 1] and mat[i + 1][j - 1] and mat[i + 1][j + 1] and mat[i][j]) {
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		}
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
