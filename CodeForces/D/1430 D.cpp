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
    ll n;
    cin >> n;
    string str;
    cin >> str;

    vi vec;
    min_pq(pii) one, many;

    for (ll i = 0; i < n; ) {
        ll j = i + 1;
        while (str[i] == str[j]) {
            j++;
        }
        vec.pb(j - i);
        if (j - i == 1) {
            one.push(make_pair(i, j - i));
        } else {
            many.push(make_pair(i, j - i));
        }
        i = j;
    }

    ll ans = 0;
    while (one.size() && many.size()) {
        pii oneone = one.top();
        pii manymany = many.top();

        if (manymany.ff < oneone.ff) {
            ans += 1;
            many.pop();
        } else {
            one.pop();
            many.pop();
            manymany.ss -= 1;
            ans += 1;
            if (manymany.ss == 1) {
                one.push(make_pair(manymany.ff, manymany.ss));
            } else {
                many.push(make_pair(manymany.ff, manymany.ss));
            }
        }
    }

    if (one.size()) {
        ans += (one.size() + 1) / 2;
    }
    if (many.size()) {
        ans += many.size();
    }

    cout << ans << endl;

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
