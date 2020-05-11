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

vi t;

void insert(ll v, ll tl, ll tr, ll pos){
    if(tl == tr){
        t[v]++;
        return;
    }
    ll tm = (tl+tr)/2;
    if(pos<=tm)
        insert(2*v, tl, tm, pos);
    else
        insert(2*v+1, tm+1, tr, pos);
    t[v] = t[2*v] + t[2*v+1];
}

ll counter(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)
        return 0;
    if(l==tl && r==tr)
        return t[v];
    ll tm = (tl+tr)/2;
    return counter(2*v, tl, tm, l, min(r, tm)) + counter(2*v+1, tm+1, tr, max(l, tm+1), r);
}

ll solve(){
    ll n;
    cin >> n;
    vi vec(n), left(n), right(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    vi tempvec = vec;
    sort(all(tempvec));
    tempvec.resize(distance(tempvec.begin(), unique(all(tempvec))));

    map<ll,ll> mapper;
    ll mpc = 0;
    for(ll i=0; i<tempvec.size(); i++)
        mapper[tempvec[i]] = mpc++;

    t.resize(4*mpc, 0);
    for(ll i=0; i<n; i++){
        ll m = mapper[vec[i]];
        left[i] = counter(1, 0, mpc-1, m+1, mpc-1);
        insert(1, 0, mpc-1, m);
    }
    t.assign(4*mpc, 0);
    for(ll i=n-1; i>=0; i--){
        ll m = mapper[vec[i]];
        right[i] = counter(1, 0, mpc-1, 0, m-1);
        insert(1, 0, mpc-1, m);
    }


    ll ans = 0;

    for(ll i=0; i<n; i++)
        ans += left[i] * right[i];
    cout << ans << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

