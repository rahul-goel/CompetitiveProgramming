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

struct SegmentTree {
	struct node {
		array<ll,40> arr = {0};
		ll inv = 0;
	};

	vector<node> t;
	ll n;

	SegmentTree(ll n) {
		this->n = n;
		t.resize(n << 2);
	}

	node merge(node a, node b) {
		node ret;
		for (ll i = 0; i < (ll) a.arr.size(); i++) ret.arr[i] = a.arr[i] + b.arr[i];
		for (ll i = 1; i < (ll) b.arr.size(); i++) b.arr[i] += b.arr[i - 1];
		ret.inv = a.inv + b.inv;
		for (ll i = 1; i < (ll) a.arr.size(); i++) ret.inv += a.arr[i] * b.arr[i - 1];
		return ret;
	}

	void build(ll v, ll tl, ll tr, vector<ll> &vec) {
		if (tl == tr) {
			t[v].arr[vec[tl]] = 1;
		} else {
			ll tm = (tl + tr) >> 1;
			build(v << 1, tl, tm, vec);
			build(v << 1 | 1, tm + 1, tr, vec);
			t[v] = merge(t[v << 1], t[v << 1 | 1]);
		}
	}

	void build(vector<ll> &vec) {
		build(1, 0, n - 1, vec);
	}

	void update(ll v, ll tl, ll tr, ll pos, ll val) {
		if (tl == tr) {
			fill(all(t[v].arr), 0);
			t[v].arr[val] = 1;
		} else {
			ll tm = (tl + tr) >> 1;
			if (pos <= tm) update(v << 1, tl, tm, pos, val);
			else update(v << 1 | 1, tm + 1, tr, pos, val);
			t[v] = merge(t[v << 1], t[v << 1 | 1]);
		}
	}

	void update(ll pos, ll val) {
		update(1, 0, n - 1, pos, val);
	}

	node query(ll v, ll tl, ll tr, ll ql, ll qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			node ret;
			ll tm = (tl + tr) >> 1;
			if (ql <= tm) ret = merge(ret, query(v << 1, tl, tm, ql, qr));
			if (tm + 1 <= qr) ret = merge(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			return ret;
		}
	}

	node query(ll ql, ll qr) {
		return query(1, 0, n - 1, ql, qr);
	}
};

ll solve() {
	ll n, q;
	cin >> n >> q;

	vector<ll> vec(n);
	for (ll &x : vec) cin >> x, --x;

	SegmentTree st(n);
	st.build(vec);

	while (q--) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll ql, qr;
			cin >> ql >> qr;
			--ql, --qr;
			ll ans = st.query(ql, qr).inv;
			cout << ans << endl;
		} else {
			ll pos, val;
			cin >> pos >> val;
			--pos, --val;
			st.update(pos, val);
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
