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
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair
char mat[1005][1005];
ll up[1005][1005] = {0}, down[1005][1005] = {0}, leftt[1005][1005] = {0}, rightt[1005][1005] = {0}, horizontal[1005][1005] = {0}, vertical[1005][1005] = {0};

ll solve(){
    ll n, m, count_star=0;
    cin >> n >> m;
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '*')
                count_star++;
        }
        
    if(count_star == 0){
        cout << 0 << '\n';
        return 0;
    }

    //down
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(mat[i][j] == '*')
                down[i][j] = down[i-1][j] + 1;
            else
                down[i][j] = 0;
        }
    }
    //up
    for(ll i=n; i>=1; i--){
        for(ll j=1; j<=m; j++){
            if(mat[i][j] == '*')
                up[i][j] = up[i+1][j] + 1;
            else
                up[i][j] = 0;
        }
    }
    //left
    for(ll j=1; j<=m; j++){
        for(ll i=1; i<=n; i++){
            if(mat[i][j] == '*')
                leftt[i][j] = leftt[i][j-1]+1;
            else
                leftt[i][j] = 0;
        }
    }
    //right
    for(ll j=m; j>=0; j--){
        for(ll i=1; i<=n; i++){
            if(mat[i][j] == '*')
                rightt[i][j] = rightt[i][j+1]+1;
            else
                rightt[i][j] = 0;
        }
    }

    //calculate
    vector < pair < ll, pii > > ans;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            ll x = min({up[i][j], down[i][j], rightt[i][j], leftt[i][j]}) - 1;
            if(x>=1)
                ans.pb({x, {i, j}});
        }
    }

    for(auto inst : ans){
        ll size = inst.f, x = inst.s.f, y = inst.s.s;
        horizontal[x][y-size] += 1, horizontal[x][y+size+1] += -1;
        vertical[x-size][y] += 1, vertical[x+size+1][y] += -1;
    }

    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=m; j++)
            horizontal[i][j] += horizontal[i][j-1];
    for(ll j=1; j<=m; j++)
        for(ll i=1; i<=n; i++)
            vertical[i][j] += vertical[i-1][j];

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++)
            if(mat[i][j] == '*' && (horizontal[i][j] == 0 && vertical[i][j] == 0)){
                cout << -1 << '\n';
                return 0;
            }
    }

    if(ans.size() == 0){
        cout << -1 << '\n';
        return 0;
    }

    cout << ans.size() << '\n';
    for(auto inst : ans)
        cout << inst.s.f << " " << inst.s.s << " " << inst.f << '\n';

    return 0;
}

int main(){
    fastio;

    ll t;
    t = 1;
    while(t--)
        solve();

    return 0;
}
