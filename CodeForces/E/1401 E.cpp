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
    SegmentTree(ll n) {
        t.resize(n << 2);
    }

    void add(ll v, ll tl, ll tr, ll pos, ll val) {
        if (tl == tr) {
            t[v] += val;
            return;
        }
        ll tm = (tl + tr) >> 1;
        if (pos <= tm) {
            add(v << 1, tl, tm, pos, val);
        } else {
            add(v << 1 | 1, tm + 1, tr, pos, val);
        }
        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    ll sum(ll v, ll tl, ll tr, ll ql, ll qr) {
        if (ql <= tl && tr <= qr) {
            return t[v];
        }
        ll tm = (tl + tr) >> 1;
        ll ret = 0;
        if (ql <= tm) {
            ret += sum(v << 1, tl, tm, ql, qr);
        }
        if (tm + 1 <= qr) {
            ret += sum(v << 1 | 1, tm + 1, tr, ql, qr);
        }
        t[v] = t[v << 1] + t[v << 1 | 1];
        return ret;
    }
};

ll solve() {
    ll n, m;
    cin >> n >> m;

    SegmentTree st(1000005);
    ll ans = 1;
    vvi left(1e6 + 5), right(1e6 + 5), track(1e6 + 5);
    vi y, lx, rx, x, ly, ry;
    y = lx = rx = x = ly = ry = vi(1e6 + 5);

    for (ll i = 0; i < n; i++) {
        cin >> y[i] >> lx[i] >> rx[i];
        if (lx[i] == 0 && rx[i] == 1000000) {
            ans++;
        }
        left[lx[i]].pb(i);
        right[rx[i] + 1].pb(i);
    }

    for (ll i = 0; i < m; i++) {
        cin >> x[i] >> ly[i] >> ry[i];
        if (ly[i] == 0 && ry[i] == 1000000) {
            ans++;
        }
        track[x[i]].push_back(i);
    }

    for (ll i = 0; i <= 1000000; i++) {
        for (ll j : left[i]) {
            st.add(1, 0, 1000004, y[j], 1);
        }
        for (ll j : right[i]) {
            st.add(1, 0, 1000004, y[j], -1);
        }
        for (ll j : track[i]) {
            if (ly[j] == 0) {
                ans += st.sum(1, 0, 1000004, 0, ry[j]);
            } else {
                ans += st.sum(1, 0, 1000004, ly[j], 1000000);
            }
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
