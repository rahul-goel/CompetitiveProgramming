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


ll solve(){
    vb used(1<<14);
    vi q1, q2;
    for(ll i=0; i<(1<<14); i++){
        if(!used[i]){
            ll cnt= 0;
            for(ll j=0; j<7; j++)
                if(i&(1<<j))
                    cnt++;
            if(cnt == 7)
                used[i] = true, q1.pb(i);
        }
        if(q1.size() == 100)
            break;
    }
    for(ll i=0; i<(1<<14); i++){
        if(!used[i]){
            ll cnt= 0;
            for(ll j=7; j<14; j++)
                if(i&(1<<j))
                    cnt++;
            if(cnt == 7)
                used[i] = true, q2.pb(i);
        }
        if(q2.size() == 100)
            break;
    }

    ll a, b;

    cout << "? ";
    for(ll x : q1)
        cout << x << " ";
    cout << endl;
    cin >> a;
    cout << "? ";
    for(ll x : q2)
        cout << x << " ";
    cout << endl;
    cin >> b;

    ll ans = 0;
    for(ll i=0; i<7; i++)
        if(!(a&(1<<i)))
            ans += (1<<i);
    for(ll i=7; i<14; i++)
        if(!(b&(1<<i)))
            ans += (1<<i);
    cout << "! " << ans << endl;
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
