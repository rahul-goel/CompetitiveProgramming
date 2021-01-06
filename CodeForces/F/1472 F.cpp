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
    ll n, m;
    cin >> n >> m;

    map<ll,ll> mp;

    for (ll i = 0; i < m; i++) {
        ll r, c;
        cin >> r >> c;
        if (present(mp, c)) {
            mp[c] = 3;
        } else {
            mp[c] = r;
        }
    }

    ll flag = 0;
    ll prev = 0;
    for (auto &[k, p] : mp) {
        if (flag == 0) {
            if (p == 3) {
                flag = 0;
            } else if (p == 2) {
                flag = 2;
            } else if (p == 1) {
                flag = 1;
            }
        } else if (flag == 1) {
            if (p == 3) {
                // fully blocked
                cout << "NO" << endl;
                return 0;
            } else if (p == 2) {
                if ((prev & 1) != (k & 1)) {
                    // double different parity
                    cout << "NO" << endl;
                    return 0;
                }
                flag = 0;
            } else if (p == 1) {
                if ((prev & 1) == (k & 1)) {
                    // double same parity
                    cout << "NO" << endl;
                    return 0;
                }
                flag = 0;
            }
        } else if (flag == 2) {
            if (p == 3) {
                cout << "NO" << endl;
                return 0;
            } else if (p == 2) {
                if ((prev & 1) == (k & 1)) {
                    // double same parity
                    cout << "NO" << endl;
                    return 0;
                }
                flag = 0;
            } else if (p == 1) {
                if ((prev & 1) != (k & 1)) {
                    // double different parity
                    cout << "NO" << endl;
                    return 0;
                }
                flag = 0;
            }
        }

        prev = k;
    }

    if (flag == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
