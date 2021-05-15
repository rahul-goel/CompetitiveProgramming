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

ll solve() {
	ll n;
	cin >> n;

	set<pii> s1, s2;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if ((i + j) & 1) {
				s1.insert({i, j});
			} else {
				s2.insert({i, j});
			}
		}
	}
	for (ll i = 0; i < n * n; i++) {
		ll x, y;
		cin >> x;
		if (x == 1) {
			if (!s2.empty()) {
				auto p = *s2.begin();
				s2.erase(s2.begin());
				cout << 2 << " " << p.ff + 1 << " " << p.ss + 1 << endl;
			} else {
				auto p = *s1.begin();
				s1.erase(s1.begin());
				cout << 3 << " " << p.ff + 1 << " " << p.ss + 1 << endl;
			}
		} else if (x == 2) {
			if (!s1.empty()) {
				auto p = *s1.begin();
				s1.erase(s1.begin());
				cout << 1 << " " << p.ff + 1 << " " << p.ss + 1 << endl;
			} else {
				auto p = *s2.begin();
				s2.erase(s2.begin());
				cout << 3 << " " << p.ff + 1 << " " << p.ss + 1 << endl;
			}
		} else if (x == 3) {
			if (!s2.empty()) {
				auto p = *s2.begin();
				s2.erase(s2.begin());
				cout << 2 << " " << p.ff + 1 << " " << p.ss + 1 << endl;
			} else if (!s1.empty()) {
				auto p = *s1.begin();
				s1.erase(s1.begin());
				cout << 1 << " " << p.ff + 1 << " " << p.ss + 1 << endl;
			}
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
