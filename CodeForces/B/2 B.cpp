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

ll counter(ll n, ll f){
    ll ret = 0;
    while(n > 0 && n%f == 0)
        n/=f, ret++;
    return ret;
}

ll solve(){
    ll n;
    cin >> n;
    vvi mat, mat2, mat5, dp2, dp5;
    mat = mat2 = mat5 = dp2 = dp5 = vvi(n, vi(n));
    vector < vector < char > > path2, path5;
    path2 = path5 = vector < vector < char > > (n, vector < char > (n));

    bool zero = false;

    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
            cin >> mat[i][j], zero |= (mat[i][j] == 0);

    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
            mat2[i][j] = counter(mat[i][j], 2), mat5[i][j] = counter(mat[i][j], 5);

    dp2[0][0] = mat2[0][0];
    dp5[0][0] = mat5[0][0];

    for(ll i=1; i<n; i++){
        dp2[i][0] = mat2[i][0] + dp2[i-1][0];
        path2[i][0] = 'D';
        dp5[i][0] = mat5[i][0] + dp5[i-1][0];
        path5[i][0] = 'D';
        dp2[0][i] = mat2[0][i] + dp2[0][i-1];
        path2[0][i] = 'R';
        dp5[0][i] = mat5[0][i] + dp5[0][i-1];
        path5[0][i] = 'R';
    }

    for(ll i=1; i<n; i++){
        for(ll j=1; j<n; j++){
            if(dp2[i-1][j] < dp2[i][j-1]){
                dp2[i][j] = mat2[i][j] + dp2[i-1][j];
                path2[i][j] = 'D';
            }
            else{
                dp2[i][j] = mat2[i][j] + dp2[i][j-1];
                path2[i][j] = 'R';
            }

            if(dp5[i-1][j] < dp5[i][j-1]){
                dp5[i][j] = mat5[i][j] + dp5[i-1][j];
                path5[i][j] = 'D';
            }
            else{
                dp5[i][j] = mat5[i][j] + dp5[i][j-1];
                path5[i][j] = 'R';
            }
        }
    }

    ll ans = min(dp2[n-1][n-1], dp5[n-1][n-1]);

    if(ans > 0 && zero == true){
        ll x = -1, y = -1;
        string str;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(mat[i][j] == 0){
                    x = i, y = j;
                    break;
                }
            }
            if(x != -1)
                break;
        }
        str += string(x, 'D') + string(y, 'R') + string(n-x-1, 'D') + string(n-y-1, 'R');
        cout << 1 << endl;
        cout << str << endl;
        return 0;
    }

    if(ans == dp2[n-1][n-1]){
        cout << ans << endl;
        string str;
        ll x = n-1, y = n-1;
        while(x+y != 0){
            str += path2[x][y];
            if(str.back() == 'R')
                y--;
            else
                x--;
        }
        reverse(all(str));
        cout << str << endl;
    }
    else{
        cout << ans << endl;
        string str;
        ll x = n-1, y = n-1;
        while(x+y != 0){
            str += path5[x][y];
            if(str.back() == 'R')
                y--;
            else
                x--;
        }
        reverse(all(str));
        cout << str << endl;
    }

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

