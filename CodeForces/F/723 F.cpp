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

struct DSU {
    vi parent, size;

    DSU(ll n) {
        parent.resize(n);
        size.resize(n);
        for (ll i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll find_parent(ll v) {
        if (parent[v] == v) {
            return v;
        } else {
            return parent[v] = find_parent(parent[v]);
        }
    }

    void union_sets(ll u, ll v) {
        u = find_parent(u);
        v = find_parent(v);
        if (u != v) {
            if (size[u] > size[v]){
                swap(u, v);
            }
            size[v] += size[u];
            parent[u] = v;
        }
    }
};

set < pii > edge_list;
set < pii > bridge_list;
vi deg;
vvi adj;

void add_edge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
    edge_list.insert({min(u, v), max(u, v)});
}

// cpalgo copypasta starts
vb visited;
vi tin, low;
ll timer = 0;

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (ll to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridge_list.insert({min(to, v), max(to, v)});
        }
    }
}

void find_bridges() {
    timer = 0;
    ll n = adj.size();
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
// cpalgo copypasta ends

ll solve() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n), deg.resize(n);

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    find_bridges();
    DSU dsu(n);

    ll s, t, ds, dt;
    cin >> s >> t >> ds >> dt;
    --s, --t;
    vpii ans;

    for (auto edge : bridge_list) {
        ll u = edge.ff, v = edge.ss;
        if (dsu.find_parent(u) != dsu.find_parent(v)) {
            ans.pb({u, v});
            dsu.union_sets(u, v);
            deg[u]++;
            deg[v]++;
            if (deg[s] > ds || deg[t] > dt) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for (auto edge : edge_list) {
        ll u = edge.ff, v = edge.ss;
        if (u == s || u == t || v == s || v == t) {
            continue;
        }
        if (dsu.find_parent(u) != dsu.find_parent(v)) {
            ans.pb({u, v});
            dsu.union_sets(u, v);
            deg[u]++;
            deg[v]++;
        }
    }

    for (auto edge : edge_list) {
        ll u = edge.ff, v = edge.ss;
        if (!(u == s || u == t || v == s || v == t)) {
            continue;
        }
        if ((u == s && v == t) || (u == t && v == s)) {
            continue;
        }
        if (u == s || v == s) {
            if (deg[s] >= ds) {
                continue;
            }
        }
        if (u == t || v == t) {
            if (deg[t] >= dt) {
                continue;
            }
        }
        if (dsu.find_parent(u) != dsu.find_parent(v)) {
            ans.pb({u, v});
            dsu.union_sets(u, v);
            deg[u]++;
            deg[v]++;
            if (deg[s] > ds || deg[t] > dt) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (auto edge : edge_list) {
        ll u = edge.ff, v = edge.ss;
        if ((u == s && v == t) || (u == t && v == s)) {
            if (dsu.find_parent(u) != dsu.find_parent(v)) {
                ans.pb({u, v});
                dsu.union_sets(u, v);
                deg[u]++;
                deg[v]++;
                if (deg[s] > ds || deg[t] > dt) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    if ((ll)ans.size() != n - 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (auto &x : ans) {
            cout << ++x.ff << " " << ++x.ss << endl;
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
