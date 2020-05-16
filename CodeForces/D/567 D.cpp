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
    ll n, k, a, m;
    cin >> n >> k >> a;
    set < ll > lll, rrr;
    lll.insert(1), rrr.insert(n);
    ll max_possible = (n-1+2)/(a+1);

    cin >> m;
    vi query(m);
    for(ll &x : query)
        cin >> x;
    ll ptr = 1;
    for(ll x : query){
        auto high = rrr.lower_bound(x);
        ll r = *high;
        auto low = --lll.upper_bound(x);
        ll l = *low;

        max_possible -= (r-l+2)/(a+1);
        lll.insert(l);
        rrr.insert(x-1);
        lll.insert(x+1);
        rrr.insert(r);
        if((x-1-l+1) >= a){
            max_possible += (x-1-l+2)/(a+1);
        }
        if((r-(x+1)+1) >= a){
            max_possible += (r-(x+1)+2)/(a+1);
        }
        if(max_possible < k){
            cout << ptr << endl;
            return 0;
        }
        ptr++;
    }
    cout << -1 << endl;
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

