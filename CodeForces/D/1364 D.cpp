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
vi p, depth;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void dfs(ll v){
    for(ll u : adj[v]){
        if(u == p[v]) continue;
        if(depth[u] == 0){
            depth[u] = depth[v] + 1;
            p[u] = v;
            dfs(u);
        }
        else if(depth[u] < depth[v]){
            vi ans;
            while(v != u)
                ans.pb(v), v = p[v];
            ans.pb(u);

            cout << 2 << endl;
            cout << ans.size() << endl;
            for(ll aa : ans)
                cout << aa + 1 << " ";
            cout << endl;
            exit(0);
        }
    }
}

ll solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    adj.resize(n);
    p = depth = vi(n);

    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        //trying to build a graph only out of k nodes.
        if(u >= k || v >= k)
            continue;
        add_edge(u, v);
    }
    
    for(ll i=0; i<k; i++){
        if(depth[i] == 0){
            depth[i] = 1;
            dfs(i);
        }
    }

    vvi ans(2);
    for(ll i=0; i<k; i++)
        ans[depth[i]&1].pb(i);
    k = (k + 1) / 2;
    cout << 1 << endl;
    if((ll)ans[0].size() >= k){
        for(ll i=0; i<k; i++) 
            cout << ans[0][i] + 1<< " ";
        cout << endl;
    }
    else{
        for(ll i=0; i<k; i++) 
            cout << ans[1][i] + 1<< " ";
        cout << endl;
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

