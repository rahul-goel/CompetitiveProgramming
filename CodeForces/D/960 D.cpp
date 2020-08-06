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

vi shift(63);

void do_shift(ll lvl, ll k) {
    shift[lvl] = ((shift[lvl] + k) % (1LL << lvl) + (1LL << lvl)) % (1LL << lvl);
}

ll find_pos(ll lvl, ll val) {
    ll og_pos = val - (1LL << lvl);
    return (og_pos + shift[lvl] + (1LL << lvl)) % (1LL << lvl);
}

ll find_at_pos(ll lvl, ll pos) {
    return (pos - shift[lvl] + (1LL << lvl)) % (1LL << lvl) + (1LL << lvl);
}

ll find_lvl(ll val) {
    return (ll) log2(val);
}

ll solve() {
    ll q;
    cin >> q;

    while (q--) {
        ll t;
        cin >> t;

        if (t == 1LL) {
            ll x, k;
            cin >> x >> k;
            ll lvl = find_lvl(x);
            do_shift(lvl, k);
        } else if (t == 2) {
            ll x, k;
            cin >> x >> k;
            ll lvl = find_lvl(x);
            for (ll i = lvl; i < 63; i++) {
                do_shift(i, k);
                k *= 2;
            }
        } else {
            ll x;
            cin >> x;
            vi ans;
            ll lvl = find_lvl(x);
            ll pos = find_pos(lvl, x);
            for (ll i = lvl; i >= 0; i--) {
                ans.pb(find_at_pos(i, pos));
                pos >>= 1LL;
            }
            for (ll aa : ans) {
                cout << aa << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

signed main() {
    fastio;

    ll t = 1LL;
    while (t--) {
        solve();
    }
    return 0;
}
