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


ll solve(){
    ll n, k;
    cin >> n >> k;

    min_pq(ll) p11, p01, p10, p00;

    for(ll i=0; i<n; i++){
        ll t, a, b;
        cin >> t >> a >> b;
        if(a == 1 && b == 1)
            p11.push(t);
        else if(a == 0 && b == 1)
            p01.push(t);
        else if(a == 1 && b == 0)
            p10.push(t);
        else
            p00.push(t);
    }

    ll ac = 0, bc = 0, tm = 0;
    while(ac < k || bc < k){
        if(!p11.empty() && !p01.empty() && !p10.empty()){
            if(p11.top() < p01.top() + p10.top()){
                tm += p11.top();
                p11.pop();
                ac++, bc++;
            }
            else{
                tm += p01.top() + p10.top();
                p10.pop(), p01.pop();
                ac++, bc++;
            }
        }
        else if(!p11.empty()){
            tm += p11.top();
            p11.pop();
            ac++, bc++;
        }
        else if(!p01.empty() && !p10.empty()){
            tm += p01.top() + p10.top();
            p01.pop(), p10.pop();
            ac++, bc++;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    cout << tm << endl;

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

