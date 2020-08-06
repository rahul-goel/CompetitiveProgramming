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
using pii = pair < int, int >;
using vi = vector < int >;
using vb = vector < bool >;
using vvi = vector < vector < int > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
    Code begins after this.
*/

int f(int l, int r, vvi &dp, vvi &rg) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = 0;

    //does l, r segment exist?
    int exist = count(all(rg[l]), r);
    dp[l][r] = max(dp[l][r], exist + (l + 1 > r ? 0 : f(l + 1, r, dp, rg)));
    for (auto nr : rg[l]) {
        if (nr < r) {
            dp[l][r] = max(dp[l][r], exist + f(l, nr, dp, rg) + (nr + 1 > r ? 0 : f(nr + 1, r, dp, rg)));
        }
    }
    return dp[l][r];
}

int solve() {
    int n;
    cin >> n;
    vpii vec(n);
    vi points(n);
    for (auto &x : vec) {
        cin >> x.ff >> x.ss;
        points.pb(x.ff);
        points.pb(x.ss);
    }
    sort(all(points));
    uniq(points);
    for (auto &x : vec) {
        x.ff = lower_bound(all(points), x.ff) - points.begin();
        x.ss = lower_bound(all(points), x.ss) - points.begin();
    }

    vvi dp(points.size(), vi(points.size(), -1));
    vvi rg(points.size());

    for (auto x : vec) {
        rg[x.ff].pb(x.ss);
    }

    cout << f(0, points.size() - 1, dp, rg) << endl;

    return 0;
}

signed main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
