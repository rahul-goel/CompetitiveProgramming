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
    struct node {
        ll numel;
        ll prefix[2];
        ll suffix[2];
        ll ans[2];
    };

    vector < node > t;

    SegmentTree(ll n) {
        t.resize(n << 2);
    }

    node merge(node &a, node &b) {
        node ret;
        ret.prefix[0] = a.prefix[0];
        ret.suffix[0] = b.suffix[0];
        ret.prefix[1] = a.prefix[1];
        ret.suffix[1] = b.suffix[1];
        if (a.numel == a.prefix[0]) {
            ret.prefix[0] = max(ret.prefix[0], a.prefix[0] + b.prefix[0]);
        } else if (a.numel == a.prefix[1]) {
            ret.prefix[1] = max(ret.prefix[1], a.prefix[1] + b.prefix[1]);
        }
        if (b.numel == b.suffix[0]) {
            ret.suffix[0] = max(ret.suffix[0], a.suffix[0] + b.suffix[0]);
        } else if (b.numel == b.suffix[1]) {
            ret.suffix[1] = max(ret.suffix[1], a.suffix[1] + b.suffix[1]);
        }
        ret.ans[0] = max({a.ans[0], b.ans[0], ret.prefix[0], ret.suffix[0], a.suffix[0] + b.prefix[0]});
        ret.ans[1] = max({a.ans[1], b.ans[1], ret.prefix[1], ret.suffix[1], a.suffix[1] + b.prefix[1]});
        ret.numel = a.numel + b.numel;
        return ret;
    }

    void build(ll v, ll tl, ll tr, vi &vec) {
        if (tl == tr) {
            t[v].prefix[vec[tl]] = 1;
            t[v].suffix[vec[tl]] = 1;
            t[v].ans[vec[tl]] = 1;
            t[v].numel = 1;
            return;
        }

        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, vec);
        build(v << 1 | 1, tm + 1, tr, vec);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void update(ll v, ll tl, ll tr, ll pos) {
        if (tl == tr) {
            t[v].prefix[0] ^= 1;
            t[v].prefix[1] ^= 1;
            t[v].suffix[0] ^= 1;
            t[v].suffix[1] ^= 1;
            t[v].ans[0] ^= 1;
            t[v].ans[1] ^= 1;
            return;
        }

        ll tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos);
        }
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
};

ll solve() {
    string str;
    cin >> str;
    vi vec(str.size());
    ll n = str.size();
    for (ll i = 0; i < n; i++) {
        vec[i] = str[i] - '0';
    }

    SegmentTree st(n);
    st.build(1, 0, n - 1, vec);

    ll q;
    cin >> q;
    while (q--) {
        ll pos;
        cin >> pos;
        --pos;
        st.update(1, 0, n - 1, pos);
        cout << max(st.t[1].ans[0], st.t[1].ans[1]) << endl;
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
