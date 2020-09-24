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

void add_edge(int to, int from){
    adj[to].pb(from);
    adj_rev[from].pb(to);
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

void ssc(int n){
    visited.assign(n, false);
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());

    visited.assign(n, false);
    for(int i=0; i<n; i++){
        int v = order[i];
        if(!visited[v]){
            // means that this can represent the condensed graph
            dfs2(v);
            // do whatever you want to with the component.
            component.clear();
        }
    }
}

int main(){

    return 0;
}
