/*
   Created by Rahul Goel.
*/

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

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define min_pq(t) priority_queue < t, vector < t >, greater < t > >
#define max_pq(t) priority_queue < t >
#define pb push_back
#define ff first
#define ss second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

// --------------------------------------------------------------

vvi adj;
vb vis;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void dfs(ll v){
    vis[v] = true;
    for(ll u : adj[v])
        if(!vis[u])
            dfs(u);
}

ll solve(){
    ll n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            char c;
            cin >> c;
            if(c == '#')
                mat[i][j] = 0;
            else
                mat[i][j] = 1;
        }
    }

    bool flag = true;
    ll whiterow = 0, whitecol = 0;
    for(ll i=0; i<n; i++){
        ll cnt = 0;
        for(ll j=0; j<m; j++)
            if(mat[i][j] == 0)
                cnt++;
        if(cnt > 1){
            ll low = 0, high = m-1;
            for(ll j=0; j<m; j++){
                if(mat[i][j] == 0){
                    low = j;
                    break;
                }
            }
            for(ll j=m-1; j>=0; j--){
                if(mat[i][j] == 0){
                    high = j;
                    break;
                }
            }
            if(high - low + 1 > cnt)
                flag = false;
        }
        if(cnt == 0)
            whiterow++;
    }
    for(ll j=0; j<m; j++){
        ll cnt = 0;
        for(ll i=0; i<n; i++)
            if(mat[i][j] == 0)
                cnt++;
        if(cnt > 1){
            ll low = 0, high = m-1;
            for(ll i=0; i<n; i++){
                if(mat[i][j] == 0){
                    low = i;
                    break;
                }
            }
            for(ll i=n-1; i>=0; i--){
                if(mat[i][j] == 0){
                    high = i;
                    break;
                }
            }
            if(high - low + 1 > cnt)
                flag = false;
        }
        if(cnt == 0)
            whitecol++;
    }
    
    if(whiterow && !whitecol)
        flag = false;
    if(whitecol && !whiterow)
        flag = false;
    if(flag == false){
        cout << -1 << endl;
        return 0;
    }

    map < pii, ll > mapper;
    ll mpc = 0;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            if(mat[i][j] == 0)
                mapper[{i, j}] = mpc++;
    adj.resize(mpc), vis.resize(mpc, false);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m-1; j++)
            if(mat[i][j] == 0 && mat[i][j+1] == 0)
                add_edge(mapper[{i, j}], mapper[{i, j+1}]);
    }
    for(ll j=0; j<m; j++){
        for(ll i=0; i<n-1; i++)
            if(mat[i][j] == 0 && mat[i+1][j] == 0)
                add_edge(mapper[{i, j}], mapper[{i+1, j}]);
    }
        
    ll count = 0;
    for(ll i=0; i<mpc; i++){
        if(!vis[i])
            count++, dfs(i);
    }
    cout << count << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

