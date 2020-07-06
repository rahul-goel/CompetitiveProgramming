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
using pii = pair < int, int >;
using vi = vector < int >;
using vb = vector < bool >;
using vvi = vector < vector < int > >;
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
    vi t;

    SegmentTree(int n){
        t.resize(4 * n);
    }

    void build(int v, int tl , int tr, vi &vec){
        if(tl == tr){
            t[v] = vec[tl];
            return;
        }

        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, vec);
        build(v << 1 | 1, tm + 1, tr, vec);
        t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr){
            t[v] = val;
            return;
        }

        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
    }

    int query(int v, int tl, int tr, int ql, int qr, int x){
        if(ql <= tl && tr <= qr){
            if(t[v] % x == 0)
                return 0;
            if(tl == tr)
                return 1;
    
            if(t[v << 1] % x != 0 && t[v << 1 | 1] % x != 0)
                return 2;

            int tm = (tl + tr) >> 1;
            return query(v << 1, tl, tm, ql, qr, x) + query(v << 1 | 1, tm + 1, tr, ql, qr, x);
        }

        int tm = (tl + tr) >> 1;
        int val = 0;
        if(ql <= tm)
            val += query(v << 1, tl, tm, ql, qr, x);
        if(tm + 1 <= qr)
            val += query(v << 1 | 1, tm + 1, tr, ql, qr, x);
        return val;
    }

};

int solve(){
    int n;
    cin >> n;
    vi vec(n);
    for(int &x : vec)
        cin >> x;

    SegmentTree st(n);
    st.build(1, 0, n - 1, vec);

    int q;
    cin >> q;

    while(q--){
        int choice;
        cin >> choice;
        if(choice == 2){
            int ind, val;
            cin >> ind >> val;
            ind--;
            st.update(1, 0, n - 1, ind, val);
        }
        else{
            int ql, qr, x;
            cin >> ql >> qr >> x;
            ql--, qr--;

            int val = st.query(1, 0, n - 1, ql, qr, x);
            if(val > 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}


signed main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

