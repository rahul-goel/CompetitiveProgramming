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

struct DSU {
	vector<int> parent, size;

	DSU (int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) make_set(i);
	}

	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
	}

	int find_set(int v){
		if(v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b){
		a = find_set(a), b = find_set(b);
		if(a != b){
			if(size[a] < size[b])
				swap(a, b);
			parent[b] = a, size[a] += size[b];
		}
	}
};

int solve() {
	int n, m;
	cin >> n >> m;

	vector<int> d(n);
	for (int &x : d) cin >> x;

	DSU dsu(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		dsu.union_sets(u, v);
		--d[u], --d[v];
	}

	vector<vector<int>> open(n);

	for (int i = 0; i < n; ++i) {
		if (d[i] < 0) {
			cout << -1 << endl;
			return 0;
		}
		for (int j = 0; j < d[i]; ++j) {
			open[dsu.find_set(i)].push_back(i);
		}
	}

	vector<vector<int>> rem2;
	vector<int> rem1;

	for (auto vec: open) {
		if (vec.size() == 1) {
			rem1.push_back(vec.front());
		} else if (vec.size() > 1) {
			rem2.push_back(vec);
		}
	}

	vector<array<int, 2>> ans;

	for (auto vec: rem2) {
		for (int i = 0; i < (int)vec.size() - 1; ++i) {
			int x = vec[i];
			if (rem1.empty()) {
				cout << -1 << endl;
				return 0;
			}
			dsu.union_sets(x, rem1.back());
			ans.push_back({x, rem1.back()});
			rem1.pop_back();
		}
		rem1.push_back(vec.back());
	}

	if (rem1.size() != 2) {
		cout << -1 << endl;
		return 0;
	}

	dsu.union_sets(rem1[0], rem1[1]);
	ans.push_back({rem1[0], rem1[1]});

	if (dsu.size[dsu.find_set(0)] != n) {
		cout << -1 << endl;
		return 0;
	}

	for (auto [p, q] : ans) {
		cout << p + 1 << " " << q + 1 << endl;
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
