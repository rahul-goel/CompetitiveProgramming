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

vvi adj;
void add_edge(int u, int v){
    adj[v].pb(u);
    adj[u].pb(v);
}

int main(){
    int n;
    cin >> n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
    }
    bool flag = false;
    for(int i=0; i<n; i++){
        if(adj[i].size() == 2)
            flag = true;
    }
    if(flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
