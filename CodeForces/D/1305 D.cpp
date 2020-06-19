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
using ll = long long;
using ld = long double;
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

void vecin(vi & vec), vecout(vi & vec);

/*
    Code begins after this.
*/

vvi adj;
vi deg;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++;
    deg[v]++;
}

ll solve(){
    ll n;
    cin >> n;
    adj.resize(n), deg.resize(n);

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    queue < ll > q;
    for(ll i=0; i<n; i++)
        if(deg[i] == 1)
            q.push(i);

    while(!q.empty()){
        if(q.size() == 1){
            ll u = q.front();
            q.pop();
            cout << "! " << u+1 << endl;
            exit(0);
        }
        ll u = q.front();
        q.pop();
        ll v = q.front();
        q.pop();

        for(ll x : adj[u]){
            adj[x].erase(find(all(adj[x]), u));
            deg[x]--;
            if(deg[x] == 1)
                q.push(x);
        }
        for(ll x : adj[v]){
            adj[x].erase(find(all(adj[x]), v));
            deg[x]--;
            if(deg[x] == 1)
                q.push(x);
        }

        adj[u].clear();
        adj[v].clear();

        cout << "? " << u+1 << " " << v+1 << endl;
        ll an;
        cin >> an;
        an--;
        if(an == u || an == v){
            cout << "! " << an+1 << endl;
            exit(0);
        }
    }

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

void vecin(vi &vec){
    for(ll i=0; i<(ll)vec.size(); i++)
        cin >> vec[i];
}

void vecout(vi &vec, ll shift = 0){
    for(ll i=0; i<(ll)vec.size(); i++)
        cout << vec[i] + shift << " ";
    cout << endl;
}
