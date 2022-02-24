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
	vector<pii> t;
	ll n;

	SegmentTree(ll n) {
		this->n = n;
		t.resize(n << 2);
	}

	pii merge(pii a, pii b) {
		if (a.ff < b.ff) return a;
		else return b;
	}

	void build(ll v, ll tl, ll tr) {
		if (tl == tr) {
			t[v] = {LINF, tl};
		} else {
			ll tm = (tl + tr) >> 1;
			build(v << 1, tl, tm);
			build(v << 1 | 1, tm + 1, tr);
			t[v] = merge(t[v << 1], t[v << 1 | 1]);
		}
	}

	void build() {
		build(1, 0, n - 1);
	}

	void update(ll v, ll tl, ll tr, ll pos, ll val) {
		if (tl == tr) {
			t[v] = {val, tl};
		} else {
			ll tm = (tl + tr) >> 1;
			if (pos <= tm) update(v << 1, tl, tm, pos, val);
			else update(v << 1 | 1, tm + 1, tr, pos, val);
			t[v] = merge(t[v << 1], t[v << 1 | 1]);
		}
	}

	void update(ll pos, ll val) {
		return update(1, 0, n - 1, pos, val);
	}

	pii query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			pii ret = {LINF, -1};
			ll tm = (tl + tr) >> 1;
			if (ql <= tm) ret = merge(ret, query(v << 1, tl, tm, ql, qr));
			if (tm + 1 <= qr) ret = merge(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			return ret;
		}
	}

	pii query(ll ql, ll qr) {
		return query(1, 0, n - 1, ql, qr);
	}
};

ll solve() {
	ll n, q;
	cin >> n >> q;

	SegmentTree st(n);
	st.build();

	for (ll i = 0; i < q; i++) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll i, h;
			cin >> i >> h;
			st.update(i, h);
		} else {
			ll l, r, p;
			cin >> l >> r >> p;
			--r;
			ll ans = 0;
			while (true) {
				pii query_result = st.query(l, r);
				if (query_result.ff <= p) st.update(query_result.ss, LINF), ++ans;
				else break;
			}
			cout << ans << endl;
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
