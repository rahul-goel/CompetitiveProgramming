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

int n, L, timer = 0;
vvi adj, up;
vi tin, tout;

void dfs(int v, int p){
    tin[v] = timer++;
    up[v][0] = p;
    for(int i=1; i<=L; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(int u : adj[v]){
        if(u != p)
            dfs(u, v);
    }
    tout[v] = timer++;
}

bool is_ancestor(int up, int low){
    return tin[low] >= tin[up] && tout[low] <= tout[up];
}

int lca(int u, int v){
    if(is_ancestor(u, v))
        return u;
    if(is_ancestor(v, u))
        return v;
    for(int i=L; i>=0; i--){
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void pre_process(int root){
    tin.resize(n), tout.resize(n);
    timer = 0, L = ceil(log2(n));
    up.assign(n, vi(L+1));
    dfs(root, root);
}

int main(){

    return 0;
}
