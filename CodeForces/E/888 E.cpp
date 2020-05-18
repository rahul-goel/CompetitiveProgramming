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
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i], vec[i]%=m;
    vi sums1, sums2;
    ll f = n/2, s = n-f;
    vi first_half, second_half;
    for(ll i=0; i<f; i++)
        first_half.pb(vec[i]);
    for(ll i=f; i<n; i++)
        second_half.pb(vec[i]);
    //first-half
    for(ll i=0; i<(1<<f); i++){
        ll cur_sum = 0;
        for(ll j=0; j<f; j++)
            if(i&(1<<j))
                cur_sum += first_half[j], cur_sum%=m;
        sums1.pb(cur_sum); 
    }

    //second-half
    for(ll i=0; i<(1<<s); i++){
        ll cur_sum = 0;
        for(ll j=0; j<s; j++)
            if(i&(1<<j))
                cur_sum += second_half[j], cur_sum%=m;
        sums2.pb(cur_sum); 
    }

    sort(all(sums1));
    ll ans = 0;
    ans = max(ans, *max_element(all(sums1)));
    for(ll x : sums2){
        ans = max(ans, x);
        auto low = lower_bound(all(sums1), m-x);
        if(low != sums1.begin())
            ans = max(ans, x + *--low);
    }
        
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

