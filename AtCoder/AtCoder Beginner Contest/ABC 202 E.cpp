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
vector<ll> dep, tin, tout;

ll tiktok = 0;

void dfs(ll v, ll p, ll d) {
	dep[v] = d;
	tin[v] = tiktok;
	tiktok++;
	for (ll u : adj[v]) {
		if (u != p) dfs(u, v, d + 1);
	}
	tout[v] = tiktok;
	tiktok++;
}

ll solve() {
	ll n;
	cin >> n;

	adj.resize(n);
	tin.resize(n);
	tout.resize(n);
	dep.resize(n);

	for (ll i = 1; i < n; i++) {
		ll p;
		cin >> p;
		--p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	dfs(0, 0, 0);

	vector<vector<ll>> store(*max_element(all(dep)) + 1);
	for (ll i = 0; i < n; i++) store[dep[i]].push_back(tin[i]);
	for (auto &x : store) sort(all(x));

	ll q;
	cin >> q;
	while (q--) {
		ll u, d;
		cin >> u >> d;
		--u;
		if (d < dep[u] or d >= store.size()) {
			cout << 0 << endl;
		} else {
			auto &vec = store[d];
			auto right = lower_bound(all(vec), tout[u]);
			auto left = lower_bound(all(vec), tin[u]);
			cout << right - left << endl;
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
