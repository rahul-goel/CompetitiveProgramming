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

void fileio(string str) {
    string in = str + ".in";
    string out = str + ".out";
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
}

void vecout(vi &vec, ll start = -1, ll end = -1) {
    if (start == -1) {
        for (ll i = start; i < end; i++) {
            cout << vec[start] << " ";
        }
        cout << vec[end] << endl;
    } else {
        for (ll i = 0; i < (ll) vec.size() - 1; i++) {
            cout << vec[i] << " ";
        }
        cout << vec.back() << endl;
    }
}

ll solve() {
    ll n;
    cin >> n;
    vi vec(n + 5);
    vvi pre(n + 5, vi(3)), suf(n + 5, vi(3));

    for (ll i = 1; i <= n; i++) {
        char x;
        cin >> x;
        if (x == 'H') {
            vec[i] = 0;
        } else if(x == 'P') {
            vec[i] = 1;
        } else {
            vec[i] = 2;
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < 3; j++) {
            pre[i][j] += pre[i - 1][j];
            pre[i][j] += (vec[i] == j);
        }
    }
    for (ll i = n; i >= 1; i--) {
        for (ll j = 0; j < 3; j++) {
            suf[i][j] += suf[i + 1][j];
            suf[i][j] += (vec[i] == j);
        }
    }

    vpii moves = {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
    ll ans = 0;

    for (pii mv : moves) {
        ll x = mv.ff, y = mv.ss;
        for (ll i = 1; i <= n; i++) {
            ll win = 0;
            win += pre[i - 1][(x - 1 + 3) % 3];
            win += suf[i][(y - 1 + 3) % 3];
            ans = max(ans, win);
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;
    fileio("hps");

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
