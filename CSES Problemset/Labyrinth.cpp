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
    ll n, m;
    cin >> n >> m;
    vvi mat(n+5, vi(m+5, 0));
    vvb vis(n+5, vb(m+5, true));
    vvpii parent(n+5, vpii(m+5, {-1, -1}));
   
    pii start, end;
   
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            vis[i][j] = false;
            char x;
            cin >> x;
            if(x == 'A')
                start = {i, j};
            else if(x == 'B')
                end = {i, j};
            mat[i][j] = (x != '#');
        }
    }

    queue < pii > q;
    vis[start.ff][start.ss] = true;
    q.push({start.ff, start.ss});
    
    while(!q.empty()){
        ll x = q.front().ff, y = q.front().ss;
        q.pop();
        if(!vis[x+1][y] && mat[x+1][y])
            q.push({x+1, y}), vis[x+1][y] = true, parent[x+1][y] = {x, y};
        if(!vis[x-1][y] && mat[x-1][y])
            q.push({x-1, y}), vis[x-1][y] = true, parent[x-1][y] = {x, y};
        if(!vis[x][y+1] && mat[x][y+1])
            q.push({x, y+1}), vis[x][y+1] = true, parent[x][y+1] = {x, y};
        if(!vis[x][y-1] && mat[x][y-1])
            q.push({x, y-1}), vis[x][y-1] = true, parent[x][y-1] = {x, y};
    }

    if(vis[end.ff][end.ss] == false){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    vpii path;
    while(end != start)
        path.pb(end), end = parent[end.ff][end.ss];
    reverse(all(path));
    
    string ans;
    
    for(auto p : path){
        if(p.ff == start.ff){
            if(p.ss == start.ss + 1)
                ans += 'R';
            else
                ans += 'L';
        }
        else{
            if(p.ff == start.ff + 1)
                ans += 'D';
            else
                ans += 'U';
        }
        start = p;
    }

    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

