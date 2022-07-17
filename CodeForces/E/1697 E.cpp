#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Comb {
	vector<ll> fac;
	vector<ll> invfac;
	ll n;

	Comb (ll n) {
		this->n = n;
		fac.resize(n + 1, 0);
		invfac.resize(n + 1, 0);

		fac[0] = 1;
		for (ll i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
		invfac[n] = power(fac[n], MOD - 2);
		for (ll i = n - 1; i >= 0; i--) invfac[i] = (invfac[i + 1] * (i + 1)) % MOD;
	}

	ll power(ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1) ret = (ret * x) % MOD;
			y >>= 1;
			x = (x * x) % MOD;
		}
		return ret;
	}

	ll nCr(ll n, ll r) {
		if (n < 0 or r < 0 or n < r) return 0;
		ll ans = (fac[n] * ((invfac[r] * invfac[n - r]) % MOD)) % MOD;
		return ans;
	}
};

int solve() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	vector<vector<int>> d(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		}
	}

	vector<vector<int>> mins(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				if (mins[i].size() and d[i][j] < d[i][mins[i][0]]) mins[i].clear();
				if (mins[i].empty() or d[i][j] == d[i][mins[i][0]]) mins[i].push_back(j);
			}
		}
		mins[i].push_back(i);
		sort(mins[i].begin(), mins[i].end());
	}

	vector<bool> done(n, false);
	vector<long long> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; ++i) {
		if (done[i]) continue;
		bool ok = true;
		for (int x : mins[i]) {
			if (mins[i] != mins[x]) {
				ok = false;
				break;
			}
		}

		int sz;
		if (ok) {
			for (int x : mins[i]) done[x] = true;
			sz = mins[i].size();
		} else {
			done[i] = true;
			sz = 1;
		}

		for (int j = n - 1; j >= 0; --j) {
			dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
			if (sz > 1 and j + sz <= n) dp[j + sz] = (dp[j + sz] + dp[j]) % MOD;
			dp[j] = 0;
		}

	}

	long long ans = 0;
	Comb C(n + 5);

	for (int i = 1; i <= n; ++i) {
		long long npr = (C.nCr(n, i) * C.fac[i]) % MOD;
		long long add = (dp[i] * npr) % MOD;
		ans = (ans + add) % MOD;
	}

	cout << ans << endl;
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
