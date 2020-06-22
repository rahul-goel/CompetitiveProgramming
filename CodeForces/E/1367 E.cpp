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
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
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
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vi asci(26);
    for(char x : str)
        asci[x-'a']++;

    for(ll len = n; len>=1; len--){
        vb vis(len);
        vi cycles;

        for(ll i=0; i<len; i++){
            if(vis[i])
                continue;

            vis[i] = true;
            cycles.pb(0);
            cycles.back()++;
            ll j = (i+k)%len;

            while(!vis[j]){
                cycles.back()++;
                vis[j] = true;
                j = (j+k)%len;
            }
        }

        max_pq(ll) pq;
        for(ll i=0; i<26; i++)
            if(asci[i])
                pq.push(asci[i]);

        bool flag = true;
        sort(all(cycles));
        while(!cycles.empty()){
            if(pq.empty()){
                flag = false;
                break;
            }
            if(pq.top() < cycles.back()){
                flag = false;
                break;
            }
            ll rem = pq.top();
            rem -= cycles.back();
            pq.pop(), cycles.pop_back();
            if(rem)
                pq.push(rem);
        }
        if(flag){
            cout << len << endl;
            return 0;
        }
    }

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
