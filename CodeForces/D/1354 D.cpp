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
#define aint(c)          (c).begin(), (c).end()
#define pii             pair < int, int >
#define vi              vector < int >
#define vb              vector < bool >
#define vvi             vector < vector < int > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < int, int > >
#define vvpii           vector < vector < pair < int, int > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aint(c),x) != (c).end())
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
int mod_sum() { return 0; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }
 
int mod_prod() { return 1; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
    Code begins after this.
*/

vi t, freq;

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = freq[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm+1, tr);
    t[v] = t[v<<1] + t[v<<1|1];
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] += val;
        return;
    }
    int tm = (tl+tr)>>1;
    if(pos<=tm)
        update(v<<1, tl, tm, pos, val);
    else
        update(v<<1|1, tm+1, tr, pos, val);
    t[v] = t[v<<1] + t[v<<1|1];
}

int query(int v, int tl, int tr, int rank){
    if(rank > t[v])
        return 0;
    if(tl == tr){
        return tl;
    }
    int tm = (tl+tr)>>1;
    if(rank > t[v<<1]){
        rank -= t[v<<1];
        return query(v<<1|1, tm+1, tr, rank);
    }
    return query(v<<1, tl, tm, rank);
}

int solve(){
    int n, q;
    cin >> n >> q;
    t.resize(4*(n+1)), freq.resize(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    build(1, 1, n);
    while(q--){
        int k;
        cin >> k;
        if(k > 0){
            update(1, 1, n, k, 1);
        }
        else{
            k = -k;
            int val = query(1, 1, n, k);
            update(1, 1, n, val, -1);
        }
    }
    cout << query(1, 1, n, 1) << endl;
    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

