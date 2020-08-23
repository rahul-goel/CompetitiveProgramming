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
vi dist, parent, path;

int hsh(int r, int c, int m){
    return r*m + c;
}

pair < int, int > reverse_hsh(int x, int m){
    return {(x/m), (x%m)};
}

void add_edge(ll u, ll v, ll len) {
    adj[u].pb({len, v});
    adj[v].pb({len, u});
}

void dijkstra(ll source)
{
    dist[source] = 0;
    priority_queue < pii, vpii, greater < pii > > q;
    q.push({0, source});

    while(!q.empty())
    {
        ll v = q.top().second;
        ll dist_v = q.top().first;
        q.pop();

        if(dist_v != dist[v])
            continue;

        for(auto edge : adj[v])
        {
            ll to = edge.second;
            ll len = edge.first;

            if(dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len, parent[to] = v;
                q.push({dist[to], to});
            }
        }
    }
}

void restore_path(ll source, ll t) {
    for(ll u=t; u!=source; u=parent[u])
        path.pb(u);
    path.pb(source);
    reverse(path.begin(), path.end());
}

ll solve() {
    ll h, w;
    cin >> h >> w;
    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    --sx, --sy, --ex, --ey;

    adj.resize(h * w);
    dist.resize(h * w, LINF);
    parent.resize(h * w, -1);
    path.resize(h * w);

    vvi mat(h, vi(w));

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            char temp;
            cin >> temp;
            mat[i][j] = (temp == '.');
        }
    }

    vi dx = {0, 1, 0, -1};
    vi dy = {1, 0, -1, 0};

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            for (ll k = 0; k < 4; k++) {
                ll x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    if (mat[i][j] && mat[x][y]) {
                        add_edge(hsh(i, j, w), hsh(x, y, w), 0);
                    }
                }
            }
            for (ll k = -2; k <= 2; k++) {
                for (ll l = -1; l <= 2; l++) {
                    ll x = i + k, y = j + l;
                    if (x >= 0 && x < h && y >= 0 && y < w) {
                        if (mat[i][j] && mat[x][y]) {
                            add_edge(hsh(i, j, w), hsh(x, y, w), 1);
                        }
                    }
                }
            }
        }
    }

    dijkstra(hsh(sx, sy, w));
    ll ans = dist[hsh(ex, ey, w)];

    cout << (ans == LINF ? -1 : ans) << endl;

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
