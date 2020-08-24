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

vi a, b;

ll f(ll val, ll k) {
    ll cntless = 0, cnt = 0;
    for (ll &x : a) {
        cnt += upper_bound(all(b), val - x) - lower_bound(all(b), val - x);
        cntless += upper_bound(all(b), val - x - 1) - b.begin();
    }

    ll vl = cntless + 1, vr = cntless + cnt;
    if (vl <= k && k <= vr) {
        return 0;
    } else if (k < vl) {
        return -1;
    } else {
        return 1;
    }
}

ll solve() {
    ll n, k;
    cin >> n >> k;
    a = b = vi(n);
    for (ll &x : a) {
        cin >> x;
    }
    for (ll &x : b) {
        cin >> x;
    }
    sort(all(a)), sort(all(b));

    ll start = -LINF, end = LINF, mid;
    while (start <= end) {
        mid = (start + end) >> 1;
        ll res = f(mid, k);
        if (res == -1) {
            end = mid - 1;
        } else if (res == 0) {
            break;
        } else {
            start = mid + 1;
        }
    }

    cout << mid << endl;

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
