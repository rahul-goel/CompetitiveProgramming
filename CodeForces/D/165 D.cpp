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

vvi adj;
vi deg, timein, timeout, subtree_size, branchindex, which_branch;
vpii edge;
ll tiktok = 0, root = -1;
//vector of segment trees
vvi sgts;

void add_edge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++, deg[v]++;
}

ll dfs(ll v, ll p){
    timein[v] = tiktok++;
    subtree_size[v] = 1;
    for(ll &u : adj[v]){
        if(u == p)
            continue;
        subtree_size[v] += dfs(u, v);
    }
    timeout[v] = tiktok++;
    return subtree_size[v];
}

void set_index(ll v, ll p, ll ind, ll branch_id){
    branchindex[v] = ind;
    which_branch[v] = branch_id;
    for(ll u : adj[v]){
        if(u == p)
            continue;
        set_index(u, v, ind+1, branch_id);
    }
}

void build(ll branch, ll v, ll tl, ll tr){
    if(tl == tr){
        sgts[branch][v] = 0;
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(branch, v<<1, tl, tm);
    build(branch, v<<1|1, tm+1, tr);
    sgts[branch][v] = sgts[branch][v<<1] + sgts[branch][v<<1|1];
}

void build_all(){
    for(ll i=0; i<(ll)sgts.size(); i++)
        sgts[i].resize(subtree_size[adj[root][i]] * 4), build(i, 1, 0, subtree_size[adj[root][i]]-1);
}

ll sum_query(ll branch, ll v, ll tl, ll tr, ll ql, ll qr){
    if(ql <= tl && tr <= qr){
        return sgts[branch][v];
    }
    ll tm = (tl + tr) >> 1;
    ll ret_val = 0;
    if(ql <= tm)
        ret_val += sum_query(branch, v<<1, tl, tm, ql, qr);
    if(tm+1 <= qr)
        ret_val += sum_query(branch, v<<1|1, tm+1, tr, ql, qr);
    return ret_val;
}

void update(ll branch, ll v, ll tl, ll tr, ll pos){
    if(tl == tr){
        sgts[branch][v] ^= 1;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(pos <= tm)
        update(branch, v<<1, tl, tm, pos);
    if(tm+1<=pos)
        update(branch, v<<1|1, tm+1, tr, pos);
    sgts[branch][v] = sgts[branch][v<<1] + sgts[branch][v<<1|1];
}

bool check_sum(ll a, ll b){
    if(a == root){
        ll val = sum_query(which_branch[b], 1, 0, subtree_size[adj[root][which_branch[b]]]-1, 0, branchindex[b]);
        return val == 0;
    }
    if(b == root){
        ll val = sum_query(which_branch[a], 1, 0, subtree_size[adj[root][which_branch[a]]]-1, 0, branchindex[a]);
        return val == 0;
    }
    if(which_branch[a] == which_branch[b]){
        if(branchindex[a] > branchindex[b])
            swap(a, b);
        ll val = sum_query(which_branch[a], 1, 0, subtree_size[adj[root][which_branch[a]]]-1, branchindex[a]+1, branchindex[b]);
        return val == 0;
    }
    else{
        ll val1 = sum_query(which_branch[b], 1, 0, subtree_size[adj[root][which_branch[b]]]-1, 0, branchindex[b]);
        ll val2 = sum_query(which_branch[a], 1, 0, subtree_size[adj[root][which_branch[a]]]-1, 0, branchindex[a]);
        return val1+val2 == 0;
    }
}

ll solve(){
    ll n;
    cin >> n;
    adj.resize(n), deg.resize(n);
    timein.resize(n), timeout.resize(n), subtree_size.resize(n);
    branchindex.resize(n), which_branch.resize(n);
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
        edge.pb({u, v});
    }

    root = max_element(all(deg)) - deg.begin();
    dfs(root, -1);
    sgts.resize(deg[root]);
    build_all();
    branchindex[root] = -1, which_branch[root] = -1;
    for(ll i=0; i<(ll)adj[root].size(); i++)
        set_index(adj[root][i], root, 0, i);

    ll queries_count;
    cin >> queries_count;
    while(queries_count--){
        ll type;
        cin >> type;
        if(type == 3){
            ll a, b;
            cin >> a >> b;
            a--, b--;

            if(a == b){
                cout << 0 << endl;
                continue;
            }

            if(!check_sum(a, b)){
                cout << -1 << endl;
                continue;
            }

            if(timein[a] <= timein[b] && timeout[b] <= timeout[a])
                cout << branchindex[b] - branchindex[a] << endl;
            else if(timein[b] <= timein[a] && timeout[a] <= timeout[b])
                cout << branchindex[a] - branchindex[b] << endl;
            else
                cout << branchindex[a] - branchindex[root] + branchindex[b] - branchindex[root] << endl;
        }
        else{
            ll query_id;
            cin >> query_id;
            query_id--;
            ll a = edge[query_id].ff, b = edge[query_id].ss;
            if(which_branch[a] == which_branch[b]){
                if(branchindex[a] > branchindex[b])
                    swap(a, b);
                update(which_branch[b], 1, 0, subtree_size[adj[root][which_branch[b]]]-1, branchindex[b]);
            }
            else if(a == root){
                update(which_branch[b], 1, 0, subtree_size[adj[root][which_branch[b]]]-1, branchindex[b]);
            }
            else if(b == root){
                update(which_branch[a], 1, 0, subtree_size[adj[root][which_branch[a]]]-1, branchindex[a]);
            }
        }
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

