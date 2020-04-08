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
#include <map>

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

struct edge{
    int u, v, wt;
    bool operator<(edge const &other){
        return wt < other.wt;
    }
};

vector < edge > edges;
vector < int > parent, size;

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a), b = find_set(b);
    if(a != b){
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a, size[a] += size[b];
    }
}

int kruskals(){
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto ed : edges){
        int u = ed.u, v = ed.v, wt = ed.wt;
        if(find_set(u) != find_set(v)){
            union_sets(u, v);
            cost += wt;
        }
    }
    return cost;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        edges.clear(), parent.resize(n*m), size.resize(n*m);

        vvi mat(n, vi(m));
        int count = 0;
        map < pii, int > mapping;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> mat[i][j];
                mapping[{i, j}] = count++;
            }
        }
    
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++)
                edges.pb({mapping[{i, j}], mapping[{i+1, j}], mat[i][j]^mat[i+1][j]});
        }
        for(int j=0; j<m-1; j++){
            for(int i=0; i<n; i++)
                edges.pb({mapping[{i, j}], mapping[{i, j+1}], mat[i][j]^mat[i][j+1]});
        }

        for(int i=0; i<n*m; i++)
            make_set(i);
        cout << kruskals() << endl;
    }
    return 0;
}
