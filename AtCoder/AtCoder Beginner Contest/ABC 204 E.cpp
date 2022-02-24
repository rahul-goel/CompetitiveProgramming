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

vector<vector<array<ll, 3>>> adj;

ll dijkstra(ll s) {
	ll n = adj.size();
	vector<ll> d(n, LINF);
	vector<ll> p(n, -1);

	d[s] = 0;
	using pii = pair<ll, ll>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		ll v = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			ll to = edge[0];
			ll cc = edge[1];
			ll dd = edge[2];

			ll opt;
			ll can = sqrt(dd);
			ll len = LINF;
			for (ll i = can - 2; i <= can + 2; i++) {
				ll ii = max(i, 0ll);
				ii = max(ii, d[v]);
				len = min(len, cc + ii - d[v] + dd / (ii + 1));
			}

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}

	return d.back();
}

ll solve() {
	ll n, m;
	cin >> n >> m;

	adj.resize(n);

	for (int i = 0; i < m; i++) {
		ll u, v, c, d;
		cin >> u >> v >> c >> d;
		--u, --v;
		adj[u].push_back({v, c, d});
		adj[v].push_back({u, c, d});
	}

	if (ll ans = dijkstra(0); ans == LINF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
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
