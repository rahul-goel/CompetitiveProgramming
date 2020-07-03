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

vi deg;
vvi adj;
vpii edgelist;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
    edgelist.pb({u, v});
    deg[u] += 1;
    deg[v] += 1;
}

ll solve(){
    ll n, d, k;
    cin >> n >> d >> k;
    
    if(d > n-1){
        cout << "NO" << endl;
        return 0;
    }

    adj.resize(n);
    deg.resize(n);

    set < pii > s;
    for(ll i=0; i<d; i++){
        add_edge(i, i+1);
        if(deg[i] > k || deg[i+1] > k){
            cout << "NO" << endl;
            return 0;
        }
    }
    for(ll i=1; i<d; i++)
        s.insert({max(i, d-i), i});

    for(ll i=d+1; i<n; i++){
        while(!s.empty() && deg[s.begin()->ss] == k)
            s.erase(s.begin());
        if(s.empty() || s.begin()->first == d){
            cout << "NO" << endl;
            return 0;
        }

        add_edge(i, s.begin()->ss);
        s.insert({s.begin()->ff + 1, i});
    }

    cout << "YES" << endl;
    for(auto p : edgelist)
        cout << p.ff + 1 << " " << p.ss + 1 << endl;

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

