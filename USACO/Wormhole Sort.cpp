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
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll find_parent(ll v) {
        if (v == parent[v]) {
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

struct node {
    ll a, b, w;
};

bool f(vi &vec, vector < node > &worm, ll low) {
    ll n = vec.size();
    DSU dsu(n);

    for (auto &x : worm) {
        if (x.w >= low) {
            dsu.union_sets(x.a, x.b);
        }
    }

    bool ok = true;
    for (ll i = 0; i < n; i++) {
        if (dsu.find_parent(i) != dsu.find_parent(vec[i])) {
            ok = false;
        }
    }

    return ok;
}

ll solve() {
    ll n, m;
    cin >> n >> m;
    vi vec(n);
    vector < node > worm(m);

    for (ll &x : vec) {
        cin >> x;
        --x;
    }
    for (auto &x : worm) {
        cin >> x.a >> x.b >> x.w;
        --x.a, --x.b;
    }

    vi check(n);
    for (ll i = 0; i < n; i++) {
        check[i] = i;
    }

    if (check == vec) {
        cout << -1 << endl;
        return 0;
    }

    ll start = 1, end = 1000000000, mid, ans = -1;
    while (start <= end) {
        mid = (start + end) >> 1;
        if (f(vec, worm, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;
    fileio("wormsort");

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
