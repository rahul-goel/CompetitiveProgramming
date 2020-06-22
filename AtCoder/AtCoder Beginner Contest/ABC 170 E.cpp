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
    ll n, q;
    cin >> n >> q;

    vi kg(n+1); // stores to which kg does that infant i belong
    vector < set < pii > > infrat(200005); // stores the rating of the infants that belong to the kg
    vi rating(n+1); // stores the rating of the ith infant;
    set < pii > rrr; // stores all the ratings of the kgs;

    for(ll i=1; i<=n; i++){
        ll a, b;
        cin >> a >> b;
        rating[i] = a;
        kg[i] = b;

        ll oldhighestrating;
        if(infrat[b].size())
            oldhighestrating = (*--infrat[b].end()).ff;

        infrat[b].insert({rating[i], i});

        if(infrat[b].size() == 1){
            pii highestrated = *--infrat[b].end();
            rrr.insert({highestrated.ff, b});
        }
        else{
            rrr.erase({oldhighestrating, b});
            pii highestrated = *--infrat[b].end();
            rrr.insert({highestrated.ff, b});
        }
    }

    for(ll i=0; i<q; i++){
        ll c, d;
        cin >> c >> d;

        ll oldkg = kg[c];
        rrr.erase({(*--infrat[oldkg].end()).ff, oldkg});
        infrat[oldkg].erase({rating[c], c});
        if(infrat[oldkg].size())
            rrr.insert({(*--infrat[oldkg].end()).ff, oldkg});

        kg[c] = d;
        ll oldhighestrating;
        if(infrat[d].size())
            oldhighestrating = (*--infrat[d].end()).ff;

        infrat[d].insert({rating[c], c});

        if(infrat[d].size() == 1){
            pii highestrated = *--infrat[d].end();
            rrr.insert({highestrated.ff, d});
        }
        else{
            rrr.erase({oldhighestrating, d});
            pii highestrated = *--infrat[d].end();
            rrr.insert({highestrated.ff, d});
        }

        ll ans = (*rrr.begin()).ff;
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
