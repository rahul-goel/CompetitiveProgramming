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

ll power(ll x, ll y, ll m) {
    ll ret = 1;
    while (y) {
        if (y & 1) {
            ret = (ret * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

ll solve() {
    string str;
    cin >> str;
    ll n = str.size();
    ll a, b;
    cin >> a >> b;
    for (char &x : str) {
        x -= '0';
    }

    vi rem(n);
    for (ll i = n - 1, val = 0; i >= 0; i--) {
        val = (val + str[i] * power(10, n - 1 - i, b)) % b;
        rem[i] = val;
    }

    for (ll i = 0, val = 0; i < n - 1; i++) {
        val = (val * 10 + str[i]) % a;
        if (val == 0 && str[i + 1] != 0 && rem[i + 1] == 0) {
            cout << "YES" << endl;

            string one = str.substr(0, i + 1);
            string two = str.substr(i + 1);
            for (char &x : one) {
                x += '0';
            }
            for (char &x : two) {
                x += '0';
            }

            cout << one << endl;
            cout << two << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

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
