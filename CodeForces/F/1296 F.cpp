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
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
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

vvpii adj;
struct query{
    int u, v, mn;
};
vector < query > queries;

void add_edge(int u, int v, int wt=0){
    adj[u].pb({wt, v}), adj[v].pb({wt, u});
}

int main(){
    fastio;

    vpii order;
    int n;
    bool flag = true;
    cin >> n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        order.pb({u, v});
        add_edge(u, v);
    }
    int q;
    cin >> q;
    while(q--){
        int u, v, mn;
        cin >> u >> v >> mn;
        u--, v--;
        queries.pb({u, v, mn});

        queue < int > q;
        vb visited(n, false);
        vi path, parent(n);
        q.push(u), visited[u] = true, parent[u] = -1;
        while(!visited[v]){
            int from = q.front();
            q.pop();
            for(auto ed : adj[from]){
                int to = ed.s;
                if(!visited[to])
                    visited[to] = true, parent[to] = from, q.push(to);
            }
        }
        int p = v;
        while(p!=u)
            path.pb(p), p=parent[p];
        path.pb(u);
        reverse(all(path));
        for(int i=1; i<(int)path.size(); i++){
            for(auto &ed : adj[path[i]]){
                if(ed.s == path[i-1])
                    ed.f = max(ed.f, mn);
            }
            for(auto &ed : adj[path[i-1]]){
                if(ed.s == path[i])
                    ed.f = max(ed.f, mn);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(auto &ed : adj[i])
            if(ed.f == 0)
                ed.f = 1e6;
    }

    for(auto &shit : queries){
        int u = shit.u, v = shit.v, mn = shit.mn;
        queue < int > q;
        vb visited(n, false);
        vi parent(n), path;
        q.push(u), visited[u] = true, parent[u] = -1;
        while(!visited[v]){
            int from = q.front();
            q.pop();
            for(auto &ed : adj[from]){
                int to = ed.s;
                if(!visited[to])
                    visited[to] = true, parent[to] = from, q.push(to);
            }
        }
        int p = v;
        while(p!=u)
            path.pb(p), p=parent[p];
        path.pb(u);
        reverse(all(path));
        int min_val = 1e6;
        for(int i=1; i<(int)path.size(); i++){
            for(auto &ed : adj[path[i]]){
                if(ed.s == path[i-1])
                    min_val = min(ed.f, min_val);
            }
        }

        if(min_val != mn)
            flag = false;
    }

    if(flag == false){
        cout << -1 << endl;
        return 0;
    }

    for(auto ord : order){
        int u = ord.f, v = ord.s;
        int value;
        for(auto &ed : adj[u]){
            if(ed.s == v){
                value = ed.f;
                break;
            }        
        }
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
