/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
/*******************************************************************************/
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/* For PBDS */
/*Two new methods X.order_of_key() and X.find_by_order()*/
/*
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

/*******************************************************************************/
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define pii             pair < int, int >
#define vi              vector < int >
#define vb              vector < bool >
#define vvi             vector < vector < int > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < int, int > >
#define vvpii           vector < vector < pair < int, int > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aint(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(aint(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
    Code begins after this.
*/

struct edge{
    int a, b, cost;
};

vector < edge > e;
vvi adj;
vb vis;
int negcycle_start = -1;

ll bellmanford(int n, int source, int dest){
    vector < ll > d (n, LINF);
    d[source] = 0;
    vi p (n - 1);
    int x = -1;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<(int)e.size(); ++j)
            if (d[e[j].a] < LINF)
                if (d[e[j].b] > d[e[j].a] + (ll)e[j].cost)
                {
                    d[e[j].b] = max (-LINF, d[e[j].a] + (ll)e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        return d[dest];
    else
    {
        negcycle_start = x;
        return d[dest];
    }
}

bool dfs(int v, int dest){
    vis[v] = true;
    if(v == dest)
        return true;
    bool ret = false;
    for(int u : adj[v]){
        if(!vis[u])
            ret |= dfs(u, dest);
    }
    return ret;
}

int solve(){
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n, false);
    for(int i=0; i<m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        a--, b--;
        adj[a].pb(b);
        e.pb({a, b, -cost});
    }

    ll ans = -bellmanford(n, 0, n-1);
    if(negcycle_start == -1){
        cout << ans << endl;
        return 0;
    }
    if(dfs(negcycle_start, n-1))
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

