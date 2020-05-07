/*
   Created by Rahul Goel.
*/

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

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define min_pq(t) priority_queue < t, vector < t >, greater < t > >
#define max_pq(t) priority_queue < t >
#define pb push_back
#define ff first
#define ss second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

// --------------------------------------------------------------

vvi adj, rev_adj;
vb up_vis, down_vis;
vi colour;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    rev_adj[v].pb(u);
}

bool dfs_cyclic(ll v){
   colour[v] = 1;
   for(ll u : adj[v]){
       if(colour[u] == 0 && dfs_cyclic(u))
           return true;
       else if(colour[u] == 1)
            return true;
   }
   colour[v] = 2;
   return false;
}

void dfs(ll v, vvi &ad, vb &vis){
    vis[v] = true;
    for(ll u : ad[v])
      if(!vis[u])
         dfs(u, ad, vis);
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n), rev_adj.resize(n), up_vis.resize(n, false), down_vis.resize(n, false), colour.resize(n, 0);

    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    for(ll i=0; i<n; i++){
        if(colour[i] == 0 && dfs_cyclic(i)){
            cout << -1 << endl;
            return 0;
        }
    }

    string ans = "";
    for(ll i=0; i<n; i++){
        if(up_vis[i] || down_vis[i])
            ans.pb('E');
        else
            ans.pb('A');
        if(!up_vis[i])
            dfs(i, adj, up_vis);
        if(!down_vis[i])
            dfs(i, rev_adj, down_vis);
    }

    cout << count(all(ans), 'A') << endl;
    cout << ans << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

