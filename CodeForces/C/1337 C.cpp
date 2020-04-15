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
const ll INF = 1e9;
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
#define pb push_back
#define f first
#define s second
#define mp make_pair

vvi adj;
vb visited;
vi child;
vpii dist;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll dfs(ll v, ll prev_dist){
    visited[v] = true;
    ll count = 1;
    for(ll u : adj[v]){
        if(!visited[u]){
            count += dfs(u, prev_dist + 1);
        }
    }
    child[v] = count;
    dist.pb({prev_dist+1-child[v]+1, v});
    return count;
}

bool cmp(const pii &a, const pii &b){
    if(a.f > b.f)
        return true;
    else
        return false;
}

int main(){
    fastio;

    ll n, k;
    cin >> n >> k;
    adj.resize(n), visited.resize(n, false), child.resize(n, 0);
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    dfs(0, -1);
    sort(dist.begin(), dist.end(), greater<pii>());
    ll ans = 0;
    for(ll i=0; i<k; i++){
        ans += dist[i].f;
    }
    cout << ans << endl;
    return 0;
}
