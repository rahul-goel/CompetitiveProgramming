/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
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
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/*
.-.. . -. -.- .- / .. ... / .-.. --- ...- . -.-.--
 */
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
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
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

/*
    Code begins after this.
*/


vvpii adj;
vi dist;

void add_edge(ll u, ll v, ll w){
    adj[u].pb({v, w});
    adj[v].pb({u, w});
}

void dijkstra(ll source = 0){
    min_pq(pii) pq;
    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        ll v = pq.top().ss;
        ll d = pq.top().ff;
        pq.pop();
        if(d != dist[v])
            continue;

        for(auto ed : adj[v]){
            ll u = ed.ff;
            ll w = ed.ss;

            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1), dist.resize(n + 1, LINF);

    for(ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w * 2);
    }

    for(ll i = 1; i <=n ; i++){
        ll w;
        cin >> w;
        add_edge(i, 0, w);
    }

    dijkstra(0);

    for(ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

