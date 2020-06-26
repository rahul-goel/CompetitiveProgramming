/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
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
ll mod = 1000000007;
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

ll sd(ll n){
    ll ret = 0;
    while(n)
        ret += n%10, n/=10;
    return ret;
}

ll power(ll x, ll y){
    ll ret = 1;
    while(y--)
        ret *= x;
    return ret;
}

ll mnd(ll sum){
    ll ret = 0;
    ll i = 0;
    while(sum){
        if(sum >= 9)
            ret += 9*(power(10, i)), sum -= 9;
        else
            ret += sum*(power(10, i)), sum = 0;
        i++;
    }
    return ret;
}

ll solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = LINF;

    for(ll i=0; i<=99-k; i++){
        ll d = 0;
        for(ll j=i; j<=i+k; j++)
            d += sd(j);
        if((n-d) >= 0 && (n-d)%(k+1) == 0){
            ll s = (n-d)/(k+1);
            ll temp_ans = mnd(s)*100 + i;
            ans = min(ans, temp_ans);
        }
    }

    for(ll i=100; i<=LINF; i*=10){
        for(ll j=i-k-1; j<i; j++){
            ll sum = 0;
            for(ll r=j; r<=j+k; r++)
                sum += sd(r);
            if(sum == n)
                ans = min(ans, j);
        }
    }

    for(ll j=0; j<100; j++){
        ll sum = 0;
        for(ll r=j; r<=j+k; r++)
            sum += sd(r);
        if(sum == n)
            ans = min(ans, j);
    }

    if(ans != LINF)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

