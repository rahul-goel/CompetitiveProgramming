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

struct SegmentTree{
    vi t;

    SegmentTree (ll n) {
        t.resize(n << 2);
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
        return ret;
    }

    void upd(ll v, ll tl, ll tr, ll pos, ll val) {
        if (tl == tr) {
            t[v] = val;
            return;
        }
        ll tm = (tl + tr) >> 1;
        if (pos <= tm) {
            upd(v << 1, tl, tm, pos, val);
        } else {
            upd(v << 1 | 1, tm + 1, tr, pos, val);
        }
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
};

vi fac(20);

vi get(ll start, ll end, ll x) {
    ll sz = end - start + 1;
    vi v;

    ordered_set<ll> s;
    for (ll i = start; i <= end; i++) {
        s.insert(i);
    }

    for (ll i = 0; i < sz; i++) {
        if (i == sz - 1) {
            v.pb(*s.begin());
            s.erase(s.begin());
            continue;
        }
        if (x >= fac[sz - i - 1]) {
            ll y = x / fac[sz - i - 1];
            v.pb(*s.find_by_order(y));
            s.erase(s.find_by_order(y));
            x -= y * fac[sz - i - 1];
        } else {
            v.pb(*s.begin());
            s.erase(s.begin());
        }
    }

    return v;
}

ll solve() {
    fac.front() = 1;
    for (ll i = 1; i < 20; i++) {
        fac[i] = fac[i - 1] * i;
    }

    ll n, m;
    cin >> n >> m;

    SegmentTree st(n);
    for (ll i = 0; i < n; i++) {
        st.upd(1, 0, n - 1, i, i + 1);
    }

    ll tot = 0;

    while (m--) {
        ll ch;
        cin >> ch;
        if (ch == 1) {
            ll ql, qr;
            cin >> ql >> qr;
            --ql, --qr;
            cout << st.sum(1, 0, n - 1, ql, qr) << endl;
        } else {
            ll x;
            cin >> x;
            tot += x;
            vi v = get(max(n - 15, 1ll), n, tot);
            for (ll i = n - 1; v.size(); i--) {
                st.upd(1, 0, n - 1, i, v.back());
                v.pop_back();
            }
        }
    }

    return 0;
}

signed main() {
    fastio;

    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
