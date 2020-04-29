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

bool ssc(int n){
    visited.assign(n, false);
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs1(i);
    reverse(order.begin(), order.end());

    int count = 0;
    visited.assign(n, false);
    for(int i=0; i<n; i++){
        int v = order[i];
        if(!visited[v]){
            // means that this can represent the condensed graph
            dfs2(v);
            count++;
            // do whatever you want to with the component.
            component.clear();
        }
    }
    if(count == 1)
        return true;
    else
        return false;
}

int hsh(int r, int c, int m){
    return r*m + c;
}

pii reverse_hsh(int x, int m){
    return {(x/m), (x%m)};
}

int main(){
    int n, m;
    cin >> n >> m;
    adj.resize(n*m), adj_rev.resize(n*m);
    string h, v;
    cin >> h >> v;
    for(int i=0; i<h.size(); i++){
        if(h[i] == '>')
            for(int j=0; j<m-1; j++)
                add_edge(hsh(i, j, m), hsh(i, j+1, m));
        else
            for(int j=1; j<m; j++)
                add_edge(hsh(i, j, m), hsh(i, j-1, m));
    }
    for(int j=0; j<v.size(); j++){
        if(v[j] == '^')
            for(int i=1; i<n; i++)
                add_edge(hsh(i, j, m), hsh(i-1, j, m));
        else
            for(int i=0; i<n-1; i++)
                add_edge(hsh(i, j, m), hsh(i+1, j, m));
    }
        
    cout << (ssc(n*m) ? "YES" : "NO") << endl;

    return 0;
}
