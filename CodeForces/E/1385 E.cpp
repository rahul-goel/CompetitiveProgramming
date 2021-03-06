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

vvi dir;
vvi undir;
vi toposort;
vi col;

bool dfs(ll v){
    col[v] = 1;
    for(ll u : dir[v]){
        if(col[u] == 0 && dfs(u))
            return true;
        else if(col[u] == 1)
            return true;
    }
    col[v] = 2;
    toposort.pb(v);
    return false;
}

ll solve(){
    dir.clear(), undir.clear(), toposort.clear(), col.clear();
    ll n, m;
    cin >> n >> m;;
    dir.resize(n), undir.resize(n), col.resize(n);

    for(ll i = 0; i < m; i++){
        ll t, u, v;
        cin >> t >> u >> v;
        --u, --v;
        if(t == 0){
            undir[u].pb(v);
            undir[v].pb(u);
        }
        else{
            dir[u].pb(v);
        }
    }

    for(ll i = 0; i < n; i++){
        if(col[i] == 0 && dfs(i)){
            cout << "NO" << endl;
            return 0;
        }
    }

    reverse(all(toposort));
    vpii ans;
    set < pii > s;

    for(ll v : toposort){
        for(ll u : dir[v])
            ans.pb({v + 1, u + 1});
        for(ll u : undir[v]){
            if(present(s, make_pair(u, v)) || present(s, make_pair(v, u)))
                continue;
            s.insert({u, v});
            s.insert({v, u});
            ans.pb({v + 1, u + 1});
        }
    }

    cout << "YES" << endl;
    for(auto x : ans)
        cout << x.ff << " " << x.ss << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

