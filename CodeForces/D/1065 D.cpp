/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
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
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/*
.-.. . -. -.- .- / .. ... / .-.. --- ...- . -.-.--
 */
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
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/

/*
    Code begins after this.
*/

vvi mat;
vpii pos;
vvpii dist;

ll hsh(ll x, ll y, ll p){
    return x * 3 * (ll)mat.size() + y * 3 + p;
}

bool valid(ll x, ll y){
    return (x >= 0 && x < (ll) mat.size()) && (y >= 0 && y < (ll) mat.size());
}

// 0 - knight
// 1 - bishop
// 2 - rook

vi dx = {1, 1, -1, -1, 2, 2, -2, -2};
vi dy = {2, -2, 2, -2, 1, -1, 1, -1};

pii operator + (const pii &a, const pii &b){
    return make_pair(a.ff + b.ff, a.ss + b.ss);
}

ll solve(){
    ll n;
    cin >> n;
    mat = vvi(n, vi(n));
    pos.resize(n * n);
    dist.resize(n * n * 3, vpii(n * n * 3, {LINF, LINF}));

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            cin >> mat[i][j], pos[--mat[i][j]] = {i, j};

    for(ll i = 0; i < (ll)dist.size(); i++)
        dist[i][i] = {0, 0};

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            // knight
            for(ll k = 0; k < 8; k++){
                ll x = i + dx[k];
                ll y = j + dy[k];

                if(valid(x, y))
                    dist[hsh(i, j, 0)][hsh(x, y, 0)] = {1, 0};
            }
            // bishop
            for(ll k = -n; k <= n; k++){
                for(ll l = -n; l <= n; l++){
                    if(llabs(k) != llabs(l))
                        continue;
                    ll x = i + k;
                    ll y = j + l;

                    if(valid(x, y))
                        dist[hsh(i, j, 1)][hsh(x, y, 1)] = {1, 0};
                }
            }
            //rook
            for(ll k = -n; k <= n; k++){
                ll x = i + k;
                ll y = j;

                if(valid(x, y))
                    dist[hsh(i, j, 2)][hsh(x, y, 2)] = {1, 0};
            }
            for(ll k = -n; k <= n; k++){
                ll x = i;
                ll y = j + k;

                if(valid(x, y))
                    dist[hsh(i, j, 2)][hsh(x, y, 2)] = {1, 0};
            }

            //piece change
            for(ll k = 0; k < 3; k++)
                for(ll l = 0; l < 3; l++)
                    if(k != l)
                        dist[hsh(i, j, k)][hsh(i, j, l)] = {1, 1};
        }
    }

    //floyd warshall
    for(ll k = 0; k < (ll)dist.size(); k++)
        for(ll i = 0; i < (ll)dist.size(); i++)
            for(ll j = 0; j < (ll)dist.size(); j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    vvpii dp(n * n, vpii(3, {LINF, LINF}));

    dp[0][0] = dp[0][1] = dp[0][2] = {0, 0};

    for(ll i = 1; i < n * n; i++)
        for(ll j = 0; j < 3; j++)
            for(ll k = 0; k < 3; k++)
                dp[i][k] = min(dp[i][k], dp[i - 1][j] + dist[hsh(pos[i - 1].ff, pos[i - 1].ss, j)][hsh(pos[i].ff, pos[i].ss, k)]);

    pii ans = min({dp[n * n - 1][0], dp[n * n - 1][1], dp[n * n - 1][2]});

    cout << ans.ff << " " << ans.ss << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

