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

ll solve() {
    ll n, q;
    cin >> n >> q;

    vvi vec(n + 1, vi(3));
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        --x;
        vec[i][x] = 1;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < 3; j++) {
            vec[i][j] += vec[i-1][j];
        }
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        for (ll i = 0; i < 2; i++) {
            cout << vec[b][i] - vec[a - 1][i] << " ";
        }
        cout << vec[b][2] - vec[a - 1][2];
        cout << endl;
    }

    return 0;
}

signed main() {
    fastio;

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
