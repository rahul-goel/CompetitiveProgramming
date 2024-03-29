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
	vector<ll> t;
	int n;

	SegmentTree(int an) {
		n = an;
		t.resize(n << 2);
	}

	void build(int v, int tl, int tr, vector<ll> &vec) {
		if (tl == tr) {
			t[v] = vec[tl];
		} else {
			int tm = (tl + tr) >> 1;
			build(v << 1, tl, tm, vec);
			build(v << 1 | 1, tm + 1, tr, vec);
			t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
		}
	}

	void build(vector<ll> &vec) {
		build(1, 0, n - 1, vec);
	}

	ll query(int v, int tl, int tr, int ql, int qr) {
		if (ql <= tl and tr <= qr) {
			return t[v];
		} else {
			int tm = (tl + tr) >> 1;
			ll ret = 0;
			if (ql <= tm) ret = __gcd(ret, query(v << 1, tl, tm, ql, qr));
			if (tm + 1 <= qr) ret = __gcd(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
			return ret;
		}
	}

	ll query(int ql, int qr) {
		return query(1, 0, n - 1, ql, qr);
	}
};

int solve() {
	int n;
	cin >> n;

	vector<ll> diff(n - 1);
	ll prev;
	cin >> prev;
	for (int i = 0; i < n - 1; i++) {
		ll next;
		cin >> next;
		diff[i] = abs(next - prev);
		prev = next;
	}

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	SegmentTree st(n - 1);
	st.build(diff);

	ll ans = 1;
	for (ll i = 0, j = 0; i < (ll) diff.size(); i++) {
		while (j <= i and st.query(j, i) == 1) j++;
		ans = max(ans, i - j + 2);
	}

	cout << ans << endl;
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
