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

ll G = 0, B = 0;
vvpii adj;
vb visited;
vi subtree;

void add_edge(ll u, ll v, ll wt){
    adj[u].pb({wt, v});
    adj[v].pb({wt, u});
}

ll dfs(ll v){
    visited[v] = true;
    subtree[v] = 1;
    for(auto edge : adj[v]){
        ll u = edge.s;
        if(!visited[u])
            subtree[v] += dfs(u);
    }
    return subtree[v];
}

void dfs_solve(ll v){
    visited[v] = true;
    for(auto edge : adj[v]){
        ll u = edge.s, wt = edge.f;
        if(!visited[u]){
            B += min(subtree[u], (ll)adj.size()-subtree[u])*wt;
            G += (subtree[u]&1)*wt;
            dfs_solve(u);
        }       
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n*=2;
        G = B = 0;
        adj.clear(), visited.clear(), subtree.clear();
        adj.resize(n), visited.resize(n, false), subtree.resize(n, 0);
        for(int i=0; i<n-1; i++){
            int u, v, wt;
            cin >> u >> v >> wt;
            u--, v--;
            add_edge(u, v, wt);
        }
        dfs(0);
        visited.assign(n, false);
        dfs_solve(0);
        cout << G << " " << B << endl;
    }
    return 0;
}
