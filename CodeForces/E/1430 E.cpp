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
    vi t, lz;

    SegmentTree (ll n) {
        t.resize(n << 2);
        lz.resize(n << 2);
    }

    void push(ll v) {
        if (lz[v]) {
            lz[v << 1] += lz[v];
            lz[v << 1 | 1] += lz[v];
            t[v << 1] += lz[v];
            t[v << 1 | 1] += lz[v];
            lz[v] = 0;
        }
    }

    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = tl;
        } else {
            ll tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
        }
    }

    void add(ll v, ll tl, ll tr, ll ql, ll qr, ll val) {
        if (ql <= tl && tr <= qr) {
            t[v] += val;
            lz[v] += val;
            return;
        }
        ll tm = (tl + tr) >> 1;
        push(v);
        if (ql <= tm) {
            add(v << 1, tl, tm, ql, qr, val);
        }
        if (tm + 1 <= qr) {
            add(v << 1 | 1, tm + 1, tr, ql, qr, val);
        }
    }

    ll query(ll v, ll tl, ll tr, ll pos) {
        if (tl == tr) {
            return t[v];
        }
        ll tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) {
            return query(v << 1, tl, tm, pos);
        } else {
            return query(v << 1 | 1, tm + 1, tr, pos);
        }
    }
};

ll solve() {
    ll n;
    cin >> n;
    string str;
    cin >> str;

    vvi idx(128);

    for (ll i = 0; i < n; i++) {
        idx[str[i]].pb(i);
    }
    for (ll i = 'a'; i <= 'z'; i++) {
        reverse(all(idx[i]));
    }

    string rev = str;
    reverse(all(rev));

    vi assign(n);
    for (ll i = 0; i < n; i++) {
        assign[i] = idx[rev[i]].back();
        idx[rev[i]].pop_back();
    }

    SegmentTree st(n);
    st.build(1, 0, n - 1);

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll curpos = st.query(1, 0, n - 1, assign[i]);
        ans += curpos - i;
        if (0 <= assign[i] - 1) {
            st.add(1, 0, n - 1, 0, assign[i] - 1, 1);
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
