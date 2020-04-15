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

    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        vi vec(n+1), count(201, 0);
        for(int i=1; i<=n; i++)
            cin >> vec[i], count[vec[i]]++, ans = max(count[vec[i]], ans);
        vvi freq(n+1, vi(201, 0)), position(201);
        for(int i=1; i<=n; i++){
            int u = vec[i];
            for(int j=1; j<=200; j++)
                freq[i][j] = freq[i-1][j] + (u == j);
            position[u].pb(i);
        }
        
        for(int i=1; i<=200; i++){
            for(int sz=1; sz<=n; sz++){
                if(position[i].size() >= 2*sz){
                    int pos1 = position[i][sz-1], pos2 = position[i][position[i].size() - sz];
                    int mid = 0;
                    for(int x=1; x<=200; x++)
                        mid = max(mid, freq[pos2-1][x] - freq[pos1][x]);
                    ans = max(ans, mid + 2*sz);
                }
                else
                    break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
