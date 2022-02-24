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
	vector<ll> t, lz;
	ll n;

	SegmentTree (ll an) {
		n = an;
		t.resize(n << 2);
		lz.resize(n << 2);
	}

	void push(ll v) {
		if (lz[v]) {
			t[v << 1] += lz[v];
			t[v << 1 | 1] += lz[v];
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
			lz[v] = 0;
		}
	}

	void add(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
		if (ql <= tl and tr <= qr) {
			t[v] += val;
			lz[v] += val;
		} else {
			push(v);
			ll tm = (tl + tr) >> 1;
			if (ql <= tm) add(v << 1, tl, tm, ql, qr, val);
			if (tm + 1 <= qr) add(v << 1 | 1, tm + 1, tr, ql, qr, val);
			t[v] = min(t[v << 1], t[v << 1 | 1]);
		}
	}

	void add(ll ql, ll qr, ll val) {
		add(1, 0, n - 1, ql, qr, val);
	}

	ll query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			push(v);
			ll tm = (tl + tr) >> 1;
			ll ret = LINF;
			if (ql <= tm) ret = min(ret, query(v << 1, tl, tm, ql, qr));
			if (tm + 1 <= qr) ret = min(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			t[v] = min(t[v << 1], t[v << 1 | 1]);
			return ret;
		}
	}

	ll query(ll ql, ll qr) {
		return query(1, 0, n - 1, ql, qr);
	}
};

struct seg {
	ll l, r, w;
};

ll solve() {
	ll n, m;
	cin >> n >> m;

	vector<seg> vec(n);
	for (auto &x : vec) {
		cin >> x.l >> x.r >> x.w;
		--x.l, --x.r;
	}

	sort(all(vec), [](const seg &a, const seg &b) {
		return a.w < b.w;
	});

	ll ans = LINF;
	SegmentTree st(m - 1);

	for (ll i = 0, j = 0; i < n; i++) {
		while (j < n and st.query(0, m - 2) == 0) {
			st.add(vec[j].l, vec[j].r - 1, 1);
			j++;
		}

		if (st.query(0, m - 2) == 0) break;
		ans = min(ans, vec[j - 1].w - vec[i].w);
		st.add(vec[i].l, vec[i].r - 1, -1);
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
