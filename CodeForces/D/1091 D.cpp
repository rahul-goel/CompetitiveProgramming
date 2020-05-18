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
ll mod = 998244353;
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

ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }
 
ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }

/*
    Code begins after this.
*/

ll fac[1000005] = {0};

ll factorial(ll n){
    if(n==1)
        return 1;
    if(fac[n])
        return fac[n];
    return fac[n] = mod_prod(n, factorial(n-1));
}

ll mod_inverse(ll n){
    ll x = n, y = mod - 2;
    ll ans = 1;
    while(y){
        if(y&1)
            ans = mod_prod(ans, x);
        y>>=1;
        x = mod_prod(x, x);
    }
    return ans;
}

ll solve(){
    ll n;
    cin >> n;
    ll ans = mod_prod(factorial(n), n);
    for(ll k=1; k<=n-1; k++)
        ans = mod_sum(ans, -(mod_prod(factorial(n), mod_inverse(factorial(k)))));
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

