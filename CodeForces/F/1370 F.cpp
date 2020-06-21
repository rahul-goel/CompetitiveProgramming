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
vi dist;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void dfs(ll v, ll p, ll d){
    dist[v] = d;
    for(ll u : adj[v])
        if(u != p)
            dfs(u, v, d+1);
}

ll solve(){
    ll n;
    cin >> n;
    adj.clear(), dist.clear();
    adj.resize(n+1), dist.resize(n+1);

    for(ll i=1; i<n; i++){
        ll u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    cout << "? " << n << " ";
    for(ll i=1; i<=n; i++)
        cout << i << " ";
    cout << endl;

    ll root, len;
    cin >> root >> len;
    dfs(root, -1, 0);

    ll ans1, ans2;
    ll end = min(*max_element(all(dist)), len);
    ll start = (end+1)/2;
    ll mid;
    while(start <= end){
        mid = (start + end) >> 1;

        vi v;
        for(ll i=1; i<=n; i++)
            if(dist[i] == mid)
                v.pb(i);

        if(v.empty()){
            end = mid - 1;
            continue;
        }

        cout << "? " << v.size() << " ";
        for(ll x : v)
            cout << x << " ";
        cout << endl;

        ll node, d;
        cin >> node >> d;

        if(d == len){
            ans1 = node;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    dfs(ans1, -1, 0);
    vi v;
    for(ll i=1; i<=n; i++)
        if(dist[i] == len)
            v.pb(i);

    cout << "? " << v.size() << " ";
    for(ll x : v)
        cout << x << " ";
    cout << endl;

    cin >> ans2 >> len;

    cout << "! " << ans1 << " " << ans2 << endl;
    string str;
    cin >> str;
    if(str != "Correct")
        exit(0);

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
