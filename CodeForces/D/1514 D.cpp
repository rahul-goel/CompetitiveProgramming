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

vector<vector<ll>> ind(300005);

ll cnt(ll l, ll r, ll val) {
	return upper_bound(all(ind[val]), r) - lower_bound(all(ind[val]), l);
}

struct SegmentTree {
	vector<ll> t;

	SegmentTree(ll n) { t.resize(n << 2); }

	void merge(ll v, ll l, ll r) {
		if (cnt(l, r, t[v << 1]) > cnt(l, r, t[v << 1 | 1])) {
			t[v] = t[v << 1];
		} else {
			t[v] = t[v << 1 | 1];
		}
	}

	void build(ll v, ll tl, ll tr, vector<ll> &a) {
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			ll tm = (tl + tr) >> 1;
			build(v << 1, tl, tm, a);
			build(v << 1 | 1, tm + 1, tr, a);
			merge(v, tl, tr);
		}
	}

	ll query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return cnt(ql, qr, t[v]);
		} else {
			ll tm = (tl + tr) >> 1;
			ll a = 0, b = 0;
			if (ql <= tm) {
				a = query(v << 1, tl, tm, ql, qr);
			}
			if (tm + 1 <= qr) {
				b = query(v << 1 | 1, tm + 1, tr, ql, qr);
			}
			return max(a, b);
		}
	}
};

ll solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> vec(n);

	for (ll i = 0; i < n; i++) {
		cin >> vec[i];
		ind[vec[i]].push_back(i);
	}

	SegmentTree st(n);
	st.build(1, 0, n - 1, vec);

	while (q--) {
		ll l, r;
		cin >> l >> r;
		--l, --r;
		ll x = st.query(1, 0, n - 1, l, r);
		ll len = r - l + 1;
		ll c = (len + 1) / 2;
		if (x > c) {
			cout << 2 * x - len << endl;
		} else {
			cout << 1 << endl;
		}
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
