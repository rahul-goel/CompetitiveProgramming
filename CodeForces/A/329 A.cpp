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
    char mat[105][105];
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> mat[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int count = 0;
            for(int k=1; k<=n; k++){
                if(mat[i][k] == 'E')
                    count++;
                if(mat[k][j] == 'E')
                    count++;
            }
            if(count == 2*n){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vpii ans;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mat[i][j] == '.'){
                ans.pb({i, j});
                break;
            }
        }
    }

    if(ans.size() != n){
        ans.clear();
        for(int j=1; j<=n; j++){
            for(int i=1; i<=n; i++){
                if(mat[i][j] == '.'){
                    ans.pb({i, j});
                    break;
                }
            }
        }
    }

    for(auto &foo : ans)
        cout << foo.f << " " << foo.s << endl;

    return 0;
}
