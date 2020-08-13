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

void fileio(string str) {
    string in = str + ".in";
    string out = str + ".out";
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
}

void vecout(vi &vec, ll start = -1, ll end = -1) {
    if (start != -1) {
        for (ll i = start; i < end; i++) {
            cout << vec[start] << " ";
        }
        cout << vec[end] << endl;
    } else {
        for (ll i = 0; i < (ll) vec.size() - 1; i++) {
            cout << vec[i] << " ";
        }
        cout << vec.back() << endl;
    }
}

vvi adj;
vb vis;

void add_edge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

vi conn;
void dfs(ll v) {
    vis[v] = true;
    conn.pb(v);
    for (ll u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}

ll solve() {
    ll n, m;
    cin >> n >> m;

    vpii vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i].ff >> vec[i].ss;
    }

    adj.resize(n);
    vis.resize(n, false);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    ll ans = LINF;
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            conn.clear();
            dfs(i);
            ll mxx = -LINF, mxy = -LINF;
            ll mnx = LINF, mny = LINF;
            for (ll v : conn) {
                mxx = max(mxx, vec[v].ff);
                mnx = min(mnx, vec[v].ff);
                mxy = max(mxy, vec[v].ss);
                mny = min(mny, vec[v].ss);
            }
            ans = min(ans, (mxx - mnx) * 2 + (mxy - mny) * 2);
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;
    fileio("fenceplan");

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
