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

ll mat[71][71];
ll dp[71][71][71][71];

ll solve() {

    for (ll i = 0; i < 71; i++) {
        for (ll j = 0; j < 71; j++) {
            for (ll k = 0; k < 71; k++) {
                for (ll l = 0; l < 71; l++) {
                    dp[i][j][k][l] = -LINF;
                }
            }
        }
    }

    ll n, m, k;
    cin >> n >> m >> k;
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    dp[0][0][0][0] = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            for (ll cnt = 0; cnt < m / 2 + 1; cnt++) {
                for (ll rem = 0; rem < k; rem++) {
                    if (dp[i][j][cnt][rem] == -LINF) {
                        continue;
                    }
                    ll ni = (j == m - 1 ? i + 1 : i);
                    ll nj = (j == m - 1 ? 0 : j + 1);

                    if (i != ni) {
                        dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
                    } else {
                        dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
                    }

                    if (cnt + 1 <= m / 2) {
                        ll nrem = (rem + mat[i][j]) % k;
                        if (i != ni) {
                            dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + mat[i][j]);
                        } else {
                            dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + mat[i][j]);
                        }
                    }

                }
            }
        }
    }

    cout << dp[n][0][0][0] << endl;

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
