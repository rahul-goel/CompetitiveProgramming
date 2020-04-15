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

int hsh(int r, int c, int m){
    return r*m + c;
}

pii reverse_hsh(int x, int m){
    return {(x/m), (x%m)};
}

vvi adj;
void add_edge(int u, int v){
    adj[u].pb(v), adj[v].pb(u);
}

int main(){
    fastio;

    int r, c, start, end;
    cin >> r >> c;
    int mat[1005][1005];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char x;
            cin >> x;
            if(x == 'E')
                end = hsh(i, j, c), mat[i][j] = 0;
            else if(x == 'S')
                start = hsh(i, j, c), mat[i][j] = 0;
            else if(x == 'T')
                mat[i][j] = -1;
            else
                mat[i][j] = x - '0';
        }
    }

    adj.resize(r*c);
    for(int i=0; i<r-1; i++){
        for(int j=0; j<c; j++)
            if(mat[i][j] != -1 && mat[i+1][j] != -1)
                add_edge(hsh(i, j, c), hsh(i+1, j, c));
    }
    for(int j=0; j<c-1; j++){
        for(int i=0; i<r; i++){
            if(mat[i][j] != -1 && mat[i][j+1] != -1)
                add_edge(hsh(i, j, c), hsh(i, j+1, c));
        }
    }

    vi parent(r*c), dist(r*c, INF);
    vb visited(r*c, false);
    queue < int > q;
    q.push(end), visited[end] = true, parent[end] = -1, dist[end] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v])
                visited[v] = true, parent[v] = u, dist[v] = dist[u] + 1, q.push(v);
        }
    }
    int count = 0;
    for(int i=0; i<r*c; i++){
        pii pikachu = reverse_hsh(i, c);
        if(mat[pikachu.f][pikachu.s] > 0 && dist[i] <= dist[start]){
            count += mat[pikachu.f][pikachu.s];
        }
    }

    cout << count << endl;
    
    return 0;
}
