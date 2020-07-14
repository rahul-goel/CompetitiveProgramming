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

void count_sort(vi &p, vi &c){
    ll n = p.size();
    vi cnt(n);
    for(auto x : c)
        cnt[x]++;
    vi pos(n), pnew(n);
    pos[0] = 0;
    for(ll i=1; i<n; i++)
        pos[i] = pos[i-1] + cnt[i-1];
    for(auto x : p){
        ll i = c[x];
        pnew[pos[i]] = x;
        pos[i]++;
    }
    p = pnew;
}


ll solve(){

    string s, t;
    cin >> s >> t;

    string str = s + "#" + t;
    str += "$";

    ll n = str.size();
    vi c(n), p(n);
    {
        vpii a(n);
        for(ll i=0; i<n; i++)
            a[i] = {str[i], i};
        sort(all(a));
        for(ll i=0; i<n; i++)
            p[i] = a[i].ss;
        c[p[0]] = 0;
        for(ll i=1; i<n; i++){
            if(str[p[i]] == str[p[i-1]])
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] + 1;
        }
    }

    ll k = 0;
    while((1<<k) < n){
        for(ll i=0; i<n; i++)
            p[i] = (p[i] - (1<<k) + n)%n;
        count_sort(p, c);
        vi cnew(n);
        cnew[p[0]] = 0;
        for(ll i=1; i<n; i++){
            pii prev = {c[p[i-1]], c[(p[i-1] + (1<<k)) % n]};
            pii now = {c[p[i]], c[(p[i] + (1<<k)) % n]};
            if(prev == now)
                cnew[p[i]] = cnew[p[i-1]];
            else
                cnew[p[i]] = cnew[p[i-1]] + 1;
        }
        c = cnew;
        k++;
    }

    vi lcp(n, 0);
    // k is the prefix already calculated
    k = 0;
    for(ll i=0; i<n-1; i++){
        //since all the classes are now different, c[i] holds the position of index i in the suffix array
        ll pi = c[i];
        if(pi == n-1){
            // this is lexicographically the largest, so lcp with 1 more than this does not exist
            k = 0;
            continue;
        }
        // next lexicographically larger string's starting index
        ll j = p[pi+1];
        while((i+k) < n && (j+k) < n && str[i+k] == str[j+k])
            k++;
        lcp[pi] = k;
        k = max(0ll, k-1);
    }

    ll ans = 0;
    for(ll i=0; i<n-1; i++){
        if((p[i] < (ll)s.size() && p[i+1] > (ll)s.size()) || (p[i] > (ll)s.size() && p[i+1] < (ll)s.size()))
            ans = max(ans, lcp[i]);
    }

    for(ll i=0; i<n-1; i++){
        if((p[i] < (ll)s.size() && p[i+1] > (ll)s.size()) || (p[i] > (ll)s.size() && p[i+1] < (ll)s.size())){
            if(ans == lcp[i]){
                cout << str.substr(p[i], ans) << endl;
                return 0;
            }
        }
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

