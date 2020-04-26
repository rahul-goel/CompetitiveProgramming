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

vvi memo;
vvb visited;
ll n, a, b;
string str;

ll dp(ll cur, ll prev){
    if(cur == n-1 && prev == 0)
        return a + b;
    else if(cur == n-1 && prev == 1)
        return 2*a + b;
    if(visited[cur][prev])
        return memo[cur][prev];
    visited[cur][prev] = true;
    
    if(str[cur] == '1')
        return memo[cur][prev] = dp(cur+1, 1) + a + 2*b;

    if(str[cur+1] == '1' && prev == 0)
        return memo[cur][prev] = dp(cur+1, 1) + 2*a + 2*b;
    else if(str[cur+1] == '1' && prev == 1)
        return memo[cur][prev] = dp(cur+1, 1) + a + 2*b;
    else if(str[cur+1] == '0' && prev == 0)
        return memo[cur][prev] = min(dp(cur+1, 0) + a + b, dp(cur+1, 1) + 2*a + 2*b);
    else
        return memo[cur][prev] = min(dp(cur+1, 0) + 2*a + b, dp(cur+1, 1) + a + 2*b);
}

ll solve(){
    cin >> n >> a >> b;
    cin >> str;

    memo.clear(), visited.clear();
    memo.resize(n+5, vi(2)), visited.resize(n+5, vb(2, false));

    cout << dp(0, 0) + b << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
