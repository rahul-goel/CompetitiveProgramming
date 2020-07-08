/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
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

vvi adj;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll x = -1, y = -1, curx = 0, cury = 0;
vi par;

void dfs1(ll v, ll p, ll d){
    if(d > curx)
        curx = d, x = v;
    for(ll u : adj[v]){
        if(u == p)
            continue;
        dfs1(u, v, d + 1);
    }
}

void dfs2(ll v, ll p, ll d){
    par[v] = p;
    if(d > cury)
        cury = d, y = v;
    for(ll u : adj[v]){
        if(u == p)
            continue;
        dfs2(u, v, d + 1);
    }
}

ll solve(){
    ll n;
    cin >> n;
    adj.resize(n);
    par.resize(n);

    for(ll i = 1; i < n; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    dfs1(0, -1, 0);
    dfs2(x, -1, 0);

    if(cury == n - 1){
        for(ll i = 0; i < n; i++){
            if(i != x && i != y){
                cout << n - 1 << endl;
                cout << x + 1 << " " << y + 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }

    vi dist(n, LINF);
    queue < ll > q;
    for(ll v = y; v != -1; v = par[v])
        q.push(v), dist[v] = 0;

    while(!q.empty()){
        ll v = q.front();
        q.pop();

        for(ll u : adj[v]){
            if(dist[u] == LINF){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    ll z = max_element(all(dist)) - dist.begin();

    cout << cury + dist[z] << endl;
    cout << x + 1 << " " << y + 1 << " " << z + 1 << endl;

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

