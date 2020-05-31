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

vvi rail, road;
vvi mat;

ll ssp(ll s, ll d, vvi &adj){
    vb visited(adj.size(), false);
    vi dist(adj.size(), LINF);
    queue < ll > q;
    q.push(s), dist[s] = 0, visited[s] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[d];
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    rail.resize(n), road.resize(n), mat.resize(n, vi(n));
        
    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(mat[i][j]){
                rail[i].pb(j);
                rail[j].pb(i);
            }
            else{
                road[i].pb(j);
                road[j].pb(i);
            }
        }
    }

    for(ll i=0; i<n; i++){
        sort(all(rail[i]));
        uniq(rail[i]);
        sort(all(road[i]));
        uniq(road[i]);
    }
        
    ll d1 = ssp(0, n-1, rail);
    ll d2 = ssp(0, n-1, road);
    
    if(d1 == LINF || d2 == LINF){
        cout << -1 << endl;
        return 0;
    }

    cout << max({d1, d2, 1ll}) << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

