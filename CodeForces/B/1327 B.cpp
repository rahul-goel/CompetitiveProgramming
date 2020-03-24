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

vvi adj;
vi vis, vis_lady;

int main(){
    int t;
    cin >> t;
    while(t--){
        adj.clear(), vis.clear(), vis_lady.clear();
        int n;
        cin >> n;
        adj.resize(n+1), vis.resize(n+1, 0), vis_lady.resize(n+1, 0);

        for(int i=1; i<=n; i++){
            int k;
            cin >> k;
            adj[i].resize(k);
            for(int j=0; j<k; j++)
                cin >> adj[i][j];
        }

        for(int i=1; i<=n; i++){
            for(int x : adj[i]){
                if(!vis[x]){
                    vis[x] = 1, vis_lady[i] = 1;
                    break;
                }
            }
        }
        int count = 0, count_lady = 0, guy = -1, lady = -1;
        for(int i=1; i<=n; i++){
            if(vis[i] == 0)
                count++, guy = i;
            if(vis_lady[i] == 0)
                count_lady++, lady = i;
        }
        if(count_lady == 0 && count == 0)
            cout << "OPTIMAL" << endl;
        else{
            cout << "IMPROVE" << endl;
            cout << lady << " " << guy << endl;
        }
    }
    return 0;
}
