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

struct HeavyLightDecomposition {
	vector<vector<ll>> adj;
	vector<ll> sz, par, head, sc, st, en;
	vector<ll> val, linear;
	ll tiktok = 0;

	void dfs_size(ll v, ll p) {
		sz[v] = 1;
		par[v] = p;
		head[v] = v;
		sc[v] = -1;
		ll mx_sc_size = 0;
		for (auto &u : adj[v]) {
			if (u != p) {
				dfs_size(u, v);
				sz[v] += sz[u];
				if (sz[u] > mx_sc_size) {
					mx_sc_size = sz[u];
					sc[v] = u;
				}
			}
		}
	}

	void dfs_hld(ll v, ll p) {
		st[v] = tiktok;
		linear[tiktok] = val[v];
		tiktok++;
		// dfs on heavy edge
		if (sc[v] != -1) {
			head[sc[v]] = head[v];
			dfs_hld(sc[v], v);
		}
		// dfs on light edges
		for (auto &u : adj[v]) {
			if (u != p and u != sc[v]) dfs_hld(u, v);
		}
		en[v] = tiktok;
	}

	bool is_ancestor(ll x, ll y) {
		// is x ancestor of y ??
		return st[x] <= st[y] and en[y] <= en[x];
	}

	ll find_lca(ll x, ll y) {
		if (is_ancestor(x, y)) return x;
		if (is_ancestor(y, x)) return y;

		while (!is_ancestor(par[head[x]], y)) x = par[head[x]];
		while (!is_ancestor(par[head[y]], x)) y = par[head[y]];
		x = par[head[x]];
		y = par[head[y]];

		return is_ancestor(x, y) ? y : x;
	}

	HeavyLightDecomposition(vector<vector<ll>> &a_adj, vector<ll> &a_val) {
		adj = a_adj;
		val = a_val;
		linear = st = en = sz = par = head = sc = vector<ll>(adj.size());
		dfs_size(0, 0);
		dfs_hld(0, 0);
	}
};

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
			t[v] = max(t[v << 1], t[v << 1 | 1]);
		}
	}

	void update(ll v, ll tl, ll tr, ll pos, ll newval) {
		if (tl == tr) {
			t[v] = newval;
		} else {
			ll tm = (tl + tr) >> 1;
			if (pos <= tm) {
				update(v << 1, tl, tm, pos, newval);
			} else {
				update(v << 1 | 1, tm + 1, tr, pos, newval);
			}
			t[v] = max(t[v << 1], t[v << 1 | 1]);
		}
	}

	ll query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			ll ret = -LINF;
			ll tm = (tl + tr) >> 1;
			if (ql <= tm) ret = max(ret, query(v << 1, tl, tm, ql, qr));
			if (tm + 1 <= qr) ret = max(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			return ret;
		}
	}
};

ll solve() {
	ll n, q;
	cin >> n >> q;

	vector<ll> val(n);
	vector<vector<ll>> adj(n);

	for (ll i = 0; i < n; i++) cin >> val[i];
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	HeavyLightDecomposition hld(adj, val);
	SegmentTree st(n);
	st.build(1, 0, n - 1, hld.linear);

	for (ll i = 0; i < q; i++) {
		ll t, u, v;
		cin >> t >> u >> v;
		if (t == 2) {
			--u, --v;
			ll lca = hld.find_lca(u, v);

			ll ans = -LINF;
			while (hld.head[u] != hld.head[lca]) {
				ans = max(ans, st.query(1, 0, n - 1, hld.st[hld.head[u]], hld.st[u]));
				u = hld.par[hld.head[u]];
			}
			ans = max(ans, st.query(1, 0, n - 1, hld.st[lca], hld.st[u]));
			while (hld.head[v] != hld.head[lca]) {
				ans = max(ans, st.query(1, 0, n - 1, hld.st[hld.head[v]], hld.st[v]));
				v = hld.par[hld.head[v]];
			}
			ans = max(ans, st.query(1, 0, n - 1, hld.st[lca], hld.st[v]));

			cout << ans << " ";
		} else {
			--u;
			ll pos = hld.st[u];
			st.update(1, 0, n - 1, pos, v);
		}
	}
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
