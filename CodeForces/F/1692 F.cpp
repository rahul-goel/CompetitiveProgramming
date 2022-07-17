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

vector<array<int,3>> trip;

int solve() {
	int cnt[10] = {0};
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x % 10];
	}

	for (auto arr : trip) {
		for (int i = 0; i < 3; ++i) {
			--cnt[arr[i]];
		}
		bool ok = true;
		for (int i = 0; i < 10; ++i) {
			if (cnt[i] < 0) {
				ok = false;
			}
		}

		if (ok) {
			cout << "YES" << endl;
			return 0;
		}

		for (int i = 0; i < 3; ++i) {
			++cnt[arr[i]];
		}
	}

	cout << "NO" << endl;
	return 0;
}

signed main() {
	fastio;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				if ((i + j + k) % 10 == 3) {
					trip.push_back({i, j, k});
				}
			}
		}
	}

	ll t = 1;
	cin >> t;
	while (t--) {
	solve();
	}
	return 0;
}
