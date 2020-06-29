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

vi vec;

void op(ll j){
    swap(vec[j], vec[j+2]);
    swap(vec[j+1], vec[j+2]);
}

ll solve(){
    ll n;
    cin >> n;
    vec.clear();
    vec.resize(n);
    for(ll &x : vec)
        cin >> x;


    vi ans;

    for(ll i=0; i<n-2; i++){
        ll j = min_element(vec.begin()+i, vec.end()) - vec.begin();
        if(j == i)
            continue;

        while(j>i+1)
            op(j-2), ans.pb(j-2), j-=2;
        if(j == i+1){
            op(i), ans.pb(i);
            op(i), ans.pb(i);
        }
    }

    if(!is_sorted(vec.end()-3, vec.end())){
        vi temp = vec;
        sort(all(temp));
        uniq(temp);
        if(temp.size() == vec.size()){
            cout << -1 << endl;
            return 0;
        }

        if(vec[n-1] == vec[n-3]){
            ans.pb(n-3);
        }
        else{
            ll j = vec.size()-3;
            while(vec[j] != vec[j+1])
                ans.pb(j), j--;
            ans.pb(j);
        }
    }

    if((ll)ans.size() > n*n){
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for(ll &x : ans)
        cout << x+1 << " ";
    cout << endl;


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

