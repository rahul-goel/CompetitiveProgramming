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

/*
    Code begins after this.
*/

vvi adj;
vi side, comps;
vb vis, vis2;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

bool is_bipartite(){
    bool flag = true;
    queue<ll> q;
    for(ll st = 0; st < (ll)side.size(); ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                ll v = q.front();
                q.pop();
                for (ll u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        flag &= side[u] != side[v];
                    }
                }
            }
        }
    }
    return flag;
}

ll dfs_comp(ll v){
    vis[v] = true;
    ll val = 1;
    for(ll u : adj[v]){
        if(!vis[u])
            val += dfs_comp(u);
    }
    return val;
}

pii dfs(ll v){
    vis2[v] = true;
    pii cur = {0, 0};
    if(side[v] == 0)
        cur.ff++;
    else
        cur.ss++;
    for(ll u : adj[v]){
        if(!vis2[u]){
            pii temp = dfs(u);
            cur.ff+=temp.ff;
            cur.ss+=temp.ss;
        }
    }
    return cur;
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n), side.resize(n, -1);
    vis.resize(n, false);

    if(m == 0){
        cout << 3 << " " << n*(n-1)*(n-2)/6 << endl;
        return 0;
    }

    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    if(!is_bipartite()){
        cout << "0 1" << endl;
        return 0;
    }
    
    for(ll i=0; i<n; i++)
        if(!vis[i])
            comps.pb(dfs_comp(i));
    sort(all(comps), greater<ll>());

    if(comps.front()>=3){
        vis2.assign(n, false); 
        vis.assign(n, false); 
        ll ans = 0;
        for(ll i=0; i<n; i++){
            if(!vis[i]){
                ll el = dfs_comp(i);
                if(el >= 3){
                    pii cur = dfs(i);
                    ans += cur.ff * (cur.ff-1)/2;
                    ans += cur.ss * (cur.ss-1)/2;
                }
            }
        }
        cout << 1 << " " << ans << endl;
    }
    else{
        ll x = count(all(comps), 2);
        cout << 2 << " " << x * (n-2) << endl;
        return 0;
    }

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

