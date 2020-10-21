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
vvi sp, par;

void add_edge(ll u, ll v, ll w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

// cp algo copy pasta
void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

ll solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    adj.resize(n);
    sp.resize(n, vi(n));
    par.resize(n, vi(n));

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        add_edge(u, v, w);
    }

    vpii routes(k);
    for (ll i = 0; i < k; i++) {
        cin >> routes[i].ff >> routes[i].ss;
        --routes[i].ff, --routes[i].ss;
    }

    for (ll i = 0; i < n; i++) {
        dijkstra(i, sp[i], par[i]);
    }

    map<pii,ll> mp;
    ll sum = 0;
    for (auto &p : routes) {
        vi path;
        ll v = p.ss;
        sum += sp[p.ff][v];
        while (v != -1) {
            path.pb(v);
            v = par[p.ff][v];
        }
        for (ll i = 0; i < (ll)path.size() - 1; i++) {
            mp[make_pair(min(path[i], path[i + 1]), max(path[i], path[i + 1]))]++;
        }
    }

    ll ans = LINF;
    for (ll i = 0; i < n; i++) {
        for (pii ed : adj[i]) {
            ll j = ed.ff, w = ed.ss;
            ll temp_ans = 0;
            for (auto &p : routes) {
                temp_ans += min({sp[p.ff][p.ss], sp[p.ff][i] + sp[j][p.ss], sp[p.ff][j] + sp[i][p.ss]});
            }
            ans = min(ans, temp_ans);
        }
    }

    cout << ans << endl;

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
