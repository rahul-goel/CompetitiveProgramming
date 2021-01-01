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
using pii = pair < int, int >;
using vi = vector < int >;
using vb = vector < bool >;
using vvi = vector < vector < int > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
    Code begins after this.
*/

int bfs(vector<set<int>> &adj, int u, int v) {
    int ans = INF;
    int n = adj.size();
    vector<bool> vis(n);
    vector<int> dist(n, INF);

    queue<int> q;
    vis[v] = true;
    q.push(v);
    dist[v] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (!vis[y]) {
                dist[y] = dist[x] + 1;
                vis[y] = true;
                q.push(y);
                if (vis[u]) {
                    break;
                }
            }
        }
        if (vis[u]) {
            break;
        }
    }

    ans = min(ans, dist[u] + 1);

    return ans;
}

int solve() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n);
    vector<pii> edge_list;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
        edge_list.emplace_back(u, v);
    }

    int girth = INF;
    for (auto &p : edge_list) {
        int u = p.ff, v = p.ss;
        adj[u].erase(v);
        adj[v].erase(u);

        girth = min(girth, bfs(adj, u, v));

        adj[u].insert(v);
        adj[v].insert(u);
    }


    cout << (girth == INF ? -1 : girth) << endl;

    return 0;
}

signed main() {
    fastio;

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
