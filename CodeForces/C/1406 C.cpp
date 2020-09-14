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

vvi adj;
vi mx;

void add_edge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

ll dfs(ll v, ll p) {
    ll sts = 0;
    ll m = 0;
    for (ll u : adj[v]) {
        if (u != p) {
            ll temp = dfs(u, v) + 1;
            m = max(m, temp);
            sts += temp;
        }
    }
    mx[v] = max(m, (ll)adj.size() - 1 - sts);
    return sts;
}

ll dfs2(ll v, ll p) {
    ll sts = 0;
    for (ll u : adj[v]) {
        if (u != p) {
            sts += dfs2(u, v) + 1;
        }
    }
    return sts;
}

ll solve() {
    adj.clear();
    mx.clear();

    ll n;
    cin >> n;

    adj.resize(n);
    mx.resize(n);

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }

    dfs(0, -1);

    ll val = *min_element(all(mx));
    ll cnt = count(all(mx), val);

    if (cnt == 1) {
        cout << 1 << " " << adj[0].front() + 1<< endl;
        cout << 1 << " " << adj[0].front() + 1 << endl;
        return 0;
    }

    ll x = -1, y = -1;
    for (ll i = 0; i < n; i++) {
        if (mx[i] == val && x == -1) {
            x = i;
        } else if (mx[i] == val && x != -1) {
            y = i;
        }
    }


    vi store(adj[x].size());
    for (ll i = 0; i < (ll) adj[x].size(); i++) {
        store[i] = dfs2(adj[x][i], x) + 1;
    }

//    if (store.size() == 2) {
//        ll yy = find(all(adj[x]), y) - adj[x].begin();
//        store[yy] = -1;
//        ll p = max_element(all(store)) - store.begin();
//        store[p] = -1;
//        p = adj[x][p];
//        cout << x + 1 << " " << p + 1 << endl;
//        cout << y + 1 << " " << p + 1 << endl;
//    } else {
//        ll yy = find(all(adj[x]), y) - adj[x].begin();
//        store[yy] = -1;
//        ll p = max_element(all(store)) - store.begin();
//        store[p] = -1;
//        ll q = max_element(all(store)) - store.begin();
//        store[q] = -1;
//        p = adj[x][p];
//        q = adj[x][q];
//        cout << x + 1 << " " << p + 1 << endl;
//        cout << q + 1 << " " << p + 1 << endl;
//    }

    ll rmv = max_element(all(store)) - store.begin();
    if (adj[x][rmv] == y) {
        store[rmv] = -1;
        rmv = max_element(all(store)) - store.begin();
    }
    rmv = adj[x][rmv];

    cout << rmv + 1 << " " << x + 1 << endl;
    cout << rmv + 1 << " " << y + 1<< endl;

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
