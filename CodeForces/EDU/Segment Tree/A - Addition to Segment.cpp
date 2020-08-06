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
T mod_sum(T a, Args... args) { return ((a + MOD_sum(args...))%MOD + MOD)%MOD; }
/*******************************************************************************/
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a*MOD_prod(args...))%MOD; }
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
    vi t;

    SegmentTree (ll n) {
        t.resize(n << 2);
    }

    void push(ll v) {
        t[v << 1] += t[v];
        t[v << 1 | 1] += t[v];
        t[v] = 0;
    }

    void update(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
        if (ql <= tl && tr <= qr) {
            t[v] += val;
            return;
        }

        push(v);
        ll tm = (tl + tr) >> 1;
        if (ql <= tm) {
            update(v << 1, tl, tm, ql, qr, val);
        }
        if (tm + 1 <= qr) {
            update(v << 1 | 1, tm + 1, tr, ql, qr, val);
        }
    }

    ll query(ll v, ll tl, ll tr, ll pos) {
        if (tl == tr) {
            return t[v];
        }

        push(v);
        ll tm = (tl + tr) >> 1;
        if (pos <= tm) {
            return query(v << 1, tl, tm, pos);
        } else {
            return query(v << 1 | 1, tm + 1, tr, pos);
        }
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
            ll ql, qr, val;
            cin >> ql >> qr >> val;
            --qr;
            st.update(1, 0, n - 1, ql, qr, val);
        } else {
            ll pos;
            cin >> pos;
            cout << st.query(1, 0, n - 1, pos) << endl;
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

