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

vector < vector < array < ll, 3 > > > adj;
vector<ll> w, lv;
max_pq(pii) pq1, pq2;
ll sum1 = 0, sum2 = 0;

void add_edge(ll u, ll v, ll idx, ll type) {
    adj[u].pb({v, idx, type});
    adj[v].pb({u, idx, type});
}

ll dfs(ll v, ll p) {
    if (v != 0 && adj[v].size() == 1) {
        return 1;
    }
    ll ret = 0;
    for (auto ed : adj[v]) {
        ll u = ed[0], idx = ed[1], ut = ed[2];
        if (p != u) {
            ll cnt = dfs(u, v);
            ret += cnt;
            lv[idx] = cnt;
            ll uw = w[idx];
            if (ut == 1) {
                pq1.push(make_pair(uw * cnt - uw / 2 * cnt, idx));
                sum1 += uw * cnt;
            } else {
                pq2.push(make_pair(uw * cnt - uw / 2 * cnt, idx));
                sum2 += uw * cnt;
            }
        }
    }
    return ret;
}

ll solve() {
    adj.clear();
    w.clear();
    lv.clear();
    while (!pq1.empty()) {
        pq1.pop();
    }
    while (!pq2.empty()) {
        pq2.pop();
    }
    sum1 = sum2 = 0;

    ll n, s;
    cin >> n >> s;
    adj.resize(n);
    w.resize(n - 1), lv.resize(n - 1);

    for (ll i = 0; i < n - 1; i++) {
        ll u, v, type;
        cin >> u >> v >> w[i] >> type;
        --u, --v;
        add_edge(u, v, i, type);
    }

    dfs(0, -1);
    vi vec1, vec2;
    vec1.pb(sum1), vec2.pb(sum2);

    while (sum1 > 0) {
        pii topper = pq1.top();
        pq1.pop();
        ll &ww = w[topper.ss];
        ll &cnt = lv[topper.ss];
        sum1 -= ww * cnt;
        ww /= 2;
        sum1 += ww * cnt;
        pq1.push({ww * cnt - ww / 2 * cnt, topper.ss});
        vec1.pb(sum1);
    }
    while (sum2 > 0) {
        pii topper = pq2.top();
        pq2.pop();
        ll &ww = w[topper.ss];
        ll &cnt = lv[topper.ss];
        sum2 -= ww * cnt;
        ww /= 2;
        sum2 += ww * cnt;
        pq2.push({ww * cnt - ww / 2 * cnt, topper.ss});
        vec2.pb(sum2);
    }

    ll ans = LINF;
    for (ll i = 0; i < (ll)vec1.size(); i++) {
        if (vec1[i] > s) {
            continue;
        }
        ll want = s - vec1[i];
        ll op = i;
        auto it = lower_bound(all(vec2), want, greater<ll>());
        if (*it > want) {
            it++;
        }
        op += 2 * (it - vec2.begin());
        ans = min(ans, op);
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
