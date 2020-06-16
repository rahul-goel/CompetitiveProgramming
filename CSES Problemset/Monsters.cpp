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


int solve(){
    int n, m;
    cin >> n >> m;
    vvi mat(n+5, vi(m+5, 0));
    vpii monsters;
    pii me;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char x;
            cin >> x;
            if(x == 'M')
                monsters.pb({i, j});
            else if(x == 'A')
                me = {i, j};

            mat[i][j] = (x != '#');
        }
    }

    vpii bound;
    for(int i=2; i<n; i++){
        if(mat[i][m])
            bound.pb({i, m});
        if(mat[i][1])
            bound.pb({i, 1});
    }
    for(int j=2; j<m; j++){
        if(mat[n][j])
            bound.pb({n, j});
        if(mat[1][j])
            bound.pb({1, j});
    }
    if(mat[1][1])
        bound.pb({1, 1});
    if(mat[1][m])
        bound.pb({1, m});
    if(mat[n][1])
        bound.pb({n, 1});
    if(mat[n][n])
        bound.pb({n, n});

    vvb vis1, vis2;
    vvi dist1, dist2;
    vvpii par;
    vis1 = vis2 = vvb(n+2, vb(m+2, true));
    dist1 = dist2 = vvi(n+2, vi(m+2, INF));
    par = vvpii(n+2, vpii(m+2, {-1, -1}));

    queue < pii > q1, q2;
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++)
            vis1[i][j] = vis2[i][j] = false;

    q1.push(me);
    vis1[me.ff][me.ss] = true;
    dist1[me.ff][me.ss] = 0;
    while(!q1.empty()){
        ll x = q1.front().ff;
        ll y = q1.front().ss;
        q1.pop();
        for(int i=0; i<4; i++)
            if(!vis1[x+dx[i]][y+dy[i]] && mat[x+dx[i]][y+dy[i]])
                vis1[x+dx[i]][y+dy[i]] = true, q1.push({x+dx[i], y+dy[i]}), dist1[x+dx[i]][y+dy[i]] = dist1[x][y] + 1, par[x+dx[i]][y+dy[i]] = {x, y};
    }

    for(auto monster : monsters)
        q2.push(monster), vis2[monster.ff][monster.ss] = true, dist2[monster.ff][monster.ss] = 0;
    while(!q2.empty()){
        ll x = q2.front().ff;
        ll y = q2.front().ss;
        q2.pop();
        for(int i=0; i<4; i++)
            if(!vis2[x+dx[i]][y+dy[i]] && mat[x+dx[i]][y+dy[i]])
                vis2[x+dx[i]][y+dy[i]] = true, q2.push({x+dx[i], y+dy[i]}), dist2[x+dx[i]][y+dy[i]] = dist2[x][y] + 1;
    }

    for(auto bb : bound){
        if(dist1[bb.ff][bb.ss] < dist2[bb.ff][bb.ss]){
            cout << "YES" << endl;
            string ans;
            pii cur = bb;
            while(cur != me){
                pii tmp = par[cur.ff][cur.ss];
                if(tmp.ff == cur.ff){
                    if(tmp.ss == cur.ss + 1)
                        ans += 'L';
                    else
                        ans += 'R';
                }
                else{
                    if(tmp.ff == cur.ff + 1)
                        ans += 'U';
                    else
                        ans += 'D';
                }
                cur = tmp;
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            cout << ans << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

