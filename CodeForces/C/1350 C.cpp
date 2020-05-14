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

vi sieve(1000000, 0), primes;

vi factorise(ll n){
    vi vec;
    while(n > 1)
        vec.pb(sieve[n]), n /= sieve[n];
    return vec;
}

void mult_foo(ll fac, ll m, vpii &mult){
    vi temp(3);
    temp[0] = mult[fac].ff, temp[1] = mult[fac].ss, temp[2] = m;
    sort(all(temp));
    mult[fac] = {temp[0], temp[1]};
}

ll power(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1)
            ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}

ll solve(){
    ll n;
    cin >> n;
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    vi count(200005, 0);
    vpii mult(200005, {LINF, LINF});
    for(ll i=0; i<n; i++){
        vi fac = factorise(vec[i]);
        map < ll, ll > cnt;
        for(ll f : fac)
            cnt[f]++;
        fac.resize(distance(fac.begin(), unique(all(fac))));
        for(ll f : fac)
            count[f]++;
        for(auto [key, value] : cnt)
            mult_foo(key, value, mult);
    }
    vi less, more;
    for(ll i=2; i<count.size(); i++){
        if(count[i] == n)
            more.pb(i);
        else if(count[i] == n-1)
            less.pb(i);
    }

    ll ans = 1;
    for(ll x : more)
        ans *= power(x, mult[x].ss);
    for(ll x : less)
        ans *= power(x, mult[x].ff);
    cout << ans << endl;

    return 0;
}


int main(){
    fastio;

    for(ll i=2; i<sieve.size(); i++){
        if(sieve[i] == 0){
            sieve[i] = i;
            primes.pb(i);
            for(ll j=i*i; j<sieve.size(); j+=i)
                if(sieve[j]==0)
                    sieve[j] = i;
        }
    }

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

