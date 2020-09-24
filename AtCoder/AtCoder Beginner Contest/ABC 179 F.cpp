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
    vi lz;

    SegmentTree(ll n) {
        t.resize(n << 2);
        lz.resize(n << 2);
    }

    void push(ll v) {
        if (lz[v] < LINF) {
            t[v << 1] = min(t[v << 1], lz[v]);
            t[v << 1 | 1] = min(t[v << 1 | 1], lz[v]);
            lz[v << 1] = min(lz[v << 1], lz[v]);
            lz[v << 1 | 1] = min(lz[v << 1 | 1], lz[v]);
            lz[v] = LINF;
        }
    }

    void build(ll v, ll tl, ll tr, ll n) {
        if (tl == tr) {
            t[v] = n;
            lz[v] = LINF;
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, n);
        build(v << 1 | 1, tm + 1, tr, n);
        lz[v] = LINF;
    }

    void update(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
        if (ql <= tl && tr <= qr) {
            t[v] = min(t[v], val);
            lz[v] = min(lz[v], val);
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

    SegmentTree x(n + 5), y(n + 5);
    ll st = 0, en = n + 4;
    x.build(1, st, en, n - 1);
    y.build(1, st, en, n - 1);

    ll ans = (n - 2) * (n - 2);

    while (q--) {
        ll type, which;
        cin >> type >> which;
        if (type == 1) {
            ll till_where = x.query(1, st, en, which);
            y.update(1, st, en, 2, till_where, which - 1);
            ans -= till_where - 1;
        } else {
            ll till_where = y.query(1, st, en, which);
            x.update(1, st, en, 2, till_where, which - 1);
            ans -= till_where - 1;
        }
    }

    cout << ans << endl;

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
