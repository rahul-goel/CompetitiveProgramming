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

bool vis[205][205][205] = {false};
ll dp[205][205][205];

ll f(ll r, ll g, ll b, vi& rr, vi& gg, vi& bb) {
    ll cnt0 = !r + !b + !g;
    if (cnt0 >= 2) {
        return 0;
    }
    if (vis[r][g][b]) {
        return dp[r][g][b];
    }
    vis[r][g][b] = true;
    if (r == 0) {
        return dp[r][g][b] = gg[g] * bb[b] + f(r, g - 1, b - 1, rr, gg, bb);
    }
    if (g == 0) {
        return dp[r][g][b] = rr[r] * bb[b] + f(r - 1, g, b - 1, rr, gg, bb);
    }
    if (b == 0) {
        return dp[r][g][b] = gg[g] * rr[r] + f(r - 1, g - 1, b, rr, gg, bb);
    }
    return dp[r][g][b] = max({gg[g] * bb[b] + f(r, g - 1, b - 1, rr, gg, bb), rr[r] * bb[b] + f(r - 1, g, b - 1, rr, gg, bb), gg[g] * rr[r] + f(r - 1, g - 1, b, rr, gg, bb)});
}

ll solve() {
    ll r, g, b;
    cin >> r >> g >> b;
    vi rr(r), gg(g), bb(b);
    for (ll &x : rr) {
        cin >> x;
    }
    for (ll &x : gg) {
        cin >> x;
    }
    for (ll &x : bb) {
        cin >> x;
    }

    sort(all(rr));
    reverse(all(rr)), rr.pb(0), reverse(all(rr));
    sort(all(bb));
    reverse(all(bb)), bb.pb(0), reverse(all(bb));
    sort(all(gg));
    reverse(all(gg)), gg.pb(0), reverse(all(gg));
    ll ans = f(r, g, b, rr, gg, bb);
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
