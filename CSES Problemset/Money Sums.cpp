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
#define pii             pair < int, int >
#define vi              vector < int >
#define vb              vector < bool >
#define vvi             vector < vector < int > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < int, int > >
#define vvpii           vector < vector < pair < int, int > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aint(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(aint(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
int mod_sum() { return 0; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

int mod_prod() { return 1; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
    Code begins after this.
*/


int solve(){
    int n;
    cin >> n;
    vi vec(n);
    int mx = 0;
    for(int i=0; i<n; i++)
        cin >> vec[i], mx = max(mx, vec[i]);

    vvb dp(mx*n+5, vb(n, false));
    for(int j=0; j<n; j++)
        dp[vec[j]][j] = true;
    
    for(int i=1; i<=mx*n; i++){
        for(int j=0; j<n; j++){
            if(i-vec[j] >= 0 && j>0)
                dp[i][j] = dp[i][j] || dp[i-vec[j]][j-1];
            if(j>0)
                dp[i][j] = dp[i][j] || dp[i][j-1];
        }
    }

    vi ans;
    for(int i=1; i<=mx*n; i++)
        if(dp[i][n-1])
            ans.pb(i);
    cout << ans.size() << endl;
    for(int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

