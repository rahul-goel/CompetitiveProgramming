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

ll popcount(ll n){
    ll cnt = 0;
    while(n)
        cnt += (n & 1), n >>= 1;
    return cnt;
}

ll f(ll n){
    if(n == 0)
        return 0;
    return 1 + f(n % popcount(n));
}

ll power(ll x, ll y, ll m){
    ll ret = 1;
    while(y){
        if(y & 1)
            ret = (ret * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

ll solve(){
    ll n;
    cin >> n;
    string str;
    cin >> str;

    ll cnt1 = 0;
    for(char &x : str)
        cnt1 += (x == '1');


    ll val0 = 0, val1 = 0, val2 = 0;
    for(ll i = 0; i < n; i++){
        if(str[i] == '1'){
            if(cnt1 - 1 > 0)
                val0 = (val0 + power(2, n - i - 1, cnt1 - 1)) % (cnt1 - 1);
            val1 = (val1 + power(2, n - i - 1, cnt1 - 0)) % (cnt1 - 0);
            val2 = (val2 + power(2, n - i - 1, cnt1 + 1)) % (cnt1 + 1);
        }
    }

    vi ans;

    for(ll i = 0; i < n; i++){
        if(str[i] == '1'){
            str[i] = '0';
            if(cnt1 - 1 == 0){
                ans.pb(0);
                continue;
            }

            //cnt1 decreases by 1
            ll val = ((val0 - power(2, n - i - 1, cnt1 - 1)) % (cnt1 - 1) + cnt1 - 1) % (cnt1 - 1);
            ans.pb(1 + f(val));

            str[i] = '1';
        }
        else{
            str[i] = '1';
            if(cnt1 + 1 == 0){
                ans.pb(0);
                continue;
            }

            //cnt1 increases by 1
            ll val = (val2 + power(2, n - i - 1, cnt1 + 1) + cnt1 + 1) % (cnt1 + 1);
            ans.pb(1 + f(val));

            str[i] = '0';
        }
    }

    for(ll x : ans)
        cout << x << endl;

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

