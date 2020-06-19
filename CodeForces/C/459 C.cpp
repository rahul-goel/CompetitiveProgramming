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

void vecin(vi & vec), vecout(vi & vec);

/*
    Code begins after this.
*/

void calc(vi &prev, vi &next, ll k){
    next = prev;
    ll i = next.size()-1;
    while(next[i] == k)
        next[i] = 1, i--;
    next[i]++;
}

ll solve(){
    ll n, k, d;
    cin >> n >> k >> d;

    bool flag = true;

    ll temp = 1;
    for(ll i=0; i<d; i++){
        temp *= k;
        if(temp >= n){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << -1 << endl;
        return 0;
    }

    vvi vec(n, vi(d));
    vec[0].assign(d, 1);
    for(ll i=1; i<n; i++)
        calc(vec[i-1], vec[i], k);

    vvi ans(d, vi(n));
    for(ll i=0; i<d; i++)
        for(ll j=0; j<n; j++)
            ans[i][j] = vec[j][i];

    for(ll i=0; i<d; i++)
        vecout(ans[i]);

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

void vecin(vi &vec){
    for(ll i=0; i<(ll)vec.size(); i++)
        cin >> vec[i];
}

void vecout(vi &vec){
    for(ll i=0; i<(ll)vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
