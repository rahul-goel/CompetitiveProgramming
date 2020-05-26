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
typedef long long ll;
typedef long double ld;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
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
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define pii             pair < ll, ll >
#define vi              vector < ll >
#define vb              vector < bool >
#define vvi             vector < vector < ll > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < ll, ll > >
#define vvpii           vector < vector < pair < ll, ll > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
    Code begins after this.
*/


ll solve(){
    ll n;
    string l, r;
    cin >> n >> l >> r;
    
    vvi al(128), ar(128);
    for(ll i=0; i<n; i++) 
        al[l[i]].pb(i), ar[r[i]].pb(i);
    vpii ans;
    for(ll i='a'; i<='z'; i++){
        while(!al[i].empty() && !ar[i].empty())
            ans.pb({al[i].back(), ar[i].back()}), al[i].pop_back(), ar[i].pop_back();
        while(!al[i].empty() && !ar['?'].empty())
            ans.pb({al[i].back(), ar['?'].back()}), al[i].pop_back(), ar['?'].pop_back();
        while(!al['?'].empty() && !ar[i].empty())
            ans.pb({al['?'].back(), ar[i].back()}), al['?'].pop_back(), ar[i].pop_back();
    }
    while(!al['?'].empty() && !ar['?'].empty())
        ans.pb({al['?'].back(), ar['?'].back()}), al['?'].pop_back(), ar['?'].pop_back();
    
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x.ff+1 << " " << x.ss+1 << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

