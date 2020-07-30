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
T mod_sum(T a, Args... args) { return ((a + MOD_sum(args...))%MOD + MOD)%MOD; }
/*******************************************************************************/
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a*MOD_prod(args...))%MOD; }
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
vi p, h, sts;

void add_edge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

void calsts(ll v, ll par = -1) {
    sts[v] = p[v];
    for (ll u : adj[v]) {
        if (u == par) {
            continue;
        }
        calsts(u, v);
        sts[v] += sts[u];
    }
}

bool dfs(ll v, ll par, ll g, ll b) {
    for (ll u : adj[v]) {
        if (u == par) {
            continue;
        }

        if ((sts[u] & 1) != (h[u] & 1)) {
            return false;
        }

        ll gg = (sts[u] + h[u]) / 2;
        ll bb = (sts[u] - h[u]) / 2;
        g -= gg;
        if (bb > b) {
            bb -= b;
            b = 0;
            g -= b;
        } else {
            b -= bb;
        }
        if (g < 0 || b < 0) {
            return false;
        }
        if (dfs(u, v, gg, bb) == false) {
            return false;
        }
    }
    return true;
}

ll solve() {
    adj.clear();
    p.clear();
    h.clear();
    sts.clear();

    ll n, m;
    cin >> n >> m;

    adj.resize(n), p.resize(n), h.resize(n), sts.resize(n);

    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    calsts(0);
    for (ll i = 0; i < n; i++) {
        if (llabs(h[i]) > sts[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if ((h[0] & 1) != (sts[0] & 1)) {
        cout << "NO" << endl;
        return 0;
    }

    ll gg = (sts[0] + h[0]) / 2;
    ll bb = (sts[0] - h[0]) / 2;

    if (dfs(0, -1, gg, bb)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
