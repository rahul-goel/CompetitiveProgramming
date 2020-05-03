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
vb visited;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll dfs(ll v){
    visited[v] = true;
    ll count = 1;
    for(ll u : adj[v]){
        if(!visited[u])
            count += dfs(u);
    }
    return count;
}

ll solve(){
    adj.clear(), visited.clear();
    adj.resize(11), visited.resize(11, false);
    vi is_there(11, false);
    ll n;
    cin >> n;
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i], is_there[vec[i]] = true;
    sort(all(vec));
    for(ll i=0; i<n-1; i++)
        if(vec[i+1] - vec[i] <= 2)
            add_edge(vec[i], vec[i+1]);
    vi ans;
    for(ll i=0; i<11; i++)
        if(is_there[i] && !visited[i])
            ans.pb(dfs(i));
    sort(all(ans));
    cout << ans.front() << " " << ans.back() << endl;
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

