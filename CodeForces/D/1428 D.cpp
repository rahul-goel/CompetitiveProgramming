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
    vi vec(n);
    for (ll &x : vec) {
        cin >> x;
    }

    vi one, two, three;
    vi twomatch(n, -1), threematch(n, - 1), col(n, -1);
    ll currow = 0;

    for (ll i = n - 1; i >= 0; i--) {
        if (vec[i] == 0) {
            continue;
        }
        if (vec[i] == 1) {
            one.push_back(i);
        } else if (vec[i] == 2) {
            if (one.empty()) {
                cout << -1 << endl;
                return 0;
            } else {
                twomatch[i] = one.back();
                one.pop_back();
            }
            two.push_back(i);
        } else {
            if (!three.empty()) {
                threematch[i] = three.back();
                three.pop_back();
            } else if (!two.empty()) {
                threematch[i] = two.back();
                two.pop_back();
            } else if (!one.empty()) {
                threematch[i] = one.back();
                one.pop_back();
            } else {
                cout << -1 << endl;
                return 0;
            }
            three.push_back(i);
        }
    }

    // make the chains
    vector<pair<ll,ll>> ans;
    for (ll i = 0; i < n; i++) {
        if (vec[i] == 0 || col[i] == 1) {
            continue;
        }
        ll curcol = i;
        while (curcol != -1) {
            col[curcol] = 1;
            if (vec[curcol] == 1) {
                ans.emplace_back(currow, curcol);
                curcol = -1;
                currow++;
            } else if (vec[curcol] == 2) {
                ans.emplace_back(currow, curcol);
                curcol = twomatch[curcol];
            } else {
                ans.emplace_back(currow, curcol);
                curcol = threematch[curcol];
                ans.emplace_back(currow, curcol);
                currow++;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << 1 + x.ff << " " << 1 + x.ss << endl;
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
