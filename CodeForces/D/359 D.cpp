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
#define pii             pair < int, int >
#define vi              vector < int >
#define vb              vector < bool >
#define vvi             vector < vector < int > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < int, int > >
#define vvpii           vector < vector < pair < int, int > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aint(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(aint(c))))
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

vi t, vec, m;

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = vec[tl];
        m[v] = vec[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm+1, tr);
    t[v] = __gcd(t[v<<1], t[v<<1|1]);
    m[v] = min(m[v<<1], m[v<<1|1]);
}

int query1(int v, int tl, int tr, int ql, int qr){
    if(ql <= tl && tr <= qr)
        return t[v];
    int tm = (tl + tr) >> 1;
    if(ql <= tm && qr <= tm)
        return query1(v<<1, tl, tm, ql, qr);
    else if(ql <= tm && tm+1 <= qr)
        return __gcd(query1(v<<1, tl, tm, ql, qr), query1(v<<1|1, tm+1, tr, ql, qr));
    else
        return query1(v<<1|1, tm+1, tr, ql, qr);
}

int rmq(int v, int tl, int tr, int ql, int qr){
    if(ql <= tl && tr <= qr)
        return m[v];
    int tm = (tl + tr) >> 1;
    int val = INF;
    if(ql <= tm)
        val = min(val, rmq(v<<1, tl, tm, ql, qr));
    if(tm+1 <= qr)
        val = min(val, rmq(v<<1|1, tm+1, tr, ql, qr));
    return val;
}


vi f(int range){
    vi v;
    for(int i=0; i+range<(int)vec.size(); i++){
        if(rmq(1, 0, vec.size()-1, i, i+range) == query1(1, 0, vec.size()-1, i, i+range)) 
            v.pb(i);
    }
    return v;
}

int solve(){
    int n;
    cin >> n;
    t = m = vi(n*4);
    vec = vi(n);
    
    for(int i=0; i<n; i++)
        cin >> vec[i];
    build(1, 0, n-1);
        
    vi ans;
    int ans_range;
    int start = 0, end = n-1, mid;
    while(start <= end){
        mid = (start+end)>>1;
        vi temp = f(mid);
        if(temp.size())
            ans = temp, ans_range = mid, start = mid + 1;
        else
            end = mid - 1;
    }
    cout << ans.size() << " " << ans_range << endl;
    for(int x : ans)
        cout << x+1 << " ";
    cout << endl;

    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

