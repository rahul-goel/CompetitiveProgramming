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

vvpii adj;
vi w, lv;
max_pq(pii) pq;
ll sum = 0;

void add_edge(ll u, ll v, ll id) {
    adj[u].pb({v, id});
    adj[v].pb({u, id});
}

ll dfs(ll v, ll p) {
    if (v != 0 && adj[v].size() == 1) {
        return 1;
    }
    ll ret = 0;
    for (pii ed : adj[v]) {
        ll u = ed.ff, uw = w[ed.ss];
        if (p != u) {
            ll cnt = dfs(u, v);
            ret += cnt;
            lv[ed.ss] = cnt;
            ll diff = uw * cnt - uw / 2 * cnt;
            pq.push({diff, ed.ss});
            sum += uw * cnt;
        }
    }
    return ret;
}

ll solve() {
    adj.clear();
    w.clear();
    lv.clear();
    while (!pq.empty()) {
        pq.pop();
    }
    sum = 0;

    ll n, s;
    cin >> n >> s;
    adj.resize(n);
    w.resize(n - 1);
    lv.resize(n - 1);

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v >> w[i];
        --u, --v;
        add_edge(u, v, i);
    }

    dfs(0, -1);
    ll ans = 0;

    while (sum > s) {
        pii topper = pq.top();
        pq.pop();
        ll &ww = w[topper.ss];
        ll &cnt = lv[topper.ss];
        sum -= ww * cnt;
        ww /= 2;
        sum += ww * cnt;
        pq.push({ww * cnt - ww / 2 * cnt, topper.ss});
        ans++;
    }

    cout << ans << endl;

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
