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

vector<vector<int>> rotate(vector<vector<int>> mat) {
	auto res = mat;
	int n = mat.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i][j] = mat[j][n - i - 1];
		}
	}
	return res;
}

int solve() {
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j) {
			mat[i][j] = str[j] - '0';
		}
	}

	auto &mat1 = mat;
	auto mat2 = rotate(mat1);
	auto mat3 = rotate(mat2);
	auto mat4 = rotate(mat3);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int cnt[2] = {0, 0};
			cnt[mat1[i][j]]++;
			cnt[mat2[i][j]]++;
			cnt[mat3[i][j]]++;
			cnt[mat4[i][j]]++;
			ans += min(cnt[0], cnt[1]);
		}
	}

	cout << ans / 4 << endl;
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
