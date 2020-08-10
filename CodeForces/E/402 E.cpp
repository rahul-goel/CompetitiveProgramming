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
vvi adj, adj_rev;
vector < bool > visited;
vi order, component;

void add_edge(int to, int from){
    adj[to].pb(from);
    adj_rev[from].pb(to);
}

// dfs to set the t_out time/ build the order array
void dfs1(int from){
    visited[from] = true;
    for(int to : adj[from]){
        if(!visited[to])
            dfs1(to);
    }
    order.pb(from);
}

// dfs to mark the connected component using adj_rev
// NOTE - At any point of time, the component array has only one connected component
void dfs2(int from){
    visited[from] = true, component.pb(from);
    for(int to : adj_rev[from]){
        if(!visited[to])
            dfs2(to);
    }
}

bool ssc(int n){
    visited.assign(n, false);
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());

    ll cnt = 0;

    visited.assign(n, false);
    for(int i=0; i<n; i++){
        int v = order[i];
        if(!visited[v]){
            // means that this can represent the condensed graph
            dfs2(v);
            // do whatever you want to with the component.
            component.clear();
            cnt++;
        }
    }
    return cnt == 1;
}

int solve() {
    int n;
    cin >> n;
    vvi mat(n, vi(n));
    adj.resize(n);
    adj_rev.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && mat[i][j]) {
                add_edge(i, j);
            }
        }
    }

    bool flag = ssc(n);
    cout << (flag ? "YES" : "NO") << endl;

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
