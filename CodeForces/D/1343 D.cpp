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
    ll n, k;
    cin >> n >> k;
    vi vec(n+5), cnt(2*k+5, 0), prefix(2*k+5, 0);
    for(ll i=1; i<=n; i++)
        cin >> vec[i];
    for(ll i=1; i<=n/2; i++){
        cnt[vec[i] + vec[n-i+1]]++;
        ll low = min(vec[i], vec[n-i+1]) + 1;
        ll high = max(vec[i], vec[n-i+1]) + k;
        prefix[low] += 1, prefix[high + 1] -= 1;
    }

    for(ll i=1; i<(ll)prefix.size(); i++)
        prefix[i] += prefix[i-1];

    ll ans = LINF;
    for(ll i=2; i<=2*k; i++){
        ans = min(ans, prefix[i] - cnt[i] + (n/2 - prefix[i])*2);
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

