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
const ll INF = 1e18;
 
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

ll n;
vvi memo;
vvb visited;
vi vec, cost;

//add is the state of the last board
ll solve(ll cur, ll add){
    if(cur == n+1)
        return 0;
    if(visited[cur][add])
        return memo[cur][add];
    visited[cur][add] = true;

    for(ll i=0; i<3; i++){
        if(cur==1 || vec[cur]+i != vec[cur-1]+add)
            memo[cur][add] = min(memo[cur][add], solve(cur+1, i) + i*cost[cur]);
    }
    return memo[cur][add];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q;
    cin >> q;
    while(q--){
        cin >> n;
        memo.clear(), memo.resize(n+5, vi(3, INF)), visited.clear(), visited.resize(n+5, vb(3, false)), vec.clear(), vec.resize(n+5), cost.clear(), cost.resize(n+5);
        for(ll i=1; i<=n; i++)
            cin >> vec[i] >> cost[i];
        cout << solve(1, 0) << endl;
    }
    return 0;
}
