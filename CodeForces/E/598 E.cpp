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


ll dp[31][31][51] = {0};

ll f(ll a, ll b, ll k){
    if(dp[a][b][k] || a*b==k || !k)
        return dp[a][b][k];
    ll value = LINF;
    for(ll i=1; i<=a-i; i++){
        for(ll j=0; j<=k; j++){
            value = min(value, b*b + f(i, b, j) + f(a-i, b, k-j));
        }
    }
    for(ll i=1; i<=b-i; i++){
        for(ll j=0; j<=k; j++){
            value = min(value, a*a + f(a, i, j) + f(a, b-i, k-j));
        }
    }
    return dp[a][b][k] = value;
}

ll solve(){
    ll N, M, K;
    cin >> N >> M >> K;
    cout << f(N, M, K) << endl;
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

