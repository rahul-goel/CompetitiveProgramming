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

struct SegmentTree {
    vi t, lz;

    SegmentTree(ll n) {
        t.resize(n << 2);
        lz.resize(n << 2);
    }

    void push(ll v) {
        if (lz[v]) {
            t[v << 1] += lz[v];
            t[v << 1] %= MOD;

            t[v << 1 | 1] += lz[v];
            t[v << 1 | 1] %= MOD;

            lz[v << 1] += lz[v];
            lz[v << 1] %= MOD;

            lz[v << 1 | 1] += lz[v];
            lz[v << 1 | 1] %= MOD;

            lz[v] = 0;
        }
    }

    void add(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
        if (ql <= tl && tr <= qr) {
            t[v] += val;
            t[v] %= MOD;
            lz[v] += val;
            lz[v] %= MOD;
            return;
        }
        push(v);
        ll tm = (tl + tr) >> 1;
        if (ql <= tm) {
            add(v << 1, tl, tm, ql, qr, val);
        }
        if (tm + 1 <= qr) {
            add(v << 1 | 1, tm + 1, tr, ql, qr, val);
        }
        t[v] = t[v << 1] + t[v << 1 | 1];
        t[v] %= MOD;
    }

    ll query(ll v, ll tl, ll tr, ll pos) {
        if (tl == tr) {
            return t[v];
        }
        push(v);
        ll tm = (tl + tr) >> 1;
        ll ret;
        if (pos <= tm) {
            ret = query(v << 1, tl, tm, pos);
        } else {
            ret = query(v << 1 | 1, tm + 1, tr, pos);
        }
        t[v] = t[v << 1] + t[v << 1 | 1];
        t[v] %= MOD;
        return ret;
    }
};

ll solve() {
    ll n;
    cin >> n;
    ll k;
    cin >> k;

    SegmentTree st(n);

    vpii vec(k);
    for (auto &x : vec) {
        cin >> x.ff >> x.ss;
    }

    st.add(1, 0, n - 1, 0, 0, 1);
    for (ll i = 0; i < n - 1; i++) {
        ll val = st.query(1, 0, n - 1, i);
        for (auto &x : vec) {
            if (x.ff + i >= n) {
                continue;
            }
            st.add(1, 0, n - 1, max(0ll, i + x.ff), min(n - 1, i + x.ss), val);
        }
    }

    cout << st.query(1, 0, n - 1, n - 1) << endl;

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
