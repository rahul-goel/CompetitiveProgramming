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

int n;
vvi adj;
vector < bool > vis;
vi ans;

void dfs(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u])
            dfs(u);
    }
    ans.pb(v);
}

void topological_sort(){
    vis.resize(n, false), ans.clear();
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    
    return 0;
}
