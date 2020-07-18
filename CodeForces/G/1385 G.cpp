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

/*
 * It can be proven that odd if all numbers appear twice answer always exists.
 * It is same as saying that odd length cycles won't appear the the graph that we build.
 */

vvi adj1, adj0;
vb vis;

void dfs(ll v, ll c, vvi &col){
    vis[v] = true;
    col[c].pb(v);
    for(ll u : adj1[v]){
        if(vis[u])
            continue;
        dfs(u, !c, col);
    }
    for(ll u : adj0[v]){
        if(vis[u])
            continue;
        dfs(u, c, col);
    }
}

ll solve(){
    adj1.clear();
    adj0.clear();
    vis.clear();

    ll n;
    cin >> n;
    adj1 = adj0 = vvi(n);
    vis.resize(n, false);

    vi a(n), b(n), cnt(n);
    for(ll &x : a)
        cin >> x, --x, cnt[x]++;
    for(ll &x : b)
        cin >> x, --x, cnt[x]++;

    for(ll i = 0; i < n; i++){
        if(cnt[i] != 2){
            cout << -1 << endl;
            return 0;
        }
    }

    vi c1(n, -1), c2(n, -1), r1(n, -1), r2(n, -1);
    for(ll i = 0; i < n; i++){
        if(c1[a[i]] == -1)
            c1[a[i]] = i;
        else
            c2[a[i]] = i;
        if(r1[a[i]] == -1)
            r1[a[i]] = 0;
        else
            r2[a[i]] = 0;
    }
    for(ll i = 0; i < n; i++){
        if(c1[b[i]] == -1)
            c1[b[i]] = i;
        else
            c2[b[i]] = i;
        if(r1[b[i]] == -1)
            r1[b[i]] = 1;
        else
            r2[b[i]] = 1;
    }

    for(ll i = 0; i < n; i++){
        if(c1[i] == c2[i])
            continue;
        if(r1[i] == r2[i]){
            adj1[c1[i]].pb(c2[i]);
            adj1[c2[i]].pb(c1[i]);
        }
        else{
            adj0[c1[i]].pb(c2[i]);
            adj0[c2[i]].pb(c1[i]);
        }
    }

    vi ans;
    for(ll i = 0; i < n; i++){
        if(vis[i])
            continue;
        vvi col(2);
        dfs(i, 0, col);
        if(col[0].size() < col[1].size())
            for(ll j = 0; j < (ll)col[0].size(); j++)
                ans.pb(col[0][j]);
        else
            for(ll j = 0; j < (ll)col[1].size(); j++)
                ans.pb(col[1][j]);
    }

    cout << ans.size() << endl;
    for(ll &x : ans)
        cout << ++x << " ";
    cout << endl;

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

