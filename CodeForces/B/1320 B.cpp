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
vvi rev;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    rev[v].pb(u);
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    rev.resize(n);

    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    ll k;
    cin >> k;
    vi path(k);
    for(ll &x : path)
        cin >> x, x--;

    vi dist(n, LINF), cnt(n, 0);
    queue < ll > q;
    q.push(path.back()), dist[path.back()] = 0, cnt[path.back()] = 0;

    while(!q.empty()){
        ll v = q.front();
        q.pop();
        ll d = dist[v];

        for(ll u : rev[v]){
            if(dist[u] == LINF){
                dist[u] = d + 1;
                cnt[u] = 1;
                q.push(u);
            }
            else if(dist[u] == d + 1)
                cnt[u]++;
        }
    }

    ll mx = 0, mn = 0;
    for(ll i = 0; i < (ll)path.size() - 1; i++){
        ll cur = path[i], next = path[i + 1];
        if(dist[cur] == dist[next] + 1 && cnt[cur] == 1){
            mn += 0;
            mx += 0;
        }
        else if(dist[cur] == dist[next] + 1 && cnt[cur] > 1){
            mn += 0;
            mx += 1;
        }
        else{
            mn += 1;
            mx += 1;
        }
    }

    cout << mn << " " << mx << endl;

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

