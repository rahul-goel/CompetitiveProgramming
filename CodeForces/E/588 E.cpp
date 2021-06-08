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

vector<vector<int>> adj;
vector<vector<int>> c;
vector<int> d;

const int LOG = 20;
vector<array<int, LOG>> par;
vector<array<vector<int>, LOG>> arr;

vector<int> combine(vector<int> &a, vector<int> &b, int sz) {
	vector<int> ret(a.size() + b.size());
	int i = 0, j = 0, k = 0;
	while (i < (int) a.size() and j < (int) b.size()) {
		if (a[i] < b[j]) ret[k++] = a[i++];
		else ret[k++] = b[j++];
	}
	while (i < (int) a.size()) ret[k++] = a[i++];
	while (j < (int) b.size()) ret[k++] = b[j++];
	uniq(ret);
	ret.resize(min((int) ret.size(), sz));
	return ret;
}

void dfs(int v, int p, int dep, int sz) {
	d[v] = dep;
	par[v][0] = p;
	arr[v][0] = combine(c[v], c[p], sz);
	for (int i = 1; i < LOG; i++) par[v][i] = par[par[v][i - 1]][i - 1];
	for (int i = 1; i < LOG; i++) arr[v][i] = combine(arr[v][i - 1], arr[par[v][i - 1]][i - 1], sz);
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v, dep + 1, sz);
		}
	}
}

vector<int> query(int x, int y, int sz) {
	vector<int> ret;

	if (x == y) {
		ret = combine(ret, c[x], sz);
		return ret;
	}

	if (d[x] != d[y]) {
		if (d[x] < d[y]) swap(x, y);
		int delta = d[x] - d[y];
		for (int i = 0; i < LOG; i++) {
			if ((delta >> i) & 1) {
				ret = combine(ret, arr[x][i], sz);
				x = par[x][i];
			}
		}
	}

	if (x == y) {
		return ret;
	}

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[x][i] == par[y][i]) continue;
		ret = combine(ret, arr[x][i], sz);
		ret = combine(ret, arr[y][i], sz);
		x = par[x][i];
		y = par[y][i];
	}

	assert(par[x][0] == par[y][0]);
	ret = combine(ret, c[x], sz);
	ret = combine(ret, c[y], sz);
	ret = combine(ret, c[par[x][0]], sz);
	return ret;
}

int solve() {
	int n, m, q;
	cin >> n >> m >> q;

	adj.resize(n + 1);
	c.resize(n + 1);
	d.resize(n + 1);
	par.resize(n + 1);
	arr.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= m; i++) {
		int city;
		cin >> city;
		c[city].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(c[i]));
		uniq(c[i]);
		c[i].resize(min((int) c[i].size(), 10));
	}

	dfs(1, 0, 0, 10);

	while (q--) {
		int u, v, a;
		cin >> u >> v >> a;
		auto vec = query(u, v, a);
		cout << vec.size() << " ";
		for (int &x : vec) cout << x << " ";
		cout << endl;
	}

	return 0;
}

signed main() {
	fastio;

	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
