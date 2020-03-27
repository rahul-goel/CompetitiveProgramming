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
 
#define pii pair < int, int >
#define vi vector < int >
#define vb vector < bool >
#define vvi vector < vector < int > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

int T = 0;
vvi adj;
vi parent, depth, tin, tout;

void add_edge(int u, int v){
    adj[u].pb(v), adj[v].pb(u);
}

void dfs(int v, int par, int dep){
    parent[v] = par, depth[v] = dep;
    tin[v] = T++;
    for(int u : adj[v]){
        if(u != par)
            dfs(u, v, dep+1);
    }
    tout[v] = T++;
}

bool is_ancestor(int high_rank, int low_rank){
    if(tin[low_rank] >= tin[high_rank] && tout[low_rank] <= tout[high_rank])
        return true;
    else
        return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    adj.resize(n), depth.resize(n), parent.resize(n), tin.resize(n), tout.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }

    parent[0] = -1;
    dfs(0, -1, 0);

    while(m--){
        int k;
        cin >> k;
        vi vec(k);
        
        for(auto &it : vec){
            cin >> it;
            it--;
        }
        
        int max_dep = vec[0];
        for(auto &it : vec)
            if(depth[it] > depth[max_dep])
                max_dep = it;
        for(auto &it : vec)
            if(it != max_dep && parent[it] != -1)
                it = parent[it];

        bool flag = true;
        for(auto it : vec)
            if(is_ancestor(it, max_dep) == false)
                flag = flag && false;

        cout << (flag ? "YES" : "NO") << endl;
                
    }
    return 0;
}
