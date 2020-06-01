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
vi a, b, c;
ll ans = 0;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void dfs_set(ll v, ll p){
    if(p >= 0)
        a[v] = min(a[v], a[p]);
    for(ll u : adj[v]){
        if(p == u)
            continue;
        dfs_set(u, v);
    }
}

pii dfs_ans(ll v, ll p){
    pii cur = {0, 0};
    if(b[v] == 0 && c[v] == 1)
        cur.ff++;
    if(b[v] == 1 && c[v] == 0)
        cur.ss++;
    for(ll u : adj[v]){
        if(p == u)
            continue;
        pii temp = dfs_ans(u, v);
        cur.ff += temp.ff, cur.ss += temp.ss;
    }
    if(min(cur.ff, cur.ss) > 0){
        ll temp = min(cur.ff, cur.ss);
        ans += temp * a[v] * 2;
        cur.ff -= temp;
        cur.ss -= temp;
    }
    return cur;
}

ll solve(){
    ll n;
    cin >> n;
    adj.resize(n);
    a = b = c = vi(n);
    ll t1 = 0, t2 = 0;
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
        if(b[i] == 0 && c[i] == 1)
            t1++;
        if(b[i] == 1 && c[i] == 0)
            t2++;
    }
    for(ll i=1; i<n; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    if(t1 != t2){
        cout << -1 << endl;
        return 0;
    }
    
    dfs_set(0, -1);
    dfs_ans(0, -1);
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

