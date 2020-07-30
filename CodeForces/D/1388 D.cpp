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

ll solve() {
    ll n;
    cin >> n;

    vi a(n), b(n);
    for (ll &x : a) {
        cin >> x;
    }
    for (ll &x : b) {
        cin >> x;
    }

    vi deg(n), posorder, negorder;
    for (ll i = 0; i < n; i++) {
        if (b[i] != -1) {
            b[i]--;
            deg[b[i]]++;
        }
    }

    queue < ll > q;
    for (ll i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    ll ans = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        ans += a[v];

        if (a[v] >= 0) {
            posorder.pb(v);
            if (b[v] != -1) {
                a[b[v]] += a[v];
            }
        } else {
            negorder.pb(v);
        }

        if (b[v] != -1) {
            deg[b[v]]--;
            if (deg[b[v]] == 0) {
                q.push(b[v]);
            }
        }
    }

    while (!negorder.empty()) {
        posorder.pb(negorder.back());
        negorder.pop_back();
    }

    cout << ans << endl;
    for (ll v : posorder) {
        cout << ++v << " ";
    }
    cout << endl;

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
