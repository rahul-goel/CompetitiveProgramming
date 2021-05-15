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

vector<set<ll>> adj;
vpii ans;

void add_edge(ll u, ll v) {
	adj[u].insert(v);
	adj[v].insert(u);
}

void dfs(ll v, ll p) {
	vi con;
	for (ll u : adj[v]) {
		con.push_back(u);
	}
	for (ll u : con) {
		if (u == p) {
			continue;
		} else {
			dfs(u, v);
		}
	}
	ll cnt_child = 0;
	for (ll u : adj[v]) {
		if (u == p) {
			continue;
		} else {
			cnt_child++;
		}
	}

	if (cnt_child == 2) {
		if (p != -1) {
			adj[v].erase(p);
			adj[p].erase(v);
			ans.emplace_back(p, v);
		}
	} else if (cnt_child > 2) {
		if (p != -1) {
			adj[v].erase(p);
			adj[p].erase(v);
			ans.emplace_back(p, v);

			ll rem_child = cnt_child;
			vi rmv;
			for (ll u : adj[v]) {
				if (rem_child <= 2) {
					break;
				}
				rmv.push_back(u);
				rem_child--;
			}
			for (ll u : rmv) {
				ans.emplace_back(u, v);
				adj[v].erase(u);
				adj[u].erase(v);
			}
		} else {
			ll rem_child = cnt_child;
			vi rmv;
			for (ll u : adj[v]) {
				if (rem_child <= 2) {
					break;
				}
				rmv.push_back(u);
				rem_child--;
			}
			for (ll u : rmv) {
				ans.emplace_back(u, v);
				adj[v].erase(u);
				adj[u].erase(v);
			}
		}
	}
}

void dfs_leaf(ll v, vb &vis, vi &leaf) {
	vis[v] = true;
	ll cnt = 0;
	for (ll u : adj[v]) {
		if (!vis[u]) {
			dfs_leaf(u, vis, leaf);
			cnt++;
		}
	}

	if (cnt == 0 and adj[v].size() <= 1) {
		leaf.push_back(v);
	} else if (cnt == 1 and adj[v].size() <= 1) {
		leaf.push_back(v);
	}
}

ll solve() {
	ll n;
	cin >> n;
	adj.clear();
	ans.clear();
	adj.resize(n);

	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		add_edge(u - 1, v - 1);
	}

	dfs(0, -1);

	vb vis(n);
	vvi comp;
	for (ll i = 0; i < n; i++) {
		if (!vis[i]) {
			vi v;
			dfs_leaf(i, vis, v);
			if (v.size() == 1) {
				v.push_back(v[0]);
			}
			comp.push_back(v);
		}
	}

	cout << ans.size() << endl;
	for (ll i = 0; i < (ll) ans.size(); i++) {
		cout << ans[i].ff + 1 << " " << ans[i].ss + 1 << " ";
		cout << comp[i][1] + 1 << " " << comp[i + 1][0] + 1 << endl;
		add_edge(comp[i][1], comp[i + 1][0]);
	}

//	for (ll i = 0; i < n; i++) {
//		for (ll j : adj[i]) {
//			if (i < j)
//				cout << i << " " << j << endl;
//		}
//	}

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
