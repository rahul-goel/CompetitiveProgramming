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


ll solve(){
    ll n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            cin >> a[i][j];

    ll ans = LINF;
    ll orig = a[0][0];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            a[0][0] = a[i][j] - i - j;
            if(a[0][0] > orig)
                continue;
            vvi dp(n, vi(m, LINF));
            dp[0][0] = orig - a[0][0];
            for(ll x=0; x<n; x++){
                for(ll y=0; y<m; y++){
                    ll newh = a[0][0] + x + y;
                    if(newh > a[x][y])
                        continue;
                    if(x > 0)
                        dp[x][y] = min(dp[x][y], dp[x-1][y] + a[x][y] - newh);
                    if(y > 0)
                        dp[x][y] = min(dp[x][y], dp[x][y-1] + a[x][y] - newh);
                }
            }
            ans = min(ans, dp[n-1][m-1]);
        }
    }
    
    cout << ans << endl;

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

