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
#define pb push_back
#define f first
#define s second
#define mp make_pair

vi sieve(1e5+5, 0);

vi factors(ll n){
    vi fac;
    while(sieve[n] != 0)
        fac.pb(sieve[n]), n /= sieve[n];
    fac.pb(n);
    sort(all(fac));
    fac.resize(distance(fac.begin(), unique(all(fac))));
    return fac;
}

ll solve(){
    ll n;
    cin >> n;
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    
    for(ll i=2; i<1e5+5; i++){
        if(sieve[i] == 0){
            for(ll j=i*i; j<1e5+5; j+=i){
                if(sieve[j] == 0)
                    sieve[j] = i;
            }
        }
    }

    vi count(1e5 + 5, 0);
    for(ll i=0; i<n; i++){
        vi fac = factors(vec[i]);
        for(ll foo : fac)
            count[foo]++;
    }

    ll mx = 1;
    for(ll i=2; i<1e5+5; i++)
        mx = max(count[i], mx);
    cout << mx << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
