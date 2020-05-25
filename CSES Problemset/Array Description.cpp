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
    int n, m;
    cin >> n >> m;
    vi val(n);
    vvi dp(n, vi(m+5));

    for(int i=0; i<n; i++)
        cin >> val[i];

    if(val[0] == 0){
        for(int i=1; i<=m; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][val[0]] = 1;

    for(int i=1; i<n; i++){
        if(val[i] == 0){
            for(int j=1; j<=m; j++){
                dp[i][j] += dp[i-1][j-1];
                if(dp[i][j] >= mod)
                    dp[i][j] -= mod;
                dp[i][j] += dp[i-1][j];
                if(dp[i][j] >= mod)
                    dp[i][j] -= mod;
                dp[i][j] += dp[i-1][j+1];
                if(dp[i][j] >= mod)
                    dp[i][j] -= mod;
            }
        }
        else{
            dp[i][val[i]] += dp[i-1][val[i]-1];
            if(dp[i][val[i]] >= mod)
                dp[i][val[i]] -= mod;
            dp[i][val[i]] += dp[i-1][val[i]];
            if(dp[i][val[i]] >= mod)
                dp[i][val[i]] -= mod;
            dp[i][val[i]] += dp[i-1][val[i]+1];
            if(dp[i][val[i]] >= mod)
                dp[i][val[i]] -= mod;
        }
    }

    int ans = 0;
    for(int j=1; j<=m; j++)
        ans = mod_sum(ans, dp[n-1][j]);
    cout << ans << endl;

    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

