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
const ll MOD = 998244353;
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

vi power, one;

struct SegmentTree {
    vi t, lz;

    SegmentTree(ll n) {
        t = lz = vi(n << 2);
    }

    void pull(ll v, ll tl, ll tm, ll tr) {
        t[v] = ((t[v << 1] * power[tr - tm]) % MOD + t[v << 1 | 1]) % MOD;
    }

    void push(ll v, ll tl, ll tm, ll tr) {
        if (lz[v] != -1) {
            lz[v << 1] = lz[v];
            lz[v << 1 | 1] = lz[v];
            t[v << 1] = (one[tm - tl + 1] * lz[v]) % MOD;
            t[v << 1 | 1] = (one[tr - tm] * lz[v]) % MOD;
            lz[v] = -1;
        }
    }

    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = 1;
            lz[v] = -1;
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        pull(v, tl, tm, tr);
        lz[v] = -1;
    }


    void update(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
        if (ql <= tl && tr <= qr) {
            t[v] = (one[tr - tl + 1] * val) % MOD;
            lz[v] = val;
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
        pull(v, tl, tm, tr);
        lz[v] = -1;
    }

    ll query() {
        return t[1];
    }
};

ll solve() {
    ll n, q;
    cin >> n >> q;
    power = one = vi(n + 5);

    power[0] = 1;
    for (ll i = 1; i < (ll) power.size(); i++) {
        power[i] = (power[i - 1] * 10) % MOD;
    }
    one[0] = 0;
    for (ll i = 1; i < (ll) one.size(); i++) {
        one[i] = (one[i - 1] * 10 + 1) % MOD;
    }

    SegmentTree st(n);
    st.build(1, 0, n - 1);
    for (ll i = 0; i < q; i++) {
        ll l, r, val;
        cin >> l >> r >> val;
        --l, --r;
        st.update(1, 0, n - 1, l, r, val);
        cout << st.query() << endl;
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
