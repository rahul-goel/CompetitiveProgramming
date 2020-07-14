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


ll solve(){
    ll n;
    cin >> n;
    vvi front(n + 5), back(n + 5);
    ll ans = 0;

    for(ll i = 0; i < n; i++){
        ll k, l, r;
        cin >> k >> l >> r;
        if(l >= r)
            front[k].pb(l - r), ans += r;
        else
            back[k + 1].pb(r - l), ans += l;
    }

    min_pq(ll) pqf, pqb;
    ll ftake = 0, btake = 0;

    for(ll i = 1; i <= n; i++){
        ftake++;
        for(ll j = 0; j < (ll)front[i].size(); j++){
            if(ftake > 0){
                pqf.push({front[i][j]});
                ans += front[i][j];
                ftake--;
            }
            else{
                if(pqf.top() < front[i][j]){
                    ans -= pqf.top();
                    pqf.pop();
                    ans += front[i][j];
                    pqf.push(front[i][j]);
                }
            }
        }
    }

    for(ll i = n + 1; i >= 2; i--){
        btake++;
        for(ll j = 0; j < (ll)back[i].size(); j++){
            if(btake > 0){
                pqb.push(back[i][j]);
                ans += back[i][j];
                btake--;
            }
            else{
                if(pqb.top() < back[i][j]){
                    ans -= pqb.top();
                    pqb.pop();
                    ans += back[i][j];
                    pqb.push(back[i][j]);
                }
            }
        }
    }

    cout << ans << endl;

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

