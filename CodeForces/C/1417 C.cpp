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

ll solve() {
    ll n;
    cin >> n;

    vi vec(n);
    vvi ind(n);

    for (ll i = 0; i < n; i++) {
        ind[i].pb(0);
    }

    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
        --vec[i];
        ind[vec[i]].pb(i + 1);
    }

    for (ll i = 0; i < n; i++) {
        ind[i].pb(n + 1);
    }

    vi mxgap(n);

    for (ll i = 0; i < n; i++) {
        ll mx = -LINF;
        for (ll j = 1; j < (ll) ind[i].size(); j++) {
            mx = max(mx, ind[i][j] - ind[i][j - 1]);
        }
        mxgap[i] = mx;
    }

    vi ans(n + 5, LINF);
    for (ll i = 0; i < n; i++) {
        if (ans[mxgap[i]] > i + 1) {
            ans[mxgap[i]] = i + 1;
        }
    }

    ll y = LINF;
    for (ll i = 1; i <= n; i++) {
        if (ans[i] == LINF || ans[i] > y) {
            ans[i] = y;
        } else {
            y = ans[i];
        }
    }

    for (ll i = 1; i <= n; i++) {
        if (ans[i] == LINF) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;

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
