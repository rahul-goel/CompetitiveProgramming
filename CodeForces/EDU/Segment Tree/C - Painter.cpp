/*
    Created by Rahul Goel.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*******************************************************************************/
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*******************************************************************************/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template < typename T, typename... Args >
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%MOD + MOD)%MOD; }
/*******************************************************************************/
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a * mod_prod(args...))%MOD; }
/*******************************************************************************/
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
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
    Code begins after this.
*/

struct SegmentTree{
    struct node {
        ll left, right;
        ll countseg, len;
        ll lz;
    };
    vector<node> t;

    SegmentTree(ll n) {
        t.resize(n << 2);
    }

    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v].left = t[v].right = 0;
            t[v].countseg = t[v].len = 0;
            t[v].lz = -1;
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v].lz = -1;
        merge(v);
    }

    void merge(ll v) {
        if (t[v << 1].right == t[v << 1 | 1].left) {
            t[v].left = t[v << 1].left;
            t[v].right = t[v << 1 | 1].right;
            t[v].countseg = t[v << 1].countseg + t[v << 1 | 1].countseg - (t[v << 1].right == 1);
            t[v].len = t[v << 1].len + t[v << 1 | 1].len;
        } else {
            t[v].left = t[v << 1].left;
            t[v].right = t[v << 1 | 1].right;
            t[v].countseg = t[v << 1].countseg + t[v << 1 | 1].countseg;
            t[v].len = t[v << 1].len + t[v << 1 | 1].len;
        }
    }

    void push(ll v, ll tl, ll tm, ll tr) {
        if (t[v].lz != -1) {
            t[v << 1].lz = t[v << 1 | 1].lz = t[v].lz;
            if (!t[v].lz) {
                t[v << 1].countseg = t[v << 1 | 1].countseg = 0;
                t[v << 1].len = t[v << 1 | 1].len = 0;
                t[v << 1].left = t[v << 1].right = 0;
                t[v << 1 | 1].left = t[v << 1 | 1].right = 0;
            } else {
                t[v << 1].countseg = 1;
                t[v << 1].len = (tm - tl + 1);
                t[v << 1].left = t[v << 1].right = 1;
                t[v << 1 | 1].countseg = 1;
                t[v << 1 | 1].len = (tr - tm);
                t[v << 1 | 1].left = t[v << 1 | 1].right = 1;
            }
            t[v].lz = -1;
        }
    }

    void update(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
        if (ql <= tl && tr <= qr) {
            t[v].len = val ? (tr - tl + 1) : 0;
            t[v].countseg = val;
            t[v].left = t[v].right = val;
            t[v].lz = val;
            return;
        }

        ll tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if (ql <= tm) {
            update(v << 1, tl, tm, ql, qr, val);
        }
        if (tm + 1 <= qr) {
            update(v << 1 | 1, tm + 1, tr, ql, qr, val);
        }
        merge(v);
    }

    pii query() {
        return make_pair(t[1].countseg, t[1].len);
    }
};

ll solve() {
    ll n;
    cin >> n;
    SegmentTree st(1000010);
    st.build(1, 0, n - 1);

    while (n--) {
        char c;
        ll x, l;
        cin >> c >> x >> l;
        x += 500000;
        if (c == 'W') {
            st.update(1, 0, 1000010 - 1, x, x + l - 1, 0);
        } else {
            st.update(1, 0, 1000010 - 1, x, x + l - 1, 1);
        }
        pii ans = st.query();
        cout << ans.ff << " " << ans.ss << endl;
    }

    return 0;
}

signed main() {
    fastio;

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
