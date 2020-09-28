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
const ll MOD = 998244353;
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

vi fac(3 * 100000 + 5);

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

ll choose(ll n, ll r) {
    if (n < r) {
        return 0;
    } else {
        return (fac[n] * ((inv(fac[r]) * inv(fac[n - r])) % MOD)) % MOD;
    }
}

ll solve() {
    fac.front() = 1;
    for (ll i = 1; i < (ll) fac.size(); i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    ll n, k;
    cin >> n >> k;

    map<ll,ll> start, end;
    vi store;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        store.pb(x);
        store.pb(y);
        start[x]++;
        end[y]++;
    }

    sort(all(store));
    uniq(store);

    ll p = 0, s = 0;
    ll ans = 0;
    for (ll x : store) {
        s = start[x];
        p += s;

        ans += ((choose(p, k) - choose(p - s, k)) % MOD + MOD) % MOD;
        ans %= MOD;

        p -= end[x];
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
