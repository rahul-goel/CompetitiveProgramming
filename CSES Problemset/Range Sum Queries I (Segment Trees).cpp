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

vi t, vec;

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        t[v] = vec[tl];
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm+1, tr);
    t[v] = t[v<<1] + t[v<<1|1];
}

ll query(ll v, ll tl, ll tr, ll ql, ll qr){
    if(ql<=tl && tr<=qr)
        return t[v];
    ll tm = (tl + tr) >> 1;
    ll value = 0;
    if(ql <= tm)
        value += query(v<<1, tl, tm, ql, qr);
    if(qr >= tm+1)
        value += query(v<<1|1, tm+1, tr, ql, qr);
    return value;
}

ll solve(){
    ll n, q;
    cin >> n >> q;
    t.resize(4*n), vec.resize(4*n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    build(1, 0, n-1);
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n-1, l, r) << endl;
    }
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

