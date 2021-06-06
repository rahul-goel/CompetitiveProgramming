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

const ll LOG = 18;
vector<vector<ll>> par, mxw;

struct Edge {
	ll u, v, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

vector<ll> parent, rankdsu;

void make_set(ll v) {
	parent[v] = v;
	rankdsu[v] = 0;
}

ll find_set(ll v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rankdsu[a] < rankdsu[b])
			swap(a, b);
		parent[b] = a;
		if (rankdsu[a] == rankdsu[b])
			rankdsu[a]++;
	}
}

ll n;
vector<Edge> edges;

vector<Edge> kruskal() {
	ll cost = 0;
	vector<Edge> result;
	parent.resize(n);
	rankdsu.resize(n);
	for (ll i = 0; i < n; i++)
		make_set(i);

	sort(edges.begin(), edges.end());

	for (Edge e : edges) {
		if (find_set(e.u) != find_set(e.v)) {
			cost += e.weight;
			result.push_back(e);
			union_sets(e.u, e.v);
		}
	}

	return result;
}


vector<vector<pii>> adj;
vector<ll> tin, tout;
vector<ll> dep;
ll tiktok;

void dfs(ll v, ll p, ll w, ll d) {
	tin[v] = ++tiktok;
	par[v][0] = p;
	mxw[v][0] = w;
	dep[v] = d + 1;
	for (ll i = 1; i < LOG; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
		mxw[v][i] = max(mxw[v][i - 1], mxw[par[v][i - 1]][i - 1]);
	}

	for (auto ed : adj[v]) {
		if (ed.ff != p) dfs(ed.ff, v, ed.ss, d + 1);
	}

	tout[v] = ++tiktok;
}

bool is_ancestor(ll u, ll v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

ll query(ll x, ll y) {
	ll res = 0;
	if (dep[x] != dep[y]) {
		if (dep[x] < dep[y]) swap(x, y);
		ll d = dep[x] - dep[y];
		for (ll i = 0; i < LOG; i++) {
			if ((d >> i) & 1) {
				res = max(res, mxw[x][i]);
				x = par[x][i];
			}
		}
	}
	if (x == y) {
		return res;
	}

	for (ll i = LOG - 1; i >= 0; i--) {
		if (par[x][i] == par[y][i]) continue;
		res = max({res, mxw[x][i], mxw[y][i]});
		x = par[x][i], y = par[y][i];
	}

	res = max({res, mxw[x][0], mxw[y][0]});
	return res;
}


ll solve() {
	ll m;
	cin >> n >> m;

	for (ll i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back({u, v, w});
	}

	auto store = edges;

	auto tree = kruskal();
	adj.resize(n);
	set<pii> s;
	ll sum = 0;
	for (auto ed : tree) {
		adj[ed.u].push_back({ed.v, ed.weight});
		adj[ed.v].push_back({ed.u, ed.weight});
		s.insert({ed.u, ed.v});
		s.insert({ed.v, ed.u});
		sum += ed.weight;
	}

	par.resize(n, vector<ll>(LOG, 0));
	mxw.resize(n, vector<ll>(LOG, 0));
	dep.resize(n, 0);
	tin.resize(n);
	tout.resize(n);
	dfs(0, 0, 0, -1);

	for (ll i = 0; i < m; i++) {
		ll u = store[i].u, v = store[i].v, w = store[i].weight;
		if (s.find({u, v}) != s.end()) {
			cout << sum << endl;
		} else {
			cout << sum + w - query(u, v) << endl;
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
