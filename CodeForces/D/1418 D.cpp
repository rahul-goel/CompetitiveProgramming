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

ll solve() {
    ll n, q;
    cin >> n >> q;

    vi vec(n);
    set<ll> s;
    for (ll &x : vec) {
        cin >> x;
        s.insert(x);
    }

    sort(all(vec));
    ll tot = 0;
    multiset<ll> diff;

    for (ll i = 1; i < n; i++) {
        tot += vec[i] - vec[i - 1];
        diff.insert(vec[i] - vec[i - 1]);
    }

    if (s.size() <= 2) {
        cout << 0 << endl;
    } else {
        cout << tot - *--diff.end() << endl;
    }


    while (q--) {
        ll ch, x;
        cin >> ch >> x;
        if (ch == 1) {
            if (s.empty()) {
                s.insert(x);
            } else if (*s.begin() > x) {
                tot += *s.begin() - x;
                diff.insert(*s.begin() - x);
                s.insert(x);
            } else if (*s.rbegin() < x) {
                tot += x - *s.rbegin();
                diff.insert(x - *s.rbegin());
                s.insert(x);
            } else {
                ll a = *--s.lower_bound(x);
                ll b = *s.lower_bound(x);
                diff.erase(diff.lower_bound(b - a));
                diff.insert(x - a);
                diff.insert(b - x);
                s.insert(x);
            }
        } else {
            if (s.size() == 1) {
                s.clear();
            } else if (*s.begin() == x) {
                ll a = *++s.begin();
                s.erase(s.begin());
                diff.erase(diff.lower_bound(a - x));
                tot -= a - x;
            } else if (*s.rbegin() == x) {
                ll a = *--(--s.end());
                s.erase(--s.end());
                diff.erase(diff.lower_bound(x - a));
                tot -= x - a;
            } else {
                ll a = *--s.lower_bound(x);
                ll b = *s.upper_bound(x);
                s.erase(x);
                diff.erase(diff.lower_bound(x - a));
                diff.erase(diff.lower_bound(b - x));
                diff.insert(b - a);
            }
        }

        if (s.size() <= 2) {
            cout << 0 << endl;
        } else {
            cout << tot - *--diff.end() << endl;
        }
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
