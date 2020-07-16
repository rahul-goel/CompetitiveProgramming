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

struct SegmentTree{
    vpii t;

    SegmentTree(ll n){
        t.resize(4 * n);
    }

    pii merge(pii &a, pii &b){
        if(a.ff < b.ff)
            return a;
        else if(a.ff > b.ff)
            return b;
        else
            return {a.ff, a.ss + b.ss};
    }

    void build(ll v, ll tl, ll tr, vi &vec){
        if(tl == tr){
            t[v] = {vec[tl], 1};
            return;
        }

        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, vec);
        build(v << 1 | 1, tm + 1, tr, vec);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll val){
        if(tl == tr){
            t[v] = {val, 1};
            return;
        }

        ll tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    pii query(ll v, ll tl, ll tr, ll ql, ll qr){
        if(ql <= tl && tr <= qr)
            return t[v];

        ll tm = (tl + tr) >> 1;
        pii a = {LINF, 0}, b = {LINF, 0};
        if(ql <= tm)
            a = query(v << 1, tl, tm, ql, qr);
        if(tm + 1 <= qr)
            b = query(v << 1 | 1, tm + 1, tr, ql, qr);
        return merge(a, b);
    }

};

ll solve(){
    ll n, m;
    cin >> n >> m;
    vi vec(n);
    for(ll i = 0; i < n; i++)
        cin >> vec[i];

    SegmentTree st(n);
    st.build(1, 0, n - 1, vec);

    while(m--){
        ll choice;
        cin >> choice;
        if(choice == 1){
            ll pos, val;
            cin >> pos >> val;
            st.update(1, 0, n - 1, pos, val);
        }
        else{
            ll ql, qr;
            cin >> ql >> qr;
            qr--;
            pii ans;
            ans = st.query(1, 0, n - 1, ql, qr);
            cout << ans.ff << endl;
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

