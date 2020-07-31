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

ll solve() {
    ll n;
    cin >> n;
    vector < string > vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (char &x : vec[0]) {
        if (x == '?') {
            x = '0';
        }
    }
    if (vec[0].front() == '0') {
        vec[0].front() = '1';
    }

    for (ll i = 1; i < n; i++) {
        if (vec[i].size() < vec[i - 1].size()) {
            cout << "NO" << endl;
            return 0;
        } else if (vec[i].size() > vec[i - 1].size()) {
            for (char &x : vec[i]) {
                if (x == '?') {
                    x = '0';
                }
            }
            if (vec[i].front() == '0') {
                vec[i].front() = '1';
            }
        } else {
            vb can(vec[i].size() + 1);
            for (ll j = vec[i].size() - 1; j >= 0; j--) {
                bool isq = false;
                if (vec[i][j] == '?') {
                    vec[i][j] = '9';
                    isq = true;
                }

                if (vec[i][j] > vec[i - 1][j]) {
                    can[j] = true;
                } else if (vec[i][j] < vec[i - 1][j]) {
                    can[j] = false;
                } else {
                    can[j] = can[j + 1];
                }

                if (isq) {
                    vec[i][j] = '?';
                }
            }

            if (!can.front()) {
                cout << "NO" << endl;
                return 0;
            }

            bool greater = false;
            for (ll j = 0; j < (ll)vec[i].size(); j++) {
                if (greater) {
                    if (vec[i][j] == '?') {
                        vec[i][j] = '0';
                    }
                    continue;
                }

                if (vec[i][j] == '?') {
                    if (can[j + 1]) {
                        vec[i][j] = vec[i - 1][j];
                    } else {
                        vec[i][j] = vec[i - 1][j] + 1;
                    }
                }
                if (vec[i][j] > vec[i - 1][j]) {
                    greater = true;
                }
            }
        }
    }

    cout << "YES" << endl;
    for (string &str : vec) {
        cout << str << endl;
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
