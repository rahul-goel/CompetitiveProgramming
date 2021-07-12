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

struct SegmentTree {
	vector<ll> t;

	SegmentTree(ll n) {
		t.resize(n << 2);
	}

	void build(ll v, ll tl, ll tr, vector<ll> &a) {
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			ll tm = (tl + tr) >> 1;
			build(v << 1, tl, tm, a);
			build(v << 1 | 1, tm + 1, tr, a);
			t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
		}
	}

	ll query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			ll ret = 0;
			ll tm = (tl + tr) >> 1;
			if (ql <= tm) {
				ret = __gcd(ret, query(v << 1, tl, tm, ql, qr));
			}
			if (tm + 1 <= qr) {
				ret = __gcd(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			}
			return ret;
		}
	}
};

ll solve() {
	ll n;
	cin >> n;
	vector<ll> vec(n);
	for (ll i = 0; i < n; i++) cin >> vec[i];

	ll g = 0;
	for (ll i = 0; i < n; i++) g = __gcd(vec[i], g);

	vector<ll> xtravec(n << 1);
	for (ll i = 0; i < n; i++) {
		xtravec[i] = xtravec[i + n] = vec[i];
	}

	SegmentTree st(2 * n);
	st.build(1, 0, 2 * n - 1, xtravec);

	ll ans = 0;
	ll left = 0, right = n, mid;
	while (left <= right) {
		mid = (left + right) >> 1;

		vector<ll> v(n);
		for (ll i = 0; i < n; i++) {
			v[i] = st.query(1, 0, 2 * n - 1, i, i + mid);
		}
		bool ok = true;
		for (ll &x : v) ok = ok and (x == v.front());

		if (ok) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
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
