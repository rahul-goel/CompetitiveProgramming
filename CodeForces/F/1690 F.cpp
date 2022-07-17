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

int solve() {
	ll n;
	cin >> n;
	string str;
	cin >> str;
	vector<ll> p(n), idx(n);
	for (ll &x : p) cin >> x, --x;
	for (ll i = 0; i < n; ++i) idx[p[i]] = i;

	vector<bool> vis(n);

	vector<ll> lengths;
	for (ll i = 0; i < n; ++i) {
		if (!vis[i]) {
			vector<ll> cycle;
			for (ll j = i; !vis[j]; j = idx[j]) {
				vis[j] = true;
				cycle.push_back(j);
			}
			string s;
			for (ll c : cycle) s += str[c];
			string t = s;
			ll cnt = 0;
			do {
				rotate(t.begin(), t.begin() + 1, t.end());
				++cnt;
			} while (t != s);
			lengths.push_back(cnt);
		}
	}

	if (lengths.size() == 1) cout << lengths[0] << endl;
	else if (lengths.size() == 2) cout << lengths[0] * lengths[1] / __gcd(lengths[0], lengths[1]) << endl;
	else {
		ll lcm = lengths[0] * lengths[1] / __gcd(lengths[0], lengths[1]);
		for (ll i = 2; i < lengths.size(); ++i) {
			lcm = lcm * lengths[i] / __gcd(lcm, lengths[i]);
		}
		cout << lcm << endl;
	}

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

