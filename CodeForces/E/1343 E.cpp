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
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

/*
    Code begins after this.
*/

vvi adj;
vb visited;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void bfs(ll a, vi &dist){
    queue < ll > q;
    q.push(a), dist[a] = 0;
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(ll u : adj[v]){
            if(dist[u] == LINF)
                dist[u] = dist[v] + 1, q.push(u);
        }
    }

}

ll solve(){
    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    map < pii, ll > cnt;
    vi edge_cost(m);
    for(ll &ec : edge_cost)
        cin >> ec;
    sort(all(edge_cost));
    vi pre(m+1);
    for(ll i=1; i<=(ll)edge_cost.size(); i++)
        pre[i] = pre[i-1] + edge_cost[i-1];

    adj.clear(), adj.resize(n+1);

    for(ll i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    vi da, db, dc;
    da = db = dc = vi(n+1, LINF);
    bfs(a, da), bfs(b, db), bfs(c, dc);

    ll ans = LINF;
    for(ll i=1; i<=n; i++){
        if(da[i] + db[i] + dc[i] > m)
            continue;
        ans = min(ans, pre[db[i]] + pre[da[i] + db[i] + dc[i]]);
    }
    cout << ans << endl;
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

