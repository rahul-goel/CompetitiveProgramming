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

struct node {
	ll idx;
	ll a;
	ll c;
};

bool comp(const node &x, const node &y) {
	return (x.a < y.a);
}

vvpii adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
	ll n = adj.size();
	d.assign(n, LINF);
	p.assign(n, -1);

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
			ll to = edge.first;
			ll len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}

ll solve() {
	ll n;
	cin >> n;
	adj.resize(n);

	vector<node> vec;
	for (ll i = 0; i < n; i++) {
		ll a, c;
		cin >> a >> c;
		node tmp;
		tmp.idx = i;
		tmp.a = a;
		tmp.c = c;
		vec.push_back(tmp);
	}

	sort(all(vec), comp);
	for (ll i = 0; i < n; i++) {
		if (i - 1 > 0) {
			adj[i].push_back({i - 1, 0});
		}

		ll l = 0, r = n - 1, mid, pos = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (vec[mid].a - vec[i].a - vec[i].c <= 0) {
				pos = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (pos != -1) {
			adj[i].push_back({pos, 0});
			if (pos + 1 < n) {
				adj[i].push_back({pos + 1, vec[pos + 1].a - vec[i].a - vec[i].c});
			}
		}
	}

	vi d(n), p(n);
	dijkstra(0, d, p);

	ll ans = d.back();
	for (ll i = 0; i < n; i++) {
		ans += vec[i].c;
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
