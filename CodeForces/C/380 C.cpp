/*
   Created by Rahul Goel.
*/

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

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define min_pq(t) priority_queue < t, vector < t >, greater < t > >
#define max_pq(t) priority_queue < t >
#define pb push_back
#define ff first
#define ss second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

// --------------------------------------------------------------

string str;
vi a, b, c;

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        a[v] = 0;
        if(str[tl] == '(')
            b[v] = 1;
        else
            c[v] = 1;
        return;
    }
    ll tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    ll t = min(b[2*v], c[2*v + 1]);
    a[v] = a[2*v] + a[2*v+1] + 2*t;
    b[v] = b[2*v] + b[2*v+1] - t;
    c[v] = c[2*v] + c[2*v+1] - t;
}

pair < ll, pii> query(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)
        return {0, {0, 0}};
    if(tl==l && tr==r)
        return {a[v], {b[v], c[v]}};
    ll tm = (tl+tr)/2;
    auto left = query(2*v, tl, tm, l, min(r, tm));
    auto right = query(2*v+1, tm+1, tr, max(l, tm+1), r);
    ll t = min(left.ss.ff, right.ss.ss);
    pair < ll, pii> ret;
    ret.ff = left.ff + right.ff + 2*t;
    ret.ss.ff = left.ss.ff + right.ss.ff - t;
    ret.ss.ss = left.ss.ss + right.ss.ss - t;
    return ret;
}

ll solve(){
    cin >> str;
    a.resize(str.size() * 4);
    b.resize(str.size() * 4);
    c.resize(str.size() * 4);
    
    build(1, 0, str.size()-1);

    ll n;
    cin >> n;
    while(n--){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, str.size()-1, l, r).ff << endl;
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

