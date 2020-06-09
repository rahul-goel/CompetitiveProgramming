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
    vector < vector < char > > mat(55, vector < char > (55));
    for(ll i=0; i<55; i++)
        for(ll j=0; j<55; j++)
            mat[i][j] = '#';
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++)
            cin >> mat[i][j];

    ll dx, dy;
    dx = n, dy = m;

    ll cntg = 0, cntb = 0;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(mat[i][j] == 'G')
                cntg++;
            else if(mat[i][j] == 'B')
                cntb++;
        }
    }
    if(cntg == 0 && cntb == 0){
        cout << "Yes" << endl;
        return 0;
    }
    else if(cntg == 0 && cntb > 0){
        cout << "Yes" << endl;
        return 0;
    }

    if(mat[dx-1][dy] == 'B'){
        cout << "No" << endl;
        return 0;
    }
    if(mat[dx+1][dy] == 'B'){
        cout << "No" << endl;
        return 0;
    }
    if(mat[dx][dy+1] == 'B'){
        cout << "No" << endl;
        return 0;
    }
    if(mat[dx][dy-1] == 'B'){
        cout << "No" << endl;
        return 0;
    }

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(mat[i][j] == 'B'){
                if(mat[i+1][j] == 'G'){
                    cout << "No" << endl;
                    return 0;
                }
                if(mat[i-1][j] == 'G'){
                    cout << "No" << endl;
                    return 0;
                }
                if(mat[i][j-1] == 'G'){
                    cout << "No" << endl;
                    return 0;
                }
                if(mat[i][j+1] == 'G'){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(mat[i][j] == 'B'){
                if(mat[i-1][j] == '.')
                    mat[i-1][j] = '#';
                if(mat[i+1][j] == '.')
                    mat[i+1][j] = '#';
                if(mat[i][j+1] == '.')
                    mat[i][j+1] = '#';
                if(mat[i][j-1] == '.')
                    mat[i][j-1] = '#';
            }
        }
    }

    queue < pii > q;
    vvb vis(55, vb(55));
    for(ll i=0; i<55; i++){
        for(ll j=0; j<55; j++){
            if(mat[i][j] == 'G' || mat[i][j] == '.')
                vis[i][j] = false;
            else
                vis[i][j] = true;
        }
    }
    q.push({dx, dy});
    vis[dx][dy] = true;
    while(!q.empty()){
        ll x = q.front().ff, y = q.front().ss;
        q.pop();
        if(!vis[x-1][y]){
            q.push({x-1, y});
            vis[x-1][y] = true;
        }
        if(!vis[x+1][y]){
            q.push({x+1, y});
            vis[x+1][y] = true;
        }
        if(!vis[x][y-1]){
            q.push({x, y-1});
            vis[x][y-1] = true;
        }
        if(!vis[x][y+1]){
            q.push({x, y+1});
            vis[x][y+1] = true;
        }
    }

    bool flag = true;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(mat[i][j] == 'G' && vis[i][j] == false)
                flag = false;
        }
    }

    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

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

