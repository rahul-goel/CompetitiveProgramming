/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
/*******************************************************************************/
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/*
.-.. . -. -.- .- / .. ... / .-.. --- ...- . -.-.--
 */
/* For PBDS */
/*Two new methods X.order_of_key() and X.find_by_order()*/
/*
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

/*******************************************************************************/
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
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

/*
    Code begins after this.
*/

ll n, m;
ll x, k, y;
ll ans = 0;
vi a, b;

bool valid(ll l, ll r){
    if(l > r)
        return true;

    ll p = *max_element(a.begin() + l, a.begin() + r + 1);
    ll len = r - l + 1;
    bool flag = false;
    if(l - 1 >= 0 && a[l - 1] > p)
        flag = true;
    if(r + 1 < n && a[r + 1] > p)
        flag = true;
    if(len < k && flag == false)
        return false;

    ll rmv = len % k;
    ans += y * rmv;
    len -= rmv;

    if(x <= y * k)
        ans += (len / k) * x;
    else if(flag)
        ans += len * y;
    else
        ans += (len - k) * y + x;

    return true;
}

ll solve(){
    cin >> n >> m;
    cin >> x >> k >> y;
    a.resize(n), b.resize(m);

    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;

    ll pa = 0, pb = 0, first = -1;
    while(pb < m){
        while(pa < n && a[pa] != b[pb])
            pa++;
        if(pa == n){
            cout << -1 << endl;
            return 0;
        }

        if(valid(first + 1, pa - 1) == false){
            cout << -1 << endl;
            return 0;
        }

        first = pa;
        pb++;
    }

    if(valid(first + 1, n - 1) == false){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

