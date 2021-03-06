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
vb vis;
vi side;
vpii divisions;
vvi backtrack[2];

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

bool bipartite_check(){
    ll n = adj.size();
    queue < ll > q;
    for(ll i=0; i<n; i++){
        if(side[i] == -1){
            backtrack[0].pb(vi());
            backtrack[1].pb(vi());
            q.push(i);
            side[i] = 0;
            while(!q.empty()){
                ll v = q.front();
                backtrack[side[v]].back().pb(v);
                q.pop();
                for(ll u : adj[v]){
                    if(side[u] == -1){
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else if ((side[u] ^ side[v]) == 0)
                        return false;
                }
            }
        }
    }
    return true;
}

pii dfs(ll v){
    vis[v] = true;
    ll p0 = 0, p1 = 0;
    if(side[v] == 0)
        p0++;
    else
        p1++;
    for(ll u : adj[v]){
        if(!vis[u]){
            pii x = dfs(u);
            p0 += x.ff, p1 += x.ss;
        }
    }
    return {p0, p1};
}

ll solve(){
    backtrack[0].clear(), backtrack[1].clear();
    ll n, m, n1, n2, n3;
    cin >> n >> m >> n1 >> n2 >> n3;
    adj.resize(n), vis.resize(n, false), side.resize(n, -1);
    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    if(!bipartite_check()){
        cout << "NO" << endl;
        return 0;
    }
    
    for(ll i=0; i<n; i++){
        if(!vis[i])
            divisions.pb(dfs(i));
    }
    
    vvi dp(divisions.size()+5, vi(n+5, -1));
    dp[0][0] = 0;
    for(ll i=0; i<divisions.size(); i++){
        for(ll j=0; j<n; j++){
            if(dp[i][j] != -1){
                dp[i+1][j+divisions[i].ff] = 0;
                dp[i+1][j+divisions[i].ss] = 1;
            }
        }
    }

    if(dp[divisions.size()][n2] == -1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    vi ans(n+5);
    ll cur = n2;
    for(ll i=divisions.size(); i>0; i--){
        for(auto it : backtrack[dp[i][cur]][i-1])
            ans[it] = 2;
        cur -= backtrack[dp[i][cur]][i-1].size();
        if(cur == 0)
            break;
    }
    for(ll i=0; i<n; i++){
        if(ans[i] != 2){
            if(n1>0)
                ans[i] = 1, n1--;
            else
                ans[i] = 3;
        }
    }

    for(ll i=0; i<n; i++)
        cout << ans[i];
    cout << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

