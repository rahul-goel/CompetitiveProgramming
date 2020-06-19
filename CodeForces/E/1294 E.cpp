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

void vecin(vi & vec, ll shift), vecout(vi & vec, ll shift);

/*
    Code begins after this.
*/


ll solve(){
    ll n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));
    for(ll i=0; i<n; i++)
        vecin(mat[i], -1);

    ll ans = 0;

    for(ll j=0; j<m; j++){
        vi cnt(n, 0);
        for(ll i=0; i<n; i++)
            if(mat[i][j]%m == j && mat[i][j]/m < n)
                cnt[(i - mat[i][j]/m + n)%n]++;
        ll temp_ans = n;
        for(ll i=0; i<n; i++)
            temp_ans = min(temp_ans, n-cnt[i]+i);
        ans += temp_ans;
    }

    cout << ans << endl;

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

void vecin(vi &vec, ll shift = 0){
    for(ll i=0; i<(ll)vec.size(); i++)
        cin >> vec[i], vec[i] += shift;
}

void vecout(vi &vec, ll shift = 0){
    for(ll i=0; i<(ll)vec.size(); i++)
        cout << vec[i] + shift << " ";
    cout << endl;
}
