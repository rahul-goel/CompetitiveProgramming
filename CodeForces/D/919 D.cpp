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

vvi adj, pathocc;
vi color, indeg;
vb vis;
string str;

void add_edge(ll from, ll to){
    adj[from].pb(to);
    indeg[to]++;
}

bool dfsc(ll v) {
    color[v] = 1;
    for (ll u : adj[v]) {
        if (color[u] == 0) {
            if (dfsc(u))
                return true;
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool is_there_a_cycle(){
    ll n = adj.size();
    bool flag = false;
    for(ll i=0; i<n; i++)
        if(color[i] == 0)
            flag |= dfsc(i);
    return flag;
}


ll solve(){
    ll n, m;
    cin >> n >> m;
    cin >> str;
    
    for(char &c : str)
        c -= 'a';

    adj.resize(n);
    pathocc.resize(n, vi(26));
    indeg.resize(n);
    color.resize(n);
    vis.resize(n);

    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    if(is_there_a_cycle()){
        cout << -1 << endl;
        return 0;
    }

    queue < ll > q;
    for(ll i=0; i<n; i++)
        if(!indeg[i])
            q.push(i), pathocc[i][str[i]] = 1;

    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(ll u : adj[v]){
            for(ll i=0; i<26; i++)
                pathocc[u][i] = max(pathocc[u][i], pathocc[v][i] + (str[u] == i));
            indeg[u]--;
            if(!indeg[u])
                q.push(u);
        }
    }

    ll ans = 0;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<26; j++)
            ans = max(ans, pathocc[i][j]);
    
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

