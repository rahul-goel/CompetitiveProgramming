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

void transposeswap(vvi &mat, ll &n, ll &m) {
    vvi change(m, vi(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            change[j][i] = mat[i][j];
        }
    }
    mat.swap(change);
    swap(n, m);
}

ll solve() {
    ll n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char x;
            cin >> x;
            mat[i][j] = (x == '1');
        }
    }

    if (min(n, m) > 3) {
        cout << - 1 << endl;
        return 0;
    } else if (min(n, m) == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (m == 2) {
        transposeswap(mat, n, m);
    }

    if (n == 2) {
        vvi dp(m, vi(4, LINF));

        for (ll mask = 0; mask < 4; mask++) {
            dp[0][mask] = (mat[0][0] != (mask & 1)) + (mat[1][0] != ((mask >> 1) & 1));
        }

        for (ll i = 1; i < m; i++) {
            for (ll cmask = 0; cmask < 4; cmask++) {
                ll cost = (mat[0][i] != (cmask & 1)) + (mat[1][i] != ((cmask >> 1) & 1));
                for (ll pmask = 0; pmask < 4; pmask++) {
                    if ((cmask ^ pmask) == 1 || (cmask ^ pmask) == 2) {
                        dp[i][cmask] = min(dp[i][cmask], dp[i - 1][pmask] + cost);
                    }
                }
            }
        }

        ll ans = *min_element(all(dp.back()));
        cout << ans << endl;
        return 0;
    }

    if (m == 3) {
        transposeswap(mat, n, m);
    }

    if (n == 3) {
        vvi dp(m, vi(8, LINF));

        for (ll mask = 0; mask < 8; mask++) {
            dp[0][mask] = (mat[0][0] != (mask & 1)) + (mat[1][0] != ((mask >> 1) & 1)) + (mat[2][0] != ((mask >> 2) & 1));
        }

        for (ll i = 1; i < m; i++) {
            for (ll cmask = 0; cmask < 8; cmask++) {
                ll cost = (mat[0][i] != (cmask & 1)) + (mat[1][i] != ((cmask >> 1) & 1)) + (mat[2][i] != ((cmask >> 2) & 1));
                for (ll pmask = 0; pmask < 8; pmask++) {
                    if ((cmask ^ pmask) == 2 || (cmask ^ pmask) == 5) {
                        dp[i][cmask] = min(dp[i][cmask], dp[i - 1][pmask] + cost);
                    }
                }
            }
        }

        ll ans = *min_element(all(dp.back()));
        cout << ans << endl;
        return 0;
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
