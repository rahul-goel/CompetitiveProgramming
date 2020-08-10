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

int up[2005][2005], down[2005][2005], lft[2005][2005], rght[2005][2005];
int toup[2005][2005], todown[2005][2005], tolft[2005][2005], torght[2005][2005];
int mat[2005][2005];

int solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            mat[i][j] = (x + 100);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] == mat[i][j - 1]) {
                tolft[i][j] = tolft[i][j - 1] + 1;
            } else {
                tolft[i][j] = 0;
            }
        }
        for (int j = m; j >= 1; j--) {
            if (mat[i][j] == mat[i][j + 1]) {
                torght[i][j] = torght[i][j + 1] + 1;
            } else {
                torght[i][j] = 0;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (mat[i][j] == mat[i - 1][j]) {
                toup[i][j] = toup[i - 1][j] + 1;
            } else {
                toup[i][j] = 0;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (mat[i][j] == mat[i + 1][j]) {
                todown[i][j] = todown[i + 1][j] + 1;
            } else {
                todown[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] != mat[i][j - 1]) {
                lft[i][j] = 1;
            } else {
                lft[i][j] = min({lft[i][j - 1], toup[i][j], todown[i][j]}) + 1;
            }
        }
        for (int j = m; j >= 1; j--) {
            if (mat[i][j] != mat[i][j + 1]) {
                rght[i][j] = 1;
            } else {
                rght[i][j] = min({rght[i][j + 1], toup[i][j], todown[i][j]}) + 1;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (mat[i][j] != mat[i - 1][j]) {
                up[i][j] = 1;
            } else {
                up[i][j] = min({up[i - 1][j], tolft[i][j], torght[i][j]}) + 1;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (mat[i][j] != mat[i + 1][j]) {
                down[i][j] = 1;
            } else {
                down[i][j] = min({down[i + 1][j], tolft[i][j], torght[i][j]}) + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += min({lft[i][j], rght[i][j], up[i][j], down[i][j]});
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
