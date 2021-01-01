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

vector<vector<ll>> adj;
vector<ll> cycle;
vector<ll> col;
vector<ll> parent;
vector<bool> vis;

ll cycle_end, cycle_start;

void add_edge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(ll v, ll par) {
    col[v] = 1;
    for (ll u : adj[v]) {
        if (u == par) {
            continue;
        }
        if (col[u] == 0) {
            parent[u] = v;
            if (dfs(u, v)) {
                return true;
            }
        } else if (col[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    col[v] = 2;
    return false;
}

void find_cycle() {
    ll n = adj.size();
    col.assign(n, 0);
    parent.assign(n, -1);

    for (ll i = 0; i < n; i++) {
        if (col[i] == 0 && dfs(i, -1)) {
            break;
        }
    }

    cycle.push_back(cycle_start);
    for (ll v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    reverse(all(cycle));
}

ll dfscnt(ll v) {
    ll ret = 1;
    vis[v] = true;
    for (ll u : adj[v]) {
        if (vis[u] == false) {
            ret += dfscnt(u);
        }
    }
    return ret;
}

ll solve() {
    adj.clear();
    cycle.clear();
    cycle_end = -1;
    cycle_start = -1;
    parent.clear();
    col.clear();
    vis.clear();

    ll n;
    cin >> n;
    adj.resize(n);

    for (ll i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    find_cycle();
    vis.resize(n);
    for (ll cv : cycle) {
        vis[cv] = true;
    }

    ll ans = 0;
    for (ll cv : cycle) {
        ll cnt = dfscnt(cv);
        ans += cnt * (cnt - 1) / 2;
        ans += cnt * (n - cnt);
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
