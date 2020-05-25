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


ll solve(){
    ll n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            char x;
            cin >> x;
            mat[i][j] = (ll)x;
        }
    }

    vvi math = mat;
    vvi matv(m, vi(n));
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            matv[j][i] = mat[i][j];

    for(ll i=0; i<n; i++){
        sort(all(math[i]));
        uniq(math[i]);
    }
    for(ll i=0; i<m; i++){
        sort(all(matv[i]));
        uniq(matv[i]);
    }

    bool hor = true;
    for(ll i=0; i<n; i++){
        if(math[i].size() > 1)
            hor = false;
    }
    
    if(hor){
        ll r=0, g=0, b=0;
        ll ro=0, go=0, bo=0;
        for(ll i=0; i<n; ){
            if(math[i][0] == 'R'){
                ro++;
                while(i<n && math[i][0] == 'R')
                    i++, r++;
            } 
            else if(math[i][0] == 'G'){
                go++;
                while(i<n && math[i][0] == 'G')
                    i++, g++;
            } 
            else if(math[i][0] == 'B'){
                bo++;
                while(i<n && math[i][0] == 'B')
                    i++, b++;
            } 
        }
        if(r==g && g==b && ro==1 && bo==1 && go==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }

    bool ver = true;
    for(ll i=0; i<m; i++){
        if(matv[i].size() > 1)
            ver = false;
    }

    if(ver){
        ll r=0, g=0, b=0;
        ll ro=0, go=0, bo=0;
        for(ll i=0; i<m; ){
            if(matv[i][0] == 'R'){
                ro++;
                while(i<m && matv[i][0] == 'R')
                    i++, r++;
            } 
            else if(matv[i][0] == 'G'){
                go++;
                while(i<m && matv[i][0] == 'G')
                    i++, g++;
            } 
            else if(matv[i][0] == 'B'){
                bo++;
                while(i<m && matv[i][0] == 'B')
                    i++, b++;
            } 
        }
        if(r==g && g==b && ro==1 && bo==1 && go==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

