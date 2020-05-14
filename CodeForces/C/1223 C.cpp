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
    ll n;
    cin >> n;
    vi vec(n), factor(n+1);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    ll x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    sort(all(vec), greater<ll>());
    ll start = 0, end = n, mid, pos = -1;
    if(y > x)
        swap(a, b), swap(x, y);
    ll lcm = a*b/__gcd(a, b);
    while(start <= end){
        mid = (start+end)/2;
        ll temp_ans = 0, ptr = 0;
    
        for(ll i=1; i<=mid; i++){
            if(i%(lcm)==0)
                temp_ans += vec[ptr++]*(x+y)/100;
        }
        for(ll i=1; i<=mid; i++){
            if(i%(lcm)!=0 && i%a==0)
                temp_ans += vec[ptr++]*(x)/100;
        }
        for(ll i=1; i<=mid; i++){
            if(i%(lcm)!=0 && i%b==0)
                temp_ans += vec[ptr++]*(y)/100;
        }

        if(temp_ans >= k)
            pos = mid, end = mid - 1;
        else
            start = mid + 1;
    }
    cout << pos << endl;

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

