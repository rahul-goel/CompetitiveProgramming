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
const int INF = 1e9;
const ll LINF = 1e18;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char x;
			cin >> x;
			vec[i][j] = x == 'B';
		}
	}
	vector<vector<int>> TL(n, vector<int>(m));
	vector<vector<int>> TR(n, vector<int>(m));
	vector<vector<int>> BL(n, vector<int>(m));
	vector<vector<int>> BR(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i - 1 >= 0 and TL[i - 1][j]) TL[i][j] = max(TL[i][j], TL[i - 1][j] + 1);
			if (i - 1 >= 0 and vec[i - 1][j]) TL[i][j] = max(TL[i][j], 1);
			if (j - 1 >= 0 and TL[i][j - 1]) TL[i][j] = max(TL[i][j], TL[i][j - 1] + 1);
			if (j - 1 >= 0 and vec[i][j - 1]) TL[i][j] = max(TL[i][j], 1);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i - 1 >= 0 and TR[i - 1][j]) TR[i][j] = max(TR[i][j], TR[i - 1][j] + 1);
			if (i - 1 >= 0 and vec[i - 1][j]) TR[i][j] = max(TR[i][j], 1);
			if (j + 1 < m and TR[i][j + 1]) TR[i][j] = max(TR[i][j], TR[i][j + 1] + 1);
			if (j + 1 < m and vec[i][j + 1]) TR[i][j] = max(TR[i][j], 1);
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			if (i + 1 < n and BL[i + 1][j]) BL[i][j] = max(BL[i][j], BL[i + 1][j] + 1);
			if (i + 1 < n and vec[i + 1][j]) BL[i][j] = max(BL[i][j], 1);
			if (j - 1 >= 0 and BL[i][j - 1]) BL[i][j] = max(BL[i][j], BL[i][j - 1] + 1);
			if (j - 1 >= 0 and vec[i][j - 1]) BL[i][j] = max(BL[i][j], 1);
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i + 1 < n and BR[i + 1][j]) BR[i][j] = max(BR[i][j], BR[i + 1][j] + 1);
			if (i + 1 < n and vec[i + 1][j]) BR[i][j] = max(BR[i][j], 1);
			if (j + 1 < m and BR[i][j + 1]) BR[i][j] = max(BR[i][j], BR[i][j + 1] + 1);
			if (j + 1 < m and vec[i][j + 1]) BR[i][j] = max(BR[i][j], 1);
		}
	}

	int ans = INF;
	int x = 1, y = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (max({TL[i][j], TR[i][j], BL[i][j], BR[i][j]}) < ans) {
				ans = max({TL[i][j], TR[i][j], BL[i][j], BR[i][j]});
				x = i + 1, y = j + 1;
			}
		}
	}

	cout << x << " " << y << endl;

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
