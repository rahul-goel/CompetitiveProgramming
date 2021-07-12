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

vector<vector<ll>> adj;
vector<ll> tin, tout;
vector<ll> color;
vector<bool> inf_vis;
vector<bool> fin_vis;
vector<ll> inf;
vector<ll> fin;

ll tiktok = 0;

void dfs_inf(ll v, ll a) {
	inf_vis[v] = true;
	inf[v] = a;
	for (ll u : adj[v]) {
		if (!inf_vis[u]) {
			dfs_inf(u, a);
		}
	}
}

void dfs_fin(ll v, ll a) {
	fin_vis[v] = true;
	fin[v] += a;
	for (ll u : adj[v]) {
		if (!fin_vis[u]) {
			dfs_fin(u, a);
		}
	}
}

void dfs(ll v) {
	tin[v] = tiktok++;
	color[v] = 1;
	fin[v] = 1;
	for (ll u : adj[v]) {
		if (color[u] == 0) {
			dfs(u);
		} else if (color[u] == 1) {
			// same branch, infinite ways
			dfs_inf(u, -LINF);
		} else if (color[u] == 2) {
			// crossover
			dfs_fin(u, 1);
		}
	}
	color[v] = 2;
	tout[v] = tiktok++;
}

ll solve() {
	ll n, m;
	cin >> n >> m;

	adj.clear();
	tin.clear();
	tout.clear();
	color.clear();
	inf_vis.clear();
	inf.clear();
	fin_vis.clear();
	fin.clear();

	adj.resize(n);
	tin.resize(n);
	tout.resize(n);
	color.resize(n);
	inf_vis.resize(n);
	inf.resize(n);
	fin_vis.resize(n);
	fin.resize(n);

	tiktok = 0;

	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}

	dfs(0);

	for (ll i = 0; i < n; i++) {
		if (inf[i] < 0) {
			cout << -1 << " ";
		} else if (fin[i] == 0) {
			cout << 0 << " ";
		} else if (fin[i] == 1) {
			cout << 1 << " ";
		} else {
			cout << 2 << " ";
		}
	}
	cout << endl;

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
