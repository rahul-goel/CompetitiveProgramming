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

void fileio(string str) {
    string in = str + ".in";
    string out = str + ".out";
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
}

void vecout(vi &vec, ll start = -1, ll end = -1) {
    if (start != -1) {
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
    ll n, m;
    cin >> n >> m;
    vector < string > spotty(n), plain(n);

    for (string &x : spotty) {
        cin >> x;
    }
    for (string &x : plain) {
        cin >> x;
    }

    for (string &x : spotty) {
        for (ll i = 0; i < m; i++) {
            switch (x[i]) {
                case 'A':
                    x[i] = 0;
                    break;
                case 'C':
                    x[i] = 1;
                    break;
                case 'G':
                    x[i] = 2;
                    break;
                case 'T':
                    x[i] = 3;
                    break;
            }
        }
    }
    for (string &x : plain) {
        for (ll i = 0; i < m; i++) {
            switch (x[i]) {
                case 'A':
                    x[i] = 0;
                    break;
                case 'C':
                    x[i] = 1;
                    break;
                case 'G':
                    x[i] = 2;
                    break;
                case 'T':
                    x[i] = 3;
                    break;
            }
        }
    }

    ll ans = 0;

    for (ll i = 0; i < m; i++) {
        for (ll j = i + 1; j < m; j++) {
            for (ll k = j + 1; k < m; k++) {
                vb vis(64);
                bool flag = true;
                for (string &x : spotty) {
                    vis[x[i] * 16 + x[j] * 4 + x[k]] = true;
                }
                for (string &x : plain) {
                    if (vis[x[i] * 16 + x[j] * 4 + x[k]]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;
    fileio("cownomics");

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
