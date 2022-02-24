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
	vector<vector<pii>> adj;
	vector<ll> sz, par, head, sc, st, en, xx;
	vector<ll> val, linear;
	ll tiktok = 0;

	void dfs_size(ll v, ll p, ll xw) {
		sz[v] = 1;
		par[v] = p;
		head[v] = v;
		sc[v] = -1;
		xx[v] = xx[p] xor xw;
		ll mx_sc_size = 0;
		for (auto &[u, w] : adj[v]) {
			if (u != p) {
				dfs_size(u, v, w);
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
		for (auto &[u, w] : adj[v]) {
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

	HeavyLightDecomposition(vector<vector<pii>> &a_adj, vector<ll> &a_val) {
		adj = a_adj;
		val = a_val;
		linear = st = en = sz = par = head = sc = xx = vector<ll>(adj.size());
		fill(all(st), -1);

		for (ll i = 0; i < (ll) adj.size(); i++) {
			if (st[i] == -1) {
				dfs_size(i, i, 0);
				dfs_hld(i, i);
			}
		}
	}
};

struct DSU {
	vector<ll> parent, size;

	DSU (ll n) {
		parent.resize(n);
		size.resize(n);
		for (ll i = 0; i < n; i++) make_set(i);
	}

	void make_set(ll v){
		parent[v] = v;
		size[v] = 1;
	}

	ll find_set(ll v){
		if(v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(ll a, ll b){
		a = find_set(a), b = find_set(b);
		if(a != b){
			if(size[a] < size[b])
				swap(a, b);
			parent[b] = a, size[a] += size[b];
		}
	}
};

struct SegmentTree {
	vector<ll> t, lz;
	ll n;

	SegmentTree(ll an) {
		n = an;
		t.resize(n << 2);
		lz.resize(n << 2);
	}

	void push(ll v, ll tl, ll tm, ll tr) {
		if (lz[v]) {
			t[v << 1] += lz[v] * (tm - tl + 1);
			t[v << 1 | 1] += lz[v] * (tr - tm);
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
			lz[v] = 0;
		}
	}

	void add(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
		if (ql <= tl and tr <= qr) {
			t[v] += val * (qr - ql + 1);
			lz[v] += val;
		} else {
			ll tm = (tl + tr) >> 1;
			push(v, tl, tm, tr);
			if (ql <= tm) add(v << 1, tl, tm, ql, qr, val);
			if (tm + 1 <= qr) add(v << 1 | 1, tm + 1, tr, ql, qr, val);
			t[v] = t[v << 1] + t[v << 1 | 1];
		}
	}

	void add(ll ql, ll qr) {
		if (ql > qr) return;
		add(1, 0, n - 1, ql, qr, 1);
	}

	ll sum(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			ll tm = (tl + tr) >> 1;
			push(v, tl, tm, tr);
			ll ret = 0;
			if (ql <= tm) ret += sum(v << 1, tl, tm, ql, qr);
			if (tm + 1 <= qr) ret += sum(v << 1 | 1, tm + 1, tr, ql, qr);
			t[v] = t[v << 1] + t[v << 1 | 1];
			return ret;
		}
	}

	ll sum(ll ql, ll qr) {
		if (ql > qr) return 0;
		return sum(1, 0, n - 1, ql, qr);
	}
};

ll solve() {
	ll n, q;
	cin >> n >> q;

	vector<array<ll,3>> queries(q);
	vector<vector<pii>> adj(n);
	vector<ll> ans;

	DSU dsu(n);

	for (auto &x : queries) {
		cin >> x[0] >> x[1] >> x[2];
		--x[0], --x[1];

		if (dsu.find_set(x[0]) != dsu.find_set(x[1])) {
			dsu.union_sets(x[0], x[1]);
			adj[x[0]].emplace_back(x[1], x[2]);
			adj[x[1]].emplace_back(x[0], x[2]);
			ans.push_back(1);
		} else {
			ans.push_back(-1);
		}
	}

	vector<ll> emp(n, 0);
	SegmentTree sgt(n);
	HeavyLightDecomposition hld(adj, emp);

	for (ll i = 0; i < q; i++) {
		if (ans[i] != -1) continue;

		ans[i] = 0;
		ll u = queries[i][0];
		ll v = queries[i][1];
		ll w = queries[i][2];

		ll xx = hld.xx[u] xor hld.xx[v];
		if ((xx xor w) != 1) continue;

		ll uu = u, vv = v;
		ll lca = hld.find_lca(u, v);
		ll sum = 0;
		while (hld.head[v] != hld.head[lca]) {
			sum += sgt.sum(hld.st[hld.head[v]], hld.st[v]);
			v = hld.par[hld.head[v]];
		}
		sum += sgt.sum(hld.st[lca] + 1, hld.st[v]);
		while (hld.head[u] != hld.head[lca]) {
			sum += sgt.sum(hld.st[hld.head[u]], hld.st[u]);
			u = hld.par[hld.head[u]];
		}
		sum += sgt.sum(hld.st[lca] + 1, hld.st[u]);
		if (sum) continue;

		ans[i] = 1;
		u = uu, v = vv;
		while (hld.head[v] != hld.head[lca]) {
			sgt.add(hld.st[hld.head[v]], hld.st[v]);
			v = hld.par[hld.head[v]];
		}
		sgt.add(hld.st[lca] + 1, hld.st[v]);
		while (hld.head[u] != hld.head[lca]) {
			sgt.add(hld.st[hld.head[u]], hld.st[u]);
			u = hld.par[hld.head[u]];
		}
		sgt.add(hld.st[lca] + 1, hld.st[u]);
	}

	for (auto aa : ans) cout << (aa ? "YES" : "NO") << endl;

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
