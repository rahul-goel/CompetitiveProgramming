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
using pii = pair < int, int >;
using vi = vector < int >;
using vb = vector < bool >;
using vvi = vector < vector < int > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
    Code begins after this.
*/

struct SegmentTree {
    vi t, lz;
    SegmentTree(int n) {
        t.resize(n << 2);
        lz.resize(n << 2);
    }

    void push(int v) {
        lz[v << 1] |= lz[v];
        lz[v << 1 | 1] |= lz[v];
        t[v << 1] |= lz[v];
        t[v << 1 | 1] |= lz[v];
        lz[v] = 0;
    }

    void pull(int v) {
        t[v] = t[v << 1] & t[v << 1 | 1];
    }

    void update(int v, int tl, int tr, int ql, int qr, int val) {
        if (ql <= tl && tr <= qr) {
            lz[v] |= val;
            t[v] |= val;
            return;
        }

        push(v);
        int tm = (tl + tr) >> 1;
        if (ql <= tm) {
            update(v << 1, tl, tm, ql, qr, val);
        }
        if (tm + 1 <= qr) {
            update(v << 1 | 1, tm + 1, tr, ql, qr, val);
        }
        pull(v);
    }

    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql <= tl && tr <= qr) {
            return t[v];
        }

        push(v);
        int ret = (1 << 30) - 1;
        int tm = (tl + tr) >> 1;
        if (ql <= tm) {
            ret &= query(v << 1, tl, tm, ql, qr);
        }
        if (tm + 1 <= qr) {
            ret &= query(v << 1 | 1, tm + 1, tr, ql, qr);
        }
        pull(v);
        return ret;
    }

};

int solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree st(n);

    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int ql, qr, val;
            cin >> ql >> qr >> val;
            --qr;
            st.update(1, 0, n - 1, ql, qr, val);
        } else {
            int ql, qr;
            cin >> ql >> qr;
            --qr;
            cout << st.query(1, 0, n - 1, ql, qr) << endl;
        }
    }

    return 0;
}

signed main() {
    fastio;

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
