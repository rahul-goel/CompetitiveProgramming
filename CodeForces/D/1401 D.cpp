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

vvi adj;
vi sts;

void add_edge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

ll dfs(ll v, ll p) {
    sts[v] = 1;
    for (ll u : adj[v]) {
        if (u != p) {
            sts[v] += dfs(u, v);
        }
    }
    return sts[v];
}

ll solve() {
    ll n;
    cin >> n;

    adj.clear();
    sts.clear();
    adj.resize(n);
    sts.resize(n);

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    ll m;
    cin >> m;
    vi vec(m);
    for (ll &x : vec) {
        cin >> x;
    }
    sort(all(vec));

    if (m > n - 1) {
        while ((ll)vec.size() != n - 1) {
            ll x = vec.back();
            vec.pop_back();
            ll y = vec.back();
            vec.pop_back();
            vec.pb((x * y) % MOD);
        }
    } else {
        reverse(all(vec));
        while ((ll) vec.size() != n - 1) {
            vec.pb(1);
        }
        reverse(all(vec));
    }

    dfs(0, -1);
    vi v;
    for (ll i = 1; i < n; i++) {
        v.pb(sts[i] * (n - sts[i]));
    }

    sort(all(v));
    ll ans = 0;

    for (ll i = 0; i < n - 1; i++) {
        ans = (ans + ((v[i] % MOD) * vec[i]) % MOD) % MOD;
    }

    cout << ans % MOD << endl;

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
