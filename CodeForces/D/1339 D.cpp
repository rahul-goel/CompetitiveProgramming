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
 
using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1000000000;
 
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

ll n, L, timer = 0;
vvi adj, up;
vi tin, tout;
vb is_leaf;

bool set_flag = true;

ll dfs_check(ll v, ll p){
    ll arr[2] = {0};
    for(ll u : adj[v])
        if(u != p){
            ll val = 1 + dfs_check(u, v);
            arr[val%2]++;
        }
    if(arr[0] && arr[1])
        set_flag = false;
    if(arr[0])
        return 0;
    else return 1;
}

ll dfsmax(ll v, ll p){
    ll count = 0, leaf_count = 0;
    for(ll u : adj[v]){
        if(u == p)
            continue;
        if(is_leaf[u])
            leaf_count++;
        else
            count += 1 + dfsmax(u, v);
    }
    if(leaf_count)
        count++;
    return count;
}

int main(){
    cin >> n;
    adj.resize(n), is_leaf.resize(n, false);
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    ll root = -1;
    for(ll i=0; i<n; i++){
        if(adj[i].size() > 1){
            root = i;
        }
        else
            is_leaf[i] = true;
    }

    ll ans_max = dfsmax(root, root), ans_min; 
    dfs_check(root, root);

    if(set_flag == false)
        ans_min = 3;
    else
        ans_min = 1;

    cout << ans_min << " " << ans_max << endl;
    return 0;
}
