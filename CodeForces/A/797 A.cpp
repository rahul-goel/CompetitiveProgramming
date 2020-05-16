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

vi sieve(1e5+5);

ll solve(){
    ll n, k;
    cin >> n >> k;
    vi fac;
    while(n>1){
        fac.pb(sieve[n]);
        n /= sieve[n];
    }
    if(fac.size() < k)
        cout << -1 << endl;
    else{
        for(ll i=0; i<k-1; i++)
            cout << fac[i] << " ";
        ll fi = 1;
        for(ll i=k-1; i<fac.size(); i++)
            fi *= fac[i];
        cout << fi << endl;
    }
    return 0;
}


int main(){
    fastio;
    
    for(ll i=2; i<sieve.size(); i++){
        if(sieve[i]==0){
            sieve[i] = i;
            for(ll j=i*i; j<sieve.size(); j+=i)
                if(sieve[j] == 0)
                    sieve[j] = i;
        }
    }

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

