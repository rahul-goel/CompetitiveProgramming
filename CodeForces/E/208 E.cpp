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
vector<ll> dep;
vector<ll> tin, tout;
vector<vector<ll>> dptin;
vector<vector<ll>> dptout;

ll tiktok = 0;

const ll LOG = 20;
vector<array<ll, LOG>> up;

void add_edge(ll u, ll v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(ll v, ll p, ll d) {
	dep[v] = d + 1;
	up[v][0] = p;
	tin[v] = ++tiktok;
	for (ll i = 1; i < LOG; i++) up[v][i] = up[up[v][i - 1]][i - 1];
	for (ll u : adj[v]) {
		if (u != p) {
			dfs(u, v, d + 1);
		}
	}
	tout[v] = ++tiktok;
}

ll solve() {
	ll n;
	cin >> n;

	adj.resize(n + 1);
	dep.resize(n + 1);
	up.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);

	vi root;
	for (ll i = 1; i <= n; i++) {
		ll p;
		cin >> p;
		if (p == 0) root.push_back(i);
		else add_edge(i, p);
	}

	for (ll &x : root) dfs(x, 0, -1);

	dptin.resize(*max_element(all(dep)) + 1);
	dptout.resize(*max_element(all(dep)) + 1);
	for (ll i = 1; i <= n; i++) {
		dptin[dep[i]].push_back(tin[i]);
		dptout[dep[i]].push_back(tout[i]);
	}

	for (auto &x : dptin) sort(all(x));
	for (auto &x : dptout) sort(all(x));

	ll m;
	cin >> m;

	for (ll i = 0; i < m; i++) {
		ll v, p;
		cin >> v >> p;
		if (dep[v] < p) {
			cout << 0 << " ";
			continue;
		}
		ll d = dep[v];
		for (ll j = 0; j < LOG; j++) if ((p >> j) & 1) v = up[v][j];
		ll left = lower_bound(all(dptin[d]), tin[v]) - dptin[d].begin();
		ll right = upper_bound(all(dptout[d]), tout[v]) - dptout[d].begin();
		ll cnt = right - left;
		cout << cnt - 1 << " ";
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
