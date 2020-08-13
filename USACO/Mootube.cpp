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

struct DSU {
    vi parent, size;

    DSU(ll n) {
        parent.resize(n);
        size.resize(n);
        for (ll i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    ll find_parent(ll v) {
        if (parent[v] == v) {
            return v;
        } else {
            return parent[v] = find_parent(parent[v]);
        }
    }

    void union_sets(ll u, ll v) {
        u = find_parent(u), v = find_parent(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            size[v] += size[u];
            parent[u] = v;
        }
    }
};

struct edge {
    ll u, v, w;
};
bool cmp(edge a, edge b) {
    return a.w < b.w;
}

ll solve() {
    ll n, q;
    cin >> n >> q;

    vector<edge> edges;
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.pb({u, v, w});
    }
    sort(all(edges), cmp);

    vector<pair<ll,pair<ll,ll>>> queries(q);
    for (ll i = 0; i < q; i++) {
        cin >> queries[i].ff >> queries[i].ss.ff;
        queries[i].ss.ff--;
        queries[i].ss.ss = i;
    }
    sort(all(queries));
    reverse(all(queries));

    vpii ans;
    DSU dsu(n);
    for (ll i = 0; i < q; i++) {
        ll k = queries[i].ff;
        ll v = queries[i].ss.ff;
        ll idx = queries[i].ss.ss;
        while (!edges.empty() && edges.back().w >= k) {
            dsu.union_sets(edges.back().u, edges.back().v);
            edges.pop_back();
        }
        ans.pb({idx, dsu.size[dsu.find_parent(v)] - 1});
    }

    sort(all(ans));
    for (pii &x : ans) {
        cout << x.ss << endl;
    }

    return 0;
}

signed main() {
    fastio;
    fileio("mootube");

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
