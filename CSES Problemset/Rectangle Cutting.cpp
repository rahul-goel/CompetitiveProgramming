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
    int a, b;
    cin >> a >> b;
    vvi dp(a+1, vi(b+1, INF));
    for(int i=1; i<(int)min(dp.size(), dp[0].size()); i++)
        dp[i][i] = 0;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int x=0; x<=i; x++){
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i-x][j] + 1);
            }
            for(int y=0; y<=j; y++){
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j-y] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

