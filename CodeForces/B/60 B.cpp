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

int main(){
    fastio;

    char cube[15][15][15];
    int vis[15][15][15];

    memset(cube, 0, sizeof(cube));
    memset(vis, 1, sizeof(vis));

    int k, n, m;
    cin >> k >> n >> m;
    for(int i=1; i<=k; i++)
        for(int j=1; j<=n; j++)
            for(int t=1; t<=m; t++)
                cin >> cube[i][j][t], vis[i][j][t] = 0;
    int foo, baar;
    cin >> foo >> baar;
    queue < pair < int, pii > > qq;
    qq.push({1, {foo, baar}}), vis[1][foo][baar] = 1;
    int count = 1;
    while(!qq.empty()){
        auto point = qq.front();
        qq.pop();
        int p = point.f, q = point.s.f, r = point.s.s;

        if(!vis[p][q-1][r]){
            vis[p][q-1][r] = 1;
            if(cube[p][q-1][r] == '.'){
                qq.push({p, {q-1, r}});
                count++;
            }
        }
        if(!vis[p][q+1][r]){
            vis[p][q+1][r] = 1;
            if(cube[p][q+1][r] == '.'){
                qq.push({p, {q+1, r}});
                count++;
            }
        }
        if(!vis[p][q][r-1]){
            vis[p][q][r-1] = 1;
            if(cube[p][q][r-1] == '.'){
                qq.push({p, {q, r-1}});
                count++;
            }
        }
        if(!vis[p][q][r+1]){
            vis[p][q][r+1] = 1;
            if(cube[p][q][r+1] == '.'){
                qq.push({p, {q, r+1}});
                count++;
            }
        }
        if(!vis[p-1][q][r]){
            vis[p-1][q][r] = 1;
            if(cube[p-1][q][r] == '.'){
                qq.push({p-1, {q, r}});
                count++;
            }
        }
        if(!vis[p+1][q][r]){
            vis[p+1][q][r] = 1;
            if(cube[p+1][q][r] == '.'){
                qq.push({p+1, {q, r}});
                count++;
            }
        }
    }

        cout << count << endl;
        return 0;
    }
