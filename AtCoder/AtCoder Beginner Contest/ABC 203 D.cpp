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

ll mat[805][805];
ll pre[805][805];
ll n, k;

bool f(ll med) {
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) pre[i][j] = (ll) mat[i][j] <= med;
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
	ll mx = -LINF;
	for (ll i = k; i <= n; i++) for (ll j = k; j <= n; j++) mx = max(mx, pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k]);
	return mx >= (k * k + 1) / 2;
}

ll solve() {
	cin >> n >> k;

	vector<ll> vec;
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) cin >> mat[i][j], vec.push_back(mat[i][j]);

	sort(all(vec));
	uniq(vec);

	ll left = 0, right = vec.size() - 1, mid;
	ll ans = -1;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (f(vec[mid])) ans = vec[mid], right = mid - 1;
		else left = mid + 1;
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
