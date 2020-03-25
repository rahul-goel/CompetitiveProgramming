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
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

vvi adj, adj_rev;
vector < bool > visited;
vi order, component;

void add_edge_directed(int to, int from){
    adj[to].pb(from);
    adj_rev[from].pb(to);
}

void add_edge_undirected(int to, int from){
    adj[to].pb(from), adj[from].pb(to);
    adj_rev[from].pb(to), adj_rev[to].pb(from);
}

// dfs to set the t_out time/ build the order array
void dfs1(int from){
    visited[from] = true;
    for(int to : adj[from]){
        if(!visited[to])
            dfs1(to);
    }
    order.pb(from);
}

// dfs to mark the connected component using adj_rev
// NOTE - At any point of time, the component array has only one connected component
void dfs2(int from){
    visited[from] = true, component.pb(from);
    for(int to : adj_rev[from]){
        if(!visited[to])
            dfs2(to);
    }
}

bool ssc(int n){
    visited.assign(n, false);
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());

    visited.assign(n, false);
    dfs2(order[0]);
    bool flag = true;
    for(int i=0; i<n; i++)
        flag = flag && visited[i];

    return flag;
}

int main(){
    while(true){
        int n, m;
        cin >> n >> m;
        if(n==0 && m==0)
            break;
        
        adj.clear(), adj_rev.clear(), visited.clear(), order.clear(), component.clear();
        adj.resize(n), adj_rev.resize(n);

        for(int i=0; i<m; i++){
            int u, v, type;
            cin >> u >> v >> type;
            u--, v--;
            if(type == 1)
                add_edge_directed(u, v);
            else
                add_edge_undirected(u, v);
        }

        bool ans = ssc(n);
        cout << (ans ? 1 : 0) << endl;
    }
    return 0;
}
