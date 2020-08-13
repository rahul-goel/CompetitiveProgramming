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

ll solve() {
    ll n, m, r;
    cin >> n >> m >> r;

    vi cows(n);
    for (ll &x : cows) {
        cin >> x;
    }
    vpii shop(m);
    for (pii &x : shop) {
        cin >> x.ss >> x.ff;
    }
    vi rent(r);
    for (ll &x : rent) {
        cin >> x;
    }

    cows.pb(0);
    sort(all(cows));
    cows.pb(0);
    shop.pb({0, 0});
    sort(all(shop));
    shop.pb({0, 0});
    sort(all(rent), greater < ll > ());

    vi rentsum(max(n, r) + 5);
    for (ll i = 1; i <= r; i++) {
        rentsum[i] += rentsum[i - 1] + rent[i - 1];
    }
    for (ll i = r + 1; i <= n; i++) {
        rentsum[i] = rentsum[i - 1];
    }

    ll ans = 0, shopmoney = 0;
    for (ll i = n; i >= 0; i--) {
        ll milk = cows[i + 1];
        while(!shop.empty() && milk > 0) {
            ll take = min(milk, shop.back().ss);
            shopmoney += take * shop.back().ff;
            shop.back().ss -= take;
            milk -= take;
            if (shop.back().ss == 0) {
                shop.pop_back();
            }
        }
        ans = max(ans, rentsum[i] + shopmoney);
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    fastio;
    fileio("rental");

    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
