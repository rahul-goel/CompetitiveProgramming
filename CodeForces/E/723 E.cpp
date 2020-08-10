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

void dfs(ll v, vvi &adj, vb &vis, vpii &ans) {
    vis[v] = true;
    for (ll u = 0; u < (ll)adj.size(); u++) {
        while (adj[v][u]) {
            --adj[u][v];
            --adj[v][u];
            dfs(u, adj, vis, ans);
            ans.pb({v, u});
        }
    }
}

ll solve() {
    ll n, m;
    cin >> n >> m;

    vvi adj(n, vi(n));
    vi deg(n);
    set<pii> psuedo;

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        adj[u][v] = 1;
        adj[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }

    for (ll i = 0; i < n; i++) {
        if (deg[i] & 1) {
            for (ll j = i + 1; j < n; j++) {
                if (deg[j] & 1) {
                    adj[i][j] += 1;
                    adj[j][i] += 1;
                    deg[i]++;
                    deg[j]++;
                    psuedo.insert(make_pair(i, j));
                    break;
                }
            }
        }
    }

    vb vis(n);
    vpii ans;
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, ans);
        }
    }

    deg.assign(n, 0);
    vpii finalans;
    for (auto x : ans) {
        ll v = x.ff;
        ll u = x.ss;
        if (present(psuedo, make_pair(min(u, v), max(u, v)))) {
            psuedo.erase(make_pair(min(u, v), max(u, v)));
        } else {
            --deg[v];
            ++deg[u];
            finalans.pb(make_pair(v, u));
        }
    }

    cout << count(all(deg), 0) << endl;
    for (auto &x : finalans) {
        cout << ++x.ff << " " << ++x.ss << endl;
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
