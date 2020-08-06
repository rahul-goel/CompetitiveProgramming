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

struct SegmentTree {
    vi t;
    SegmentTree(ll n) {
        t.resize(n << 2);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll val) {
        if (tl == tr) {
            t[v] = val;
            return;
        }

        ll tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos, val);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, val);
        }
        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    ll query(ll v, ll tl, ll tr, ll ql, ll qr) {
        if (ql <= tl && tr <= qr) {
            return t[v];
        }

        ll tm = (tl + tr) >> 1;
        ll ret = 0;
        if (ql <= tm) {
            ret += query(v << 1, tl, tm, ql, qr);
        }
        if (tm + 1 <= qr) {
            ret += query(v << 1 | 1, tm + 1, tr, ql, qr);
        }
        return ret;
    }
};

vi ind, sts, tour;
vvi adj;

void add_edge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

void dfs(ll v, ll parent) {
    ind[v] = tour.size();
    tour.pb(v);
    sts[v] = 0;
    for (ll u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            sts[v] += sts[u] + 1;
        }
    }
}

ll solve() {
    ll n, q;
    cin >> n >> q;
    ind.resize(n), sts.resize(n), adj.resize(n);

    vi vec(n);
    for (ll &x : vec) {
        cin >> x;
    }

    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    dfs(0, -1);
    SegmentTree st(n);

    for (ll i = 0; i < n; i++) {
        st.update(1, 0, n - 1, ind[i], vec[i]);
    }

    while (q--) {
        ll choice;
        cin >> choice;
        if (choice == 1) {
            ll v, val;
            cin >> v >> val;
            --v;
            ll pos = ind[v];
            st.update(1, 0, n - 1, pos, val);
        } else {
            ll v;
            cin >> v;
            --v;
            cout << st.query(1, 0, n - 1, ind[v], ind[v] + sts[v]) << endl;
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
