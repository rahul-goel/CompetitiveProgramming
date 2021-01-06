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
vector<bool> vis;

void add_edge(ll u, ll v) {
    adj[u].push_back(v);
}

vector<ll> bfs(ll source) {
    ll n = adj.size();
    vector<ll> dist(n, LINF);

    queue<ll> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (dist[u] == LINF) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    return dist;
}

void dfs(ll v, vector<ll> &dp, vector<ll> &dist) {
    vis[v] = true;
    dp[v] = dist[v];
    for (ll u : adj[v]) {
        if (vis[u] == false && dist[v] < dist[u]) {
            dfs(u, dp, dist);
        }

        if (dist[v] < dist[u]) {
            dp[v] = min(dp[v], dp[u]);
        } else {
            dp[v] = min(dp[v], dist[u]);
        }
    }
}

ll solve() {
    adj.clear();
    vis.clear();

    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n, false);

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    vector<ll> dist = bfs(0);
    vector<ll> dp(n, LINF);
    dfs(0, dp, dist);

    for (ll i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

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
