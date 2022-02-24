/*
   Created by Rahul Goel.
   */
#include <algorithm>
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

struct CoordinateCompress {
	map<ll,ll> compress;
	ll highend = 0;
	vector<ll> decompress;
	CoordinateCompress(vector<ll> vec) {
		sort(all(vec));
		uniq(vec);
		for (ll x : vec) compress[x] = highend++;
		decompress = vec;
	}
};

pii maxpair(pii a, pii b) {
	if (a.ff > b.ff) return a;
	if (b.ff > a.ff) return b;
	return (a.ss > b.ss ? a : b);
}

struct SegmentTree {
	vector<pii> t, lz;
	ll n;

	SegmentTree (ll n){
		this->n = n;
		t.resize(n << 2, {0, -1});
		lz.resize(n << 2, {0, -1});
	}

	void push(ll v) {
		if (lz[v] != pii(0, -1)) {
			t[v << 1] = maxpair(t[v << 1], lz[v]);
			lz[v << 1] = t[v << 1];
			t[v << 1 | 1] = maxpair(t[v << 1 | 1], lz[v]);
			lz[v << 1 | 1] = t[v << 1 | 1];
			lz[v] = {0, -1};
		}
	}

	void update(ll v, ll tl, ll tr, ll ql, ll qr, pii val) {
		if (ql <= tl and tr <= qr) {
			t[v] = maxpair(t[v], val);
			lz[v] = t[v];
		} else {
			push(v);
			ll tm = (tl + tr) >> 1;
			if (ql <= tm) update(v << 1, tl , tm, ql, qr, val);
			if (tm + 1 <= qr) update(v << 1 | 1, tm + 1, tr, ql, qr, val);
			t[v] = maxpair(t[v << 1], t[v << 1 | 1]);
		}
	}

	void update(ll ql, ll qr, pii val) {
		update(1, 0, n - 1, ql, qr, val);
	}

	pii query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			push(v);
			ll tm = (tl + tr) >> 1;
			pii ret = {0, -1};
			if (ql <= tm) ret = maxpair(ret, query(v << 1, tl, tm, ql, qr));
			if (tm + 1 <= qr) ret = maxpair(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			t[v] = maxpair(t[v << 1], t[v << 1 | 1]);
			return ret;
		}
	}

	pii query(ll ql, ll qr) {
		return query(1, 0, n - 1, ql, qr);
	}
};

ll solve() {
	ll n, m;
	cin >> n >> m;

	vector<vector<array<ll,2>>> segments(n);
	vector<ll> vec;
	for (ll i = 0; i < m; i++) {
		ll id, l, r;
		cin >> id >> l >> r;
		--id;
		segments[id].push_back({l, r});
		vec.push_back(l);
		vec.push_back(r);
	}

	CoordinateCompress cc(vec);
	SegmentTree st(cc.highend);

	vector<int> prev(n, -1);

	for (ll i = 0; i < n; i++) {
		pii mx = {0, -1};
		for (auto arr : segments[i]) {
			ll ql = arr[0];
			ll qr = arr[1];
			ql = cc.compress[ql];
			qr = cc.compress[qr];
			pii y = st.query(ql, qr);
			mx = maxpair(mx, y);
		}

		prev[i] = mx.ss;
		mx.ff++;
		mx.ss = i;

		for (auto arr : segments[i]) {
			ll ql = arr[0];
			ll qr = arr[1];
			ql = cc.compress[ql];
			qr = cc.compress[qr];
			st.update(ql, qr, mx);
		}
	}

	pii mx = st.query(0, cc.highend - 1);
	vector<bool> vis(n);

	ll cur = mx.ss;
	while (cur != -1) {
		vis[cur] = true;
		cur = prev[cur];
	}

	cout << n - mx.ff << endl;
	for (ll i = 0; i < n; i++) if (!vis[i]) cout << i + 1 << " ";
	cout << endl;

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
