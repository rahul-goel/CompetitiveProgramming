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

void add_edge(int u, int v, vvi &adj){
    adj[v].pb(u), adj[u].pb(v);
}

struct LCA {
    vi height, euler, first, segtree;
    vb visited;
    int n;

    // pass the adjacency by reference because by default a it is by value so a copy is made
    LCA(vvi &adj, int root = 0){
        n = adj.size();
        height.resize(n), first.resize(n);
        euler.reserve(n * 2), visited.assign(n, false);

        dfs(adj, root);

        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vvi &adj, int from, int h = 0){
        visited[from] = true;
        height[from] = h;
        first[from] = euler.size();
        euler.pb(from);

        for(auto to : adj[from]){
            if(!visited[to]){
                dfs(adj, to, h + 1);
                euler.pb(from);
            }
        }
    }

    void build(int v, int tl, int tr){
        if(tl == tr){
            segtree[v] = euler[tr];
        }
        else{
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            int left = segtree[2 * v], right = segtree[2 * v + 1];
            segtree[v] = height[left] < height[right] ? left : right;
        }
    }

    int query(int v, int tl, int tr, int left, int right){
        if(tl > right || tr < left)
            return -1;
        if(tl >= left && tr <= right)
            return segtree[v];

        int tm = (tl + tr)/2;
        int left_value = query(2*v, tl, tm, left, right);
        int right_value = query(2*v + 1, tm+1, tr, left, right);
        if(left_value == -1)
            return right_value;
        if(right_value == -1)
            return left_value;
        return height[left_value] < height[right_value] ? left_value : right_value;
    }

    int lca(int u, int v){
        int left = first[u], right = first[v];
        if(left > right)
            swap(left, right);
        return query(1, 0, euler.size()-1, left, right);
    }
};

int main(){
    int n;
    cin >> n;
    vvi adj(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v, adj);
    }
    struct LCA solve(adj, 0);
    int q;
    cin >> q;
    while(q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;

        int lca_a_b = solve.lca(a, b);
        int lca_a_x = solve.lca(a, x);
        int lca_a_y = solve.lca(a, y);
        int lca_b_x = solve.lca(b, x);
        int lca_b_y = solve.lca(b, y);

        bool flag = false;
        int a_b = solve.height[a] + solve.height[b] - 2*solve.height[lca_a_b];
        int a_x = solve.height[a] + solve.height[x] - 2*solve.height[lca_a_x];
        int a_y = solve.height[a] + solve.height[y] - 2*solve.height[lca_a_y];
        int b_x = solve.height[b] + solve.height[x] - 2*solve.height[lca_b_x];
        int b_y = solve.height[b] + solve.height[y] - 2*solve.height[lca_b_y];

        if((k>=a_b) && ((a_b&1) == (k&1)))
            flag = true;
        if((k>=a_x+b_y+1) && (((a_x+b_y+1)&1) == (k&1)))
            flag = true;
        if((k>=a_y+b_x+1) && (((a_y+b_x+1)&1) == (k&1)))
            flag = true;

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
