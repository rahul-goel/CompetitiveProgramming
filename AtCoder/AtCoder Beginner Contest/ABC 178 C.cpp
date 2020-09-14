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

ll power(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1) {
            ret = (ret * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return ret;
}

ll inv(ll x) {
    return power(x, MOD - 2);
}

ll fac[1000005];

ll choose(ll x, ll y) {
    ll ret = fac[x];
    ret = (ret * inv(fac[y])) % MOD;
    ret = (ret * inv(fac[x - y])) % MOD;
    return ret;
}

ll solve() {
    fac[0] = 1;
    for (ll i = 1; i < 1000005; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    for (ll i = 2; i <= n; i++) {
        ll temp = (power(2, i) - 2) % MOD;
        temp %= MOD;
        temp += MOD;
        temp %= MOD;
        temp = (temp * choose(n, i)) % MOD;
        temp = (temp * power(10, n - i)) % MOD;
        if (i & 1) {
            ans -= temp;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        } else {
            ans += temp;
            ans %= MOD;
        }
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
