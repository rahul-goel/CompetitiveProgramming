/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
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
const ll mod = 1000000007;
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
using pii = pair < int, int >;
using vi = vector < int >;
using vb = vector < bool >;
using vvi = vector < vector < int > >;
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

int solve(){
    int n;
    cin >> n;
    vi vec(n << 1);
    vi mx(n << 1);

    for(int &x : vec)
        cin >> x;
    mx.front() = vec.front();
    for(int i = 1; i < (n << 1); i++)
        mx[i] = max(vec[i], mx[i - 1]);

    vi v;
    for(int i = (n << 1) - 1, cnt = 0; i >= 0; i--){
        cnt++;
        if(vec[i] == mx[i]){
            v.pb(cnt);
            cnt = 0;
        }
    }

    vvi dp(n * 2 + 5, vi(n * 2 + 5));
    dp[0][0] = 1;
    for(int i = 1; i <= (int)v.size(); i++){
        for(ll j = 0; j <= n; j++){
            if(dp[i - 1][j])
                dp[i][j] = 1;
            if(j + v[i - 1] <= n && dp[i - 1][j])
                dp[i][j + v[i - 1]] = 1;

        }
    }

    if(dp[v.size()][n])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


signed main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

