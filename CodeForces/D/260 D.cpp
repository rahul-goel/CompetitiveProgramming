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

struct ast{
    ll u, v, len;
};

vector < ast > ans;

ll solve(){
    ll n;
    cin >> n;

    min_pq(pii) pq0;
    min_pq(pii) pq1;

    for(ll i=0; i<n; i++){
        ll which, s;
        cin >> which >> s;
        if(which == 0)
            pq0.push({s, i});
        else
            pq1.push({s, i});
    }

    ll atlast0 = pq0.top().ss, atlast1 = pq1.top().ss;

    while(!pq0.empty() && !pq1.empty()){
        if(pq0.top().ff < pq1.top().ff){
            ll v = pq0.top().ss;
            ll u = pq1.top().ss;
            ll len = pq0.top().ff;
            ans.pb({u, v, len});
            ll temp = pq1.top().ff - len;
            pq0.pop(), pq1.pop();
            pq1.push({temp, u});
        }
        else{
            ll v = pq1.top().ss;
            ll u = pq0.top().ss;
            ll len = pq1.top().ff;
            ans.pb({u, v, len});
            ll temp = pq0.top().ff - len;
            pq0.pop(), pq1.pop();
            pq0.push({temp, u});
        }
    }

    if((ll)ans.size() < n-1 && !pq0.empty()){
        pq0.pop();
        while(!pq0.empty())
            ans.pb({atlast1, pq0.top().ss, 0}), pq0.pop();
    }
    else if((ll)ans.size() < n-1 && !pq1.empty()){
        pq1.pop();
        while(!pq1.empty())
            ans.pb({atlast0, pq1.top().ss, 0}), pq1.pop();
    }

    for(auto xxx : ans)
        cout << xxx.u+1 << " " << xxx.v+1 << " " << xxx.len << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

