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

ll overlap(pii a, pii b) {
    return min(a.ss, b.ss) - max(a.ff, b.ff);
}

ll same(pii a, pii b) {
    return max(b.ss, a.ss) - min(a.ff, b.ff);
}

ll solve() {
    ll n, k;
    cin >> n >> k;
    pii a, b;
    cin >> a.ff >> a.ss;
    cin >> b.ff >> b.ss;

    if (overlap(a, b) >= 0) {
        if (overlap(a, b) * n >= k) {
            cout << 0 << endl;
        } else {
            k -= overlap(a, b) * n;
            if ((same(a, b) - overlap(a, b)) * n >= k) {
                cout << k << endl;
            } else {
                cout << (k - (same(a, b) - overlap(a, b)) * n) * 2 + (same(a, b) - overlap(a, b)) * n << endl;
            }
        }
    } else {
        ll ans = LINF;
        for (ll in = 1; in <= n; in++) {
            ll kk = k;
            ll tmp = -overlap(a, b) * in;
            if (same(a, b) * in >= kk) {
                tmp += kk;
            } else {
                tmp += same(a, b) * in + (kk - same(a, b) * in) * 2;
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }

    return 0;
}

signed main() {
    fastio;

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
