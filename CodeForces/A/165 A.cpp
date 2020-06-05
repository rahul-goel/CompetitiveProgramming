/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
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
/*******************************************************************************/
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/* For PBDS */
/*Two new methods X.order_of_key() and X.find_by_order()*/
/*
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

/*******************************************************************************/
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define pii             pair < ll, ll >
#define vi              vector < ll >
#define vb              vector < bool >
#define vvi             vector < vector < ll > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < ll, ll > >
#define vvpii           vector < vector < pair < ll, ll > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
    Code begins after this.
*/

int mat[2005][2005] = {0};

int check(int x, int y){
    bool f1 = false, f2 = false, f3 = false, f4 = false;
    for(int i=0; i<x; i++)
        if(mat[i][y])
            f1 = true;
    for(int i=x+1; i<2005; i++)
        if(mat[i][y])
            f2 = true;
    for(int j=0; j<y; j++)
        if(mat[x][j])
            f3 = true;
    for(int j=y+1; j<2005; j++)
        if(mat[x][j])
            f4 = true;
    return f1&&f2&&f3&&f4;
}

ll solve(){
    int n;
    cin >> n;
    vpii vec;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        x += 1000, y += 1000;
        mat[x][y] = 1;
        vec.pb({x, y});
    }
    int ans = 0;
    for(auto p : vec){
        int x = p.ff, y = p.ss;
        if(check(x, y)) 
            ans++;
    }
    cout << ans << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

