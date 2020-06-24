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

vvb inp, mat, vis;
vvi dist;
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

ll gb(ll x, ll y, ll n, ll m){
    ll flag = 0;
    for(ll i=0; i<4; i++){
        if(x+dx[i]>=0 && x+dx[i]<n)
            if(y+dy[i]>=0 && y+dy[i]<m)
                if(inp[x][y] == inp[x+dx[i]][y+dy[i]])
                    flag = 1;
    }
    return flag;
}

ll solve(){
    ll n, m, t;
    cin >> n >> m >> t;

    vis = inp = mat = vvb(n, vb(m));
    dist = vvi(n, vi(m));

    char dummy;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            cin >> dummy, inp[i][j] = (dummy == '1');

    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            mat[i][j] = gb(i, j, n, m);

    queue < pii > q;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            if(mat[i][j])
                q.push({i, j}), vis[i][j] = true, dist[i][j] = 0;

    while(!q.empty()){
        ll x = q.front().ff, y = q.front().ss;
        q.pop();
        for(ll i=0; i<4; i++){
            if(x+dx[i]>=0 && x+dx[i]<n)
                if(y+dy[i]>=0 && y+dy[i]<m)
                    if(!vis[x+dx[i]][y+dy[i]])
                        q.push({x+dx[i], y+dy[i]}), vis[x+dx[i]][y+dy[i]] = true, dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1;
        }
    }

    while(t--){
        ll x, y, p;
        cin >> x >> y >> p;
        x--, y--;
        if(!vis[x][y] || p < dist[x][y])
            cout << inp[x][y] << endl;
        else
            cout << (((p - dist[x][y])&1)^inp[x][y]) << endl;
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

