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

struct Comb {
	vector<ll> fac;
	vector<ll> invfac;
	ll n;

	Comb (ll n) {
		this->n = n;
		fac.resize(n + 1, 0);
		invfac.resize(n + 1, 0);

		fac[0] = 1;
		for (ll i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
		invfac[n] = power(fac[n], MOD - 2);
		for (ll i = n - 1; i >= 0; i--) invfac[i] = (invfac[i + 1] * (i + 1)) % MOD;
	}

	ll power(ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1) ret = (ret * x) % MOD;
			y >>= 1;
			x = (x * x) % MOD;
		}
		return ret;
	}

	ll nCr(ll n, ll r) {
		if (n < 0 or r < 0 or n < r) return 0;
		ll ans = (fac[n] * ((invfac[r] * invfac[n - r]) % MOD)) % MOD;
		return ans;
	}
};

ll solve() {

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
