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
vpii edge_list;
vi deg;
map < pii, ll > col;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
    edge_list.pb({min(u, v), max(u, v)});
    deg[u]++, deg[v]++;
}

void dfs(ll v, ll p, ll f, ll D){
    ll colour = 0;
    for(ll u : adj[v]){
        if(u == p)
            continue;
        if(colour == f)
            colour++, colour%= D, f = -1;
        col[{min(u, v), max(u, v)}] = colour;
        dfs(u, v, colour, D);
        colour++, colour%=D;
    }
}

ll solve(){
    ll n, k;
    cin >> n >> k;
    adj.resize(n), deg.resize(n);

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    ll start = 0, end = n-1, mid, pos = -1;
    map < pii, ll > ans;
    while(start <= end){
        mid = (start + end) / 2;
        ll cnt = 0;
        for(ll i=0; i<n; i++){
            if(deg[i] > mid)
                cnt++;
        }
    
        if(cnt <= k){
            dfs(0, -1, -1, mid);
            ans.swap(col);
            pos = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;

    }
    
    cout << pos << endl;
    for(auto x : edge_list)
        cout << ans[x] + 1 << " ";
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

