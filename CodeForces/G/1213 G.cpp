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
using ll = long long;
using ld = long double;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/*
.-.. . -. -.- .- / .. ... / .-.. --- ...- . -.-.--
 */
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
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/

/*
    Code begins after this.
*/

vi sizee, parent;
void make_set(ll v){
    parent[v] = v;
    sizee[v] = 1;
}
ll find_parent(ll v){
    if(v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]);
}
void union_sets(ll v, ll u){
    v = find_parent(v), u = find_parent(u);
    if(u != v){
        if(sizee[v] < sizee[u])
            swap(u, v);
        sizee[v] += sizee[u];
        parent[u] = v;
    }
}

struct edge{
    ll u, v, len;
};

vector < edge > edges;
vpii queries;
vi ans;

bool cmp(edge &a, edge &b){
    if(a.len < b.len)
        return true;
    else
        return false;
}

ll c2(ll x){
    return x*(x-1)/2;
}

ll solve(){
    ll n, q;
    cin >> n >> q;

    sizee = parent = vi(n);
    for(ll i=0; i<n; i++)
        make_set(i);

    for(ll i=1; i<n; i++){
        ll u, v, len;
        cin >> u >> v >> len;
        u--, v--;
        edges.pb({u, v, len});
    }

    sort(all(edges), cmp);
    reverse(all(edges));

    queries.resize(q);
    for(ll i=0; i<q; i++){
        ll x;
        cin >> x;
        queries[i] = {x, i};
    }

    sort(all(queries));

    ll res = 0;
    ans.resize(q);

    for(ll i=0; i<q; i++){
        while(edges.size() > 0 && edges.back().len <= queries[i].ff){
            ll u = edges.back().u, v = edges.back().v;
            u = find_parent(u), v = find_parent(v);
            edges.pop_back();
            res -= (c2(sizee[u]) + c2(sizee[v]));
            res += (c2(sizee[u] + sizee[v]));
            union_sets(u, v);
        }
        ans[queries[i].ss] = res;
    }

    for(ll aa : ans)
        cout << aa << " ";
    cout << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

