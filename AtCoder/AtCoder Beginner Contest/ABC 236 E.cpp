/*
	Created by Rahul Goel.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*******************************************************************************/
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*******************************************************************************/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template < typename T, typename... Args >
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%MOD + MOD)%MOD; }
/*******************************************************************************/
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a * mod_prod(args...))%MOD; }
/*******************************************************************************/
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
	Code begins after this.
*/

bool avgcheck(vector<int> &vec, ld mid) {
	int n = vec.size();
	vector<ld> v(vec.begin(), vec.end());
	for (auto &x : v) x -= mid;
	vector<vector<ld>> dp(n, vector<ld>(2));

	dp[0][0] = 0;
	dp[0][1] = v[0];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + v[i];
	}

	return max(dp.back()[0], dp.back()[1]) >= (ld)0;
}

bool medcheck(vector<int> &vec, ld mid) {
	int n = vec.size();
	vector<int> v(vec.begin(), vec.end());
	for (auto &x : v) x = (x >= mid ? 1 : -1);
	vector<vector<int>> dp(n, vector<int>(2));

	dp[0][0] = 0;
	dp[0][1] = v[0];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + v[i];
	}

	return max(dp.back()[0], dp.back()[1]) > (ld)0;
}

int solve() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int &x : vec) cin >> x;

	{
		ld left = 0, right = 1e18;
		while (abs(right - left) > 1e-5) {
			ld mid = (right + left) / 2;
			if (avgcheck(vec, mid)) {
				left = mid;
			} else {
				right = mid;
			}
		}

		cout << fixed << setprecision(5) << left << endl;
	}

	{
		int left = 0, right = 1e9 + 5, ans = -1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (medcheck(vec, mid)) {
				ans = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		cout << ans << endl;
	}
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
