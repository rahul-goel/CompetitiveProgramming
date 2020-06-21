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

vi l, r;

bool f(ll mid, ll s){
    ll req = 0;
    ll n = r.size();
    ll cnt = 0, rem = 0;
    vi v;
    for(ll i=0; i<n; i++){
        if(r[i] < mid)
            req += l[i];
        else if(mid <= l[i])
            req += l[i], cnt++;
        else
            v.pb(l[i]);
    }

    sort(all(v), greater<ll>());

    rem = max(0LL, (n+1)/2 - cnt);
    if(rem > (ll)v.size())
        return false;
    for(ll i=0; i<(ll)v.size(); i++){
        if(i < rem)
            req += mid;
        else
            req += v[i];
    }
    return req <= s;
}

ll solve(){
    l.clear(), r.clear();

    ll n, s;
    cin >> n >> s;
    l.resize(n), r.resize(n);

    for(ll i=0; i<n; i++)
        cin >> l[i] >> r[i];

    ll start = 0, end = 1e10, mid, pos;
    while(start <= end){
        mid = (start + end) >> 1;
        if(f(mid, s))
            pos = mid, start = mid + 1;
        else
            end = mid - 1;
    }

    cout << pos << endl;

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
