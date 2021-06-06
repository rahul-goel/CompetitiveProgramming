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

ll find_sum(vector<ll> &sum, string &tree, ll i) {
	if (i >= (ll) tree.size()) {
		return 1;
	} else {
		ll ret = 0;
		ll left = find_sum(sum, tree, 2 * i + 1);
		ll right = find_sum(sum, tree, 2 * i + 2);
		if (tree[i] == '?') ret = left + right;
		if (tree[i] == '0') ret = left;
		if (tree[i] == '1') ret = right;
		return sum[i] = ret;
	}
}

void update(vector<ll> &sum, string &tree, ll i, char upd) {
	tree[i] = upd;
	sum[i] = 0;
	if (upd == '0') {
		if (2 * i + 1 < (ll) tree.size()) sum[i] += sum[2 * i + 1];
		else sum[i] += 1;
	}
	if (upd == '1') {
		if (2 * i + 2 < (ll) tree.size()) sum[i] += sum[2 * i + 2];
		else sum[i] += 1;
	}
	if (upd == '?') {
		if (2 * i + 1 < (ll) tree.size()) sum[i] += sum[2 * i + 1];
		else sum[i] += 1;
		if (2 * i + 2 < (ll) tree.size()) sum[i] += sum[2 * i + 2];
		else sum[i] += 1;
	}

	while (true) {
		i = (i - 1) / 2;
		if (tree[i] == '?') sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
		if (tree[i] == '0') sum[i] = sum[2 * i + 1];
		if (tree[i] == '1') sum[i] = sum[2 * i + 2];

		if (i == 0) break;
	}
}

ll solve() {
	ll k;
	cin >> k;

	string str;
	cin >> str;


	ll n = str.size();
	string tree(n, '0');
	vector<ll> idx(n);

	if (n == 1) {
		ll q;
		cin >> q;
		while (q--) {
			ll p;
			char upd;
			cin >> p >> upd;
			if (upd == '?') cout << 2 << endl;
			else cout << 1 << endl;
		}
		return 0;
	}

	ll x = n - 1, y = 0, z = 1;

	while (x >= 0) {
		for (ll i = x; i < x + z; i++) {
			tree[y] = str[i];
			idx[i] = y;
			y++;
		}
		z *= 2;
		x -= z;
	}

	vector<ll> sum(n);
	find_sum(sum, tree, 0);

	ll q;
	cin >> q;

	while (q--) {
		ll p;
		char upd;
		cin >> p >> upd;
		--p;
		ll i = idx[p];
		update(sum, tree, i, upd);
		cout << sum.front() << endl;
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
