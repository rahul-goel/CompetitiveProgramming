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
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

/*
    Code begins after this.
*/

ll n, a, r, m;
vi vec;

ll f(ll h){
    ll add = 0, remove = 0;
    for(ll &x : vec){
        if(x > h)
            remove += x-h;
        else if(x < h)
            add += h-x;
    }
    ll cost = 0;
    if(m < a+r){
        ll move = min(add, remove);
        add -= move, remove -= move;
        cost += m*move + a*add + r*remove;
    }
    else{
        cost += a*add + r*remove;
    }
    return cost;
}

ll solve(){
    cin >> n >> a >> r >> m;
    vec.resize(n);
    for(ll &x : vec)
        cin >> x;

    ll low = -1, high = mod;
    while(high-low>1){
        ll mid = (high+low)>>1;
        if(f(mid) < f(mid + 1))
            high = mid;
        else
            low = mid;
    }
    
    cout << f(low+1) << endl;

    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

