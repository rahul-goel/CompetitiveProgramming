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

vvi mat;
vvb vis;
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

bool valid(ll x, ll y) {
    ll n = mat.size();
    ll m = mat[0].size();
    return x >= 0 && x < n && y >= 0 && y < m;
}

set < pii > boundary;

void dfs(ll x, ll y) {
    vis[x][y] = true;
    mat[x][y] = 0;
    boundary.insert({x, y});
    for (ll i = 0; i < 4; i++) {
        ll xx = x + dx[i];
        ll yy = y + dy[i];
        if (valid(xx, yy) && !vis[xx][yy] && mat[xx][yy]) {
            dfs(xx, yy);
        }
    }
}

vpii track;

ll dfs2(ll x, ll y) {
    track.pb({x, y});
    vis[x][y] = true;
    ll ret = 1;
    for (ll i = 0; i < 4; i++) {
        ll xx = x + dx[i];
        ll yy = y + dy[i];
        if (valid(xx, yy) && !vis[xx][yy] && mat[xx][yy]) {
            ret += dfs2(xx, yy);
        }
    }
    return ret;
}

ll solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    mat = vvi(n, vi(m, 0));
    vis = vvb(n, vb(m, false));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char x;
            cin >> x;
            mat[i][j] = (x == '.');
        }
    }

    for (ll i = 0; i < n; i++) {
        if (!vis[i][0] && mat[i][0]) {
            dfs(i, 0);
        }
        if (!vis[i][m - 1] && mat[i][m - 1]) {
            dfs(i, m - 1);
        }
    }

    for (ll j = 0; j < m; j++) {
        if (!vis[0][j] && mat[0][j]) {
            dfs(0, j);
        }
        if (!vis[n - 1][j] && mat[n - 1][j]) {
            dfs(n - 1, j);
        }
    }

    vi vec;
    for (ll i = 1; i < n - 1; i++) {
        for (ll j = 1; j < m - 1; j++) {
            if (!vis[i][j] && mat[i][j]) {
                track.clear();
                vec.pb(dfs2(i, j));
            }
        }
    }

    sort(all(vec), greater<ll>());
    ll ans = 0;
    multiset < ll > karna;
    while ((ll)vec.size() > k) {
        ans += vec.back();
        karna.insert(vec.back());
        vec.pop_back();
    }

    for (auto &x : vis) {
        x.assign(m, false);
    }

    for (ll i = 1; i < n - 1; i++) {
        for (ll j = 1; j < m - 1; j++) {
            if (!vis[i][j] && mat[i][j]) {
                track.clear();
                ll val = dfs2(i, j);
                if (present(karna, val)) {
                    for (auto x : track) {
                        mat[x.ff][x.ss] = 0;
                    }
                    karna.erase(karna.find(val));
                }
            }
        }
    }

    cout << ans << endl;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (present(boundary, make_pair(i, j))) {
                cout << '.';
                continue;
            }
            cout << (mat[i][j] ? '.' : '*');
        }
        cout << endl;
    }

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
