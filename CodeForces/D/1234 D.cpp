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

struct node{
    ll dis;
    vi cnt;
};

vector < node > t;
string str;

void pull_up(ll v){
    for(ll i=0; i<26; i++)
        t[v].cnt[i] = t[v<<1].cnt[i] + t[v<<1|1].cnt[i];
    ll cc = 0;
    for(ll i=0; i<26; i++)
        if(t[v].cnt[i])
            cc++;
    t[v].dis = cc;
}

void merge_query(vi &a, vi &b, vi &c){
    for(ll i=0; i<26; i++)
        c[i] = a[i] + b[i];
}

void build(ll v, ll tl, ll tr){
    t[v].cnt.resize(26, 0);
    if(tl == tr){
        t[v].cnt[str[tl]]++;
        t[v].dis = 1;
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(v<<1, tl, tm);
    build(v<<1|1, tm+1, tr);
    pull_up(v);
}

void update(ll v, ll tl, ll tr, ll pos, char c){
    if(tl == tr){
        t[v].cnt.assign(26, 0);
        t[v].cnt[c]++;
        t[v].dis = 1;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(pos <= tm)
        update(v<<1, tl, tm, pos, c);
    else
        update(v<<1|1, tm+1, tr, pos, c);
    pull_up(v);
}

vi query(ll v, ll tl, ll tr, ll ql, ll qr){
    if(ql <= tl && tr <= qr) 
        return t[v].cnt;
    ll tm = (tl + tr) >> 1;
    vi a, b, c;
    a = b = c = vi(26, 0);
    if(ql <= tm)
        a = query(v<<1, tl, tm, ql, qr);
    if(tm+1 <= qr)
        b = query(v<<1|1, tm+1, tr, ql, qr);
    merge_query(a, b, c);
    return c;
}


ll solve(){
    
    cin >> str;
    ll n = str.size();
    t.resize(n*4);
    for(char &x : str)
        x -= 'a';
    build(1, 0, n-1);
    ll q;
    cin >> q;
    while(q--){
        ll choice;
        cin >> choice;
        if(choice == 1){
            ll pos;
            char c;
            cin >> pos >> c;
            update(1, 0, n-1, pos-1, c-'a');
        }
        else{
            ll l, r;
            cin >> l >> r;
            l--, r--;
            vi vec = query(1, 0, n-1, l, r);
            cout << 26 - count(all(vec), 0) << endl;
        }
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

