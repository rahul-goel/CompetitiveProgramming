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

vvpii adj;
vi dist, parent, path;

void add_edge(ll u, ll v, ll len){
    adj[u].pb({len, v});
}

void dijkstra(ll source){
    dist[source] = 0;
    priority_queue < pii, vpii, greater < pii > > q;
    q.push({0, source});

    while(!q.empty()){
        ll v = q.top().second;
        ll dist_v = q.top().first;
        q.pop();

        if(dist_v != dist[v])
            continue;

        for(auto edge : adj[v]){
            ll to = edge.second;
            ll len = edge.first;

            if(dist[v] + len < dist[to]){
                dist[to] = dist[v] + len, parent[to] = v;
                q.push({dist[to], to});
            }
        }
    }
}

void restore_path(ll source, ll t){
    for(ll u=t; u!=source; u=parent[u])
        path.pb(u);
    path.pb(source);
    reverse(path.begin(), path.end());
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n), dist.resize(n, LINF), parent.resize(n, -1);

    for(ll i=0; i<m; i++){
        ll u, v, len;
        cin >> u >> v >> len;
        u--, v--;
        add_edge(u, v, len);
    }

    dijkstra(0);

    for(ll i=0; i<n; i++)
        cout << dist[i] << " ";
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

