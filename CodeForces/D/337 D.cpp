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
vi marked, tour, sub, idx, height, tourheight;

struct segment_tree{
    vi t, lz;

    void init(ll n){
        t.resize(n*4);
        lz.resize(n*4);
    }

    void build(vi &vec, ll tl, ll tr, ll v){
        if(tl == tr){
            if(marked[tour[tl]])
                t[v] = vec[tl];
            else
                t[v] = -LINF;
            return;
        }

        ll tm = (tl + tr) >> 1;
        build(vec, tl, tm, v << 1);
        build(vec, tm + 1, tr, v << 1 | 1);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
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

    void update(ll tl, ll tr, ll val, ll ql, ll qr, ll v){
        if(tl > tr || ql > qr)
            return;
        if(ql <= tl && tr <= qr){
            lz[v] += val;
            t[v] += val;
            return;
        }

        push(v);
        ll tm = (tl + tr) >> 1;
        if(ql <= tm)
            update(tl, tm, val, ql, qr, v << 1);
        if(tm + 1 <= qr)
            update(tm + 1, tr, val, ql, qr, v << 1 | 1);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
};

void dfstour(ll v, ll p){
    idx[v] = tour.size();
    tour.pb(v);
    sub[v] = 0, height[v] = height[p] + 1;

    for(ll u : adj[v]){
        if(u == p)
            continue;
        dfstour(u, v);
        sub[v] += sub[u] + 1;
    }
}

ll ans = 0;
segment_tree st;
ll n, m, d;

void dfsans(ll v, ll p){
    if(st.t[1] <= d)
        ans++;

    for(ll u : adj[v]){
        if(u == p)
            continue;

        st.update(0, n - 1, -1, idx[u], idx[u] + sub[u], 1);
        st.update(0, n - 1, 1, 0, idx[u] - 1, 1);
        st.update(0, n - 1, 1, idx[u] + sub[u] + 1, n - 1, 1);
        dfsans(u, v);
        st.update(0, n - 1, 1, idx[u], idx[u] + sub[u], 1);
        st.update(0, n - 1, -1, 0, idx[u] - 1, 1);
        st.update(0, n - 1, -1, idx[u] + sub[u] + 1, n - 1, 1);
    }
}

ll solve(){
    cin >> n >> m >> d;
    adj.resize(n);
    marked = sub = idx = height = tourheight = vi(n);

    for(ll i = 0; i < m; i++){
        ll x;
        cin >> x;
        x--;
        marked[x] = 1;
    }

    for(ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    height[0] = -1;
    dfstour(0, 0);

    for(ll i = 0; i < n; i++)
        tourheight[i] = height[tour[i]];

    st.init(n);
    st.build(tourheight, 0, n - 1, 1);
    dfsans(0, 0);

    cout << ans << endl;

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

