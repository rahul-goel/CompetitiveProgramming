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
#define pii             pair < ll, ll >
#define vi              vector < ll >
#define vb              vector < bool >
#define vvi             vector < vector < ll > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < ll, ll > >
#define vvpii           vector < vector < pair < ll, ll > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
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

void vecin(vi & vec), vecout(vi & vec);

/*
    Code begins after this.
*/

vvi adj;
vb vis;
ll n, m, a, b;
bool cona, conb;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll dfs(ll v){
    if(v == a)
        cona = true;
    if(v == b)
        conb = true;
    if(vis[v])
        return 0;
    vis[v] = true;    
    ll ret = 1;
    for(ll u : adj[v])
        ret += dfs(u);
    return ret;
}

ll solve(){
    cin >> n >> m >> a >> b;
    adj.clear(), vis.clear();
    adj.resize(n), vis.resize(n);
    a--, b--;

    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }
    
    vis[a] = vis[b] = true;
    ll sza = 0, szb = 0;

    for(ll i=0; i<n; i++){
        cona = conb = false;
        ll sz = dfs(i);
        if(cona && conb)
            continue;
        if(cona)
            sza += sz;
        if(conb)
            szb += sz;
    }

    cout << sza * szb << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/

void vecin(vi &vec){
    for(ll i=0; i<(ll)vec.size(); i++)
        cin >> vec[i];
}

void vecout(vi &vec, ll shift = 0){
    for(ll i=0; i<(ll)vec.size(); i++)
        cout << vec[i] + shift << " ";
    cout << endl;
}
