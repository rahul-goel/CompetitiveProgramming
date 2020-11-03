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


ll solve() {
    ll n, m;
    cin >> n >> m;

    vi a(n), b(m);
    for (ll &x : a) {
        cin >> x;
        --x;
    }
    for (ll &x : b) {
        cin >> x;
        --x;
    }

    vi ind(n);
    for (ll i = 0; i < n; i++) {
        ind[a[i]] = i;
    }

    set<pii> sa;
    for (ll i = 0; i < n; i++) {
        sa.insert({i, a[i]});
    }
    set<ll> sb;
    for (ll &x : b) {
        sb.insert(x);
    }

    ll ans = 1;

    for (ll &x : b) {
        ll i = ind[x];
        auto it = sa.lower_bound({i, -LINF});
        if (it == sa.begin()) {
            ll y = (++it)->ss;
            if (present(sb, y)) {
                cout << 0 << endl;
                return 0;
            } else {
                sa.erase(it);
                sb.erase(x);
            }
        } else if (it == --sa.end()) {
            ll y = (--it)->ss;
            if (present(sb, y)) {
                cout << 0 << endl;
                return 0;
            } else {
                sa.erase(it);
                sb.erase(x);
            }
        } else {
            auto itb = prev(it);
            auto ita = next(it);
            if (present(sb, itb->ss) && present(sb, ita->ss)) {
                cout << 0 << endl;
                return 0;
            } else if (present(sb, itb->ss)) {
                sa.erase(ita);
                sb.erase(x);
            } else if (present(sb, ita->ss)) {
                sa.erase(itb);
                sb.erase(x);
            } else {
                sa.erase(itb);
                sb.erase(x);
                ans *= 2;
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;

    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
