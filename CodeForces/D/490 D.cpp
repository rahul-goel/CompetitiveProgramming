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

set < ll > done;

void f(ll n, set < pii > &s, ll cnt) {
    if (present(done, n)) {
        return;
    } else {
        done.insert(n);
    }

    if (n % 3 != 0 && n % 2 != 0) {
        return;
    }

    if (n % 2 == 0) {
        s.insert({n / 2, cnt + 1});
        f(n / 2, s, cnt + 1);
    }
    if (n % 3 == 0) {
        s.insert({2 * n / 3, cnt + 1});
        f(2 * n / 3, s, cnt + 1);
    }
    return;
}

ll solve() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    set < pii > aa, bb, xx, yy;
    aa.insert({a, 0}), bb.insert({b, 0}), xx.insert({x, 0}), yy.insert({y, 0});
    done.clear();
    f(a, aa, 0);
    done.clear();
    f(b, bb, 0);
    done.clear();
    f(x, xx, 0);
    done.clear();
    f(y, yy, 0);

    ll ans = LINF;
    pii ansa, ansb;

    set < pair < pii, pii > > foo, bar;

    for (auto aaa : aa) {
        for (auto bbb : bb) {
            foo.insert({{aaa.ff * bbb.ff, aaa.ss + bbb.ss}, {aaa.ff, bbb.ff}});
        }
    }
    for (auto xxx : xx) {
        for (auto yyy : yy) {
            bar.insert({{xxx.ff * yyy.ff, xxx.ss + yyy.ss}, {xxx.ff, yyy.ff}});
        }
    }

    for (auto aaa : foo) {
        auto other = *bar.lower_bound(make_pair(make_pair(aaa.ff.ff, -LINF), make_pair(-LINF, -LINF)));
        if (other.ff.ff == aaa.ff.ff) {
            if (ans > aaa.ff.ss + other.ff.ss) {
                ans = aaa.ff.ss + other.ff.ss;
                ansa = aaa.ss;
                ansb = other.ss;
            }
        }
    }

    if (ans == LINF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
        cout << ansa.ff << " " << ansa.ss << endl;
        cout << ansb.ff << " " << ansb.ss << endl;
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
