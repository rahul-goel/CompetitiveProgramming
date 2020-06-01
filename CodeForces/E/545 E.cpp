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

vvpii adj;
ll total_weight = 0;

void add_edge(ll u, ll v, ll wt){
    adj[u].pb({v, wt});
    adj[v].pb({u, wt});
}

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, LINF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
            else if(d[v] + len == d[to]){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

ll solve(){
    map < pii, pii > ids;
    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    vi d, p;
    for(ll i=0; i<m; i++){
        ll u, v, wt;
        cin >> u >> v >> wt;
        u--, v--;
        add_edge(u, v, wt);
        ids[make_pair(min(u, v), max(u, v))] = {i+1, wt};
    }
    
    ll source;
    cin >> source;
    source--;
    dijkstra(source, d, p);

    vi ans;
    for(ll i=0; i<n; i++){
        if(i == source)
            continue;
        auto x = ids[make_pair(min(i, p[i]), max(i, p[i]))];
        ans.pb(x.ff);
        total_weight += x.ss;
    }
    sort(all(ans));
    cout << total_weight << endl;
    for(ll x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

