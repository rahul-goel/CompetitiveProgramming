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

#include <bits/stdc++.h>

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

ll gcd(ll a, ll b){
    if(!b)
        return a;
    return gcd(b, a%b);
}


vi t, g, vec;

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        t[v] = vec[tl];
        g[v] = vec[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = min(t[2*v], t[2*v+1]);
    g[v] = gcd(g[2*v], g[2*v+1]);
}

ll min_query(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)
        return LINF;
    if(l==tl && r==tr)
        return t[v];
    ll tm = (tl+tr)/2;
    return min(min_query(2*v, tl, tm, l, min(r, tm)), min_query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

ll gcd_query(ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || r < tl)
        return 0;
    if(l <= tl && tr <= r)
        return g[v];
    ll tm = (tl+tr)/2;
    return gcd(gcd_query(2*v, tl, tm, l, r), gcd_query(2*v+1, tm+1, tr, l, r));
}

vpii store;

ll solve(){
    ll n;
    cin >> n;
    vec.resize(n), t.resize(n*4), g.resize(n*4);
    for(ll i=0; i<n; i++)
        cin >> vec[i], store.pb({vec[i], i});
    sort(all(store));

    build(1, 0, n-1);
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll gcdd = gcd_query(1, 0, n-1, l, r);
        ll minn = min_query(1, 0, n-1, l, r);
        if(gcdd == minn){
    
            ll low = lower_bound(all(store), make_pair(minn, l)) - store.begin();
            ll high = upper_bound(all(store), make_pair(minn, r)) - store.begin();
            cout << r-l+1 - (high-low) << endl;
        }
        else
            cout << r-l+1 << endl;
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
