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

map<pii,ll> store;

void increment(ll l, ll r, ll pos) {
	if (present(store, pii(l, r))) {
		store[pii(l, r)] += 1;
	}
	if (l != r) {
		ll mid = (l + r) >> 1;
		if (pos <= mid) {
			increment(l, mid, pos);
		} else {
			increment(mid + 1, r, pos);
		}
	}
}

ll solve() {
	ll n, t;
	cin >> n >> t;
	while (t--) {
		ll k;
		cin >> k;
		ll l = 1, r = n;
		ll leftzeros = 0;
		while (l < r) {
			ll mid = (l + r) >> 1;
			ll sum;
			if (present(store, pii(l, mid))) {
				sum = store[pii(l, mid)];
			} else {
				cout << "? " << l << " " << mid << endl;
				cin >> sum;
				store[pii(l, mid)] = sum;
			}
			ll zeros = mid - l + 1 - sum;
			if (leftzeros + zeros < k) {
				l = mid + 1;
				leftzeros += zeros;
			} else {
				r = mid;
			}
		}
		cout << "! " << l << endl;
		increment(1, n, l);
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
