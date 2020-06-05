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

ll check(ll i, ll j, ll mat[505][505]){
    ll cnt = 0;
    if(mat[i-1][j] == 1)
        cnt++;
    if(mat[i+1][j] == 1)
        cnt++;
    if(mat[i][j-1] == 1)
        cnt++;
    if(mat[i][j+1] == 1)
        cnt++;
    return cnt;
}

bool neigh(pii start, pii dest){
    bool flag = false;
    if(start.ff+1==dest.ff && start.ss==dest.ss)
        flag = true;
    if(start.ff-1==dest.ff && start.ss==dest.ss)
        flag = true;
    if(start.ff==dest.ff && start.ss+1==dest.ss)
        flag = true;
    if(start.ff==dest.ff && start.ss-1==dest.ss)
        flag = true;
    return flag;
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    ll mat[505][505];
    for(ll i=0; i<505; i++)
        for(ll j=0; j<505; j++)
            mat[i][j] = 2;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            char c;
            cin >> c;
            if(c == '.')
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    pii start, dest;
    cin >> start.ff >> start.ss >> dest.ff >> dest.ss;
    if(start == dest){
        ll i = start.ff, j = start.ss;
        if(mat[i-1][j] == 1 || mat[i+1][j] == 1 || mat[i][j-1] == 1 || mat[i][j+1] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }
    else if(neigh(start, dest)){
        if(mat[dest.ff][dest.ss] == 0)
            cout << "YES" << endl;
        else if(check(dest.ff, dest.ss, mat) >= 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }

    bool vis[505][505];
    for(ll i=0; i<505; i++)
        for(ll j=0; j<505; j++)
            vis[i][j] = true;
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++)
            vis[i][j] = false;

    queue < pii > q;
    q.push(start), vis[start.ff][start.ss] = true;
    while(!q.empty()){
        ll i = q.front().ff, j = q.front().ss;
        q.pop();
        if(!vis[i-1][j] && mat[i-1][j] == 1)
            vis[i-1][j] = true, q.push({i-1, j});
        if(!vis[i+1][j] && mat[i+1][j] == 1)
            vis[i+1][j] = true, q.push({i+1, j});
        if(!vis[i][j-1] && mat[i][j-1] == 1)
            vis[i][j-1] = true, q.push({i, j-1});
        if(!vis[i][j+1] && mat[i][j+1] == 1)
            vis[i][j+1] = true, q.push({i, j+1});

        if(!vis[i-1][j] && make_pair(i-1, j) == dest)
            vis[i-1][j] = true, q.push({i-1, j});
        if(!vis[i+1][j] && make_pair(i+1, j) == dest)
            vis[i+1][j] = true, q.push({i+1, j});
        if(!vis[i][j-1] && make_pair(i, j-1) == dest)
            vis[i][j-1] = true, q.push({i, j-1});
        if(!vis[i][j+1] && make_pair(i, j+1) == dest)
            vis[i][j+1] = true, q.push({i, j+1});
    }
    
    if(!vis[dest.ff][dest.ss])
        cout << "NO" << endl;
    else{
        if(mat[dest.ff][dest.ss] == 0)
            cout << "YES" << endl;
        else if(mat[dest.ff][dest.ss] == 1 && check(dest.ff, dest.ss, mat)>=2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

