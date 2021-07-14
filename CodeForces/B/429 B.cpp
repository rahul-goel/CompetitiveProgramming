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

ll mat[1005][1005];
ll one[1005][1005];
ll two[1005][1005];
ll three[1005][1005];
ll four[1005][1005];

ll solve() {
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) cin >> mat[i][j];

	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) one[i][j] = max(one[i - 1][j], one[i][j - 1]) + mat[i][j];
	for (ll i = n; i >= 1; i--) for (ll j = 1; j <= m; j++) two[i][j] = max(two[i + 1][j], two[i][j - 1]) + mat[i][j];
	for (ll i = n; i >= 1; i--) for (ll j = m; j >= 1; j--) three[i][j] = max(three[i + 1][j], three[i][j + 1]) + mat[i][j];
	for (ll i = 1; i <= n; i++) for (ll j = m; j >= 1; j--) four[i][j] = max(four[i - 1][j], four[i][j + 1]) + mat[i][j];

	ll ans = 0;
	for (ll i = 2; i < n; i++) {
		for (ll j = 2; j < m; j++) {
			ans = max(ans, one[i - 1][j] + two[i][j - 1] + three[i + 1][j] + four[i][j + 1]);
			ans = max(ans, one[i][j - 1] + two[i + 1][j] + three[i][j + 1] + four[i - 1][j]);
		}
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
