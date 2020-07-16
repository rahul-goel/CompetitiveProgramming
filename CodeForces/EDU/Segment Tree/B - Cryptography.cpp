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

struct node{
    ll mat[2][2];
};

struct SegmentTree{
    vector < node > t;

    SegmentTree(ll n){
        t.resize(n << 2);
    }

    node merge(node a, node b){
        node ret;
        for(ll i = 0; i < 2; i++)
            for(ll j = 0; j < 2; j++)
                ret.mat[i][j] = 0;
        for(ll i = 0; i < 2; i++)
            for(ll j = 0; j < 2; j++)
                for(ll k = 0; k < 2; k++)
                    ret.mat[i][j] = (ret.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % mod) % mod;
        return ret;
    }

    void build(ll v, ll tl, ll tr, vector < node > &vec){
        if(tl == tr){
            t[v] = vec[tl];
            return;
        }

        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, vec);
        build(v << 1 | 1, tm + 1, tr, vec);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(ll v, ll tl, ll tr, ll ql, ll qr){
        if(ql <= tl && tr <= qr)
            return t[v];

        ll tm = (tl + tr) >> 1;
        node ret;
        ret.mat[0][0] = 1 % mod;
        ret.mat[0][1] = 0;
        ret.mat[1][1] = 1 % mod;
        ret.mat[1][0] = 0;

        if(ql <= tm)
            ret = merge(ret, query(v << 1, tl, tm, ql, qr));
        if(tm + 1 <= qr)
            ret = merge(ret, query(v << 1 | 1, tm + 1, tr, ql, qr));
        return ret;
    }


};

ll solve(){
    ll n, m;
    cin >> mod >> n >> m;

    vector < node > vec(n);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 2; j++)
            for(ll k = 0; k < 2; k++)
                cin >> vec[i].mat[j][k], vec[i].mat[j][k] %= mod;
    }

    SegmentTree st(n);
    st.build(1, 0, n - 1, vec);

    while(m--){
        ll ql, qr;
        cin >> ql >> qr;
        ql--, qr--;

        node ans = st.query(1, 0, n - 1, ql, qr);
        for(ll i = 0; i < 2; i++){
            for(ll j = 0; j < 2; j++)
                cout << ans.mat[i][j] << " ";
            cout << endl;
        }
        cout << endl;
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

