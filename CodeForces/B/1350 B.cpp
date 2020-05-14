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
vi sieve;

vi factors(ll n){
    vi vec;
    for(ll i=1, lim=sqrt(n); i<lim+2; i++)
        if(n%i == 0)
            vec.pb(i), vec.pb(n/i);
    vec.pb(1);
    sort(all(vec));
    return vec;
}

ll solve(){
    ll n;
    cin >> n;
    vi vec(n+1);
    for(ll i=1; i<=n; i++)
        cin >> vec[i];
    vi till_here(n+1);
    till_here[1] = 1;
    ll ans = 1;
    for(ll i=2; i<=n; i++){
        vi fac = factors(i);
        ll cur_ans = 1;
        for(ll f : fac){
            if(vec[i] > vec[f])
                cur_ans = max(cur_ans, till_here[f] + 1);
        }
        till_here[i] = cur_ans;
        ans = max(ans, cur_ans);
    }
    cout << ans << endl;
    return 0;
}


int main(){
    fastio;
/*
    for(ll i=2; i<sieve.size(); i++){
        if(sieve[i] == 0){
            sieve[i] = i;
            for(ll j=i*i; j<sieve.size(); j+=i)
                if(sieve[j]==0)
                    sieve[j] = i;
        }
    }
*/
    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

