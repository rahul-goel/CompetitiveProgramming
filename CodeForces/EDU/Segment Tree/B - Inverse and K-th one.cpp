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

struct SegmentTree {
    vi t;
    vb lz;

    SegmentTree(ll n) {
        t.resize(n << 2);
        lz.resize(n << 2);
    }

    void push(ll v, ll tl, ll tm, ll tr) {
        if (lz[v]) {
            lz[v] = false;
            lz[v << 1] = !lz[v << 1];
            lz[v << 1 | 1] = !lz[v << 1 | 1];

            ll numel_l = (tm - tl + 1);
            t[v << 1] = numel_l - t[v << 1];
            ll numel_r = (tr - tm);
            t[v << 1 | 1] = numel_r - t[v << 1 | 1];
        }
    }

    void pull(ll v) {
        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    void update(ll v, ll tl, ll tr, ll ql, ll qr) {
        if (ql <= tl && tr <= qr) {
            ll numel = (tr - tl + 1);
            t[v] = numel - t[v];
            lz[v] = !lz[v];
            return;
        }

        ll tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if (ql <= tm) {
            update(v << 1, tl, tm, ql, qr);
        }
        if (tm + 1 <= qr) {
            update(v << 1 | 1, tm + 1, tr, ql, qr);
        }
        pull(v);
    }

    ll query(ll v, ll tl, ll tr, ll rank) {
        if (tl == tr) {
            return tl;
        }
        ll tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        ll ret;
        if (t[v << 1] > rank) {
            ret = query(v << 1, tl, tm, rank);
        } else {
            ret = query(v << 1 | 1, tm + 1, tr, rank - t[v << 1]);
        }
        pull(v);
        return ret;
    }
};

ll solve() {
    ll n, q;
    cin >> n >> q;
    SegmentTree st(n);

    while (q--) {
        ll ch;
        cin >> ch;
        if (ch == 1) {
            ll ql, qr;
            cin >> ql >> qr;
            --qr;
            st.update(1, 0, n - 1, ql, qr);
        } else {
            ll rank;
            cin >> rank;
            cout << st.query(1, 0, n - 1, rank) << endl;
        }
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
