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
using ll = long long;
using ld = long double;
ll mod = 1000000007;
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

vector < set < ll > > r, c;
queue < pii > q;
vvi dist;

void add(ll x, ll y, ll d){
    dist[x][y] = d+1;
    q.push({x, y});
    r[x].erase(y);
    c[y].erase(x);
}

ll solve(){
    ll n, m, k;
    ll x1, y1, x2, y2;

    cin >> n >> m >> k;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    r.resize(n), c.resize(m);

    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            r[i].insert(j);
    for(ll j=0; j<m; j++)
        for(ll i=0; i<n; i++)
            c[j].insert(i);

    vvi mat(n, vi(m));
    dist = vvi(n, vi(m, LINF));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            char x;
            cin >> x;
            mat[i][j] = (x == '.');
        }
    }

    add(x1, y1, -1);

    while(!q.empty()){
        ll x = q.front().ff, y = q.front().ss;
        ll d = dist[x][y];
        q.pop();
    
        if(x == x2 && y == y2){
            cout << d << endl;
            return 0;
        }
        
        auto it = r[x].lower_bound(y);
        while(it != r[x].end() && *it - y <= k && mat[x][*it])
            add(x, *it, d), it = r[x].lower_bound(y);

        it = r[x].lower_bound(y);
        while(it != r[x].begin() && y - *(--it) <= k && mat[x][*it])
            add(x, *it, d), it = r[x].lower_bound(y);

        it = c[y].lower_bound(x);
        while(it != c[y].end() && *it - x <= k && mat[*it][y])
            add(*it, y, d), it = c[y].lower_bound(x);

        it = c[y].lower_bound(x);
        while(it != c[y].begin() && x - *(--it) <= k && mat[*it][y])
            add(*it, y, d), it = c[y].lower_bound(x);
    }

    cout << -1 << endl;

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
