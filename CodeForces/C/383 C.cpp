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

vvi adj;
vi tour, vec, height, ind, sub;

struct SegmentTree{
    vi t, lz;
    ll n;

    SegmentTree(ll k){
        t = lz = vi(4 * k);
        n = k;
    }

    void push(ll v){
        if(lz[v] == 0)
            return;
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
        t[v << 1] += lz[v];
        t[v << 1 | 1] += lz[v];
        lz[v] = 0;
    }

    void update(ll v, ll tl, ll tr, ll ql, ll qr, ll val){
        if(ql <= tl && tr <= qr){
            lz[v] += val;
            t[v] += val;
            return;
        }

        push(v);
        ll tm = (tl + tr) >> 1;
        if(ql <= tm)
            update(v << 1, tl, tm, ql, qr, val);
        if(tm + 1 <= qr)
            update(v << 1 | 1, tm + 1, tr, ql, qr, val);
    }

    ll query(ll v, ll tl, ll tr, ll pos){
        if(tl == tr)
            return t[v];

        push(v);
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)
            return query(v << 1, tl, tm, pos);
        else
            return query(v << 1 | 1, tm + 1, tr, pos);
    }

};

void dfs(ll v, ll p){
    ind[v] = tour.size();
    tour.pb(v);
    height[v] = height[p] + 1;
    sub[v] = 0;

    for(ll u : adj[v]){
        if(u == p)
            continue;
        dfs(u, v);
        sub[v] += sub[u] + 1;
    }
}

ll solve(){
    ll n, m;
    cin >> n >> m;

    adj.resize(n);
    vec = sub = height = ind = vi(n);

    for(ll &x : vec)
        cin >> x;

    for(ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    height[0] = -1;
    dfs(0, 0);

    vector < SegmentTree > st(2, SegmentTree(n));

    while(m--){
        ll choice;
        cin >> choice;

        if(choice == 1){
            ll x, val;
            cin >> x >> val;
            x--;
            ll h = height[x] & 1;
            st[h].update(1, 0, n - 1, ind[x], ind[x] + sub[x], val);
        }
        else{
            ll x;
            cin >> x;
            x--;
            ll h = height[x] & 1;
            ll ans = vec[x] + st[h].query(1, 0, n - 1, ind[x]) - st[!h].query(1, 0, n - 1, ind[x]);
            cout << ans << endl;
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
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

