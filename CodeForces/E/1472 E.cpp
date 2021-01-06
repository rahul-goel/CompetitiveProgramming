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

struct Data {
    ll a;
    ll b;
    ll id;
};

bool operator<(const Data &first, const Data &second) {
    return tie(first.a, first.b, first.id) < tie(second.a, second.b, second.id);
}

// bool comparator(const Data &first, const Data &second) {
//     if (first.a < second.a) {
//         return true;
//     } else if (first.a > second.a) {
//         return false;
//     } else {
//         if (first.b < second.b) {
//             return true;
//         } else if (first.b > second.b) {
//             return false;
//         } else {
//             return false;
//         }
//     }
// }

vector<ll> solve_one_way(vector<Data> vec, vector<Data> og) {
    ll n = vec.size();
    vector<ll> ans(n, -1);

    sort(all(vec));
    vector<pair<ll,ll>> prefix(n);
    prefix.front().ff = vec.front().b;
    prefix.front().ss = vec.front().id;
    for (ll i = 1; i < n; i++) {
        if (vec[i].b < prefix[i - 1].ff) {
            prefix[i].ff = vec[i].b;
            prefix[i].ss = vec[i].id;
        } else {
            prefix[i] = prefix[i - 1];
        }
    }

    for (ll i = 0; i < n; i++) {
        ll value = og[i].a;
        Data lower_than = {value, -LINF, -LINF};
        ll ind = lower_bound(all(vec), lower_than) - vec.begin();

        if (ind > 0) {
            if (prefix[ind - 1].ff < og[i].b)
            ans[i] = prefix[ind - 1].ss;
        }
    }

    return ans;
}

ll solve() {
    ll n;
    cin >> n;

    vector<Data> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i].a >> vec[i].b;
        vec[i].id = i;
    }

    auto og = vec;
    auto ans1 = solve_one_way(vec, og);

    for (ll i = 0; i < n; i++) {
        swap(vec[i].a, vec[i].b);
    }
    auto ans2 = solve_one_way(vec, og);

    for (ll i = 0; i < n; i++) {
        if (ans1[i] == -1 && ans2[i] == -1) {
            cout << -1 << " ";
        } else if (ans1[i] != -1) {
            cout << ans1[i] + 1 << " ";
        } else if (ans2[i] != -1) {
            cout << ans2[i] + 1 << " ";
        }
    }

    cout << endl;

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
