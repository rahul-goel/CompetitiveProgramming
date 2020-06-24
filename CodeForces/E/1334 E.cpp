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
ll mod = 998244353;
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

ll power(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y&1)
            ret = mod_prod(ret, x);
        y>>=1;
        x = mod_prod(x, x);
    }
    return ret;
}

ll inv(ll x){
    return power(x, mod-2);
}

ll solve(){
    ll d;
    ll q;
    cin >> d >> q;

    vi primes;
    for(ll i=2; i*i<=d; i++){
        if(d%i == 0){
            primes.pb(i);
            while(d%i == 0)
                d/=i;
        }
    }
    if(d > 1)
        primes.pb(d);

    vi fac(100), ifac(100);
    fac[0] = 1;
    for(ll i=1; i<(ll)fac.size(); i++){
        fac[i] = mod_prod(fac[i-1], i);
        ifac[i] = inv(fac[i]);
    }

    while(q--){
        ll x, y;
        cin >> x >> y;
        ll g = __gcd(x, y);
        x/=g, y/=g;
        vi xx, yy;
        for(ll p : primes){
            ll cx = 0, cy = 0;
            if(x%p == 0){
                while(x%p == 0)
                    cx++, x/=p;
            }
            if(y%p ==0){
                while(y%p == 0)
                    cy++, y/=p;
            }
            if(cx)
                xx.pb(cx);
            if(cy)
                yy.pb(cy);
        }

        ll sumx = 0, sumy = 0;
        for(ll xxx : xx)
            sumx += xxx;
        for(ll yyy : yy)
            sumy += yyy;
        ll ans = mod_prod(fac[sumx], fac[sumy]);
        for(ll xxx : xx)
            ans = mod_prod(ans, ifac[xxx]);
        for(ll yyy : yy)
            ans = mod_prod(ans, ifac[yyy]);

        cout << ans << endl;
    }


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

