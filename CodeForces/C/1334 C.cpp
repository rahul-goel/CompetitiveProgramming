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
const ll INF = 1e18;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
 
ll solve(){
    ll n, sum = 0;
    cin >> n;
    vi a(n+1), b(n+1), vec(n+1);
    for(ll i=1; i<=n; i++)
        cin >> a[i] >> b[i];
    if(n == 1){
        cout << a[1] << endl;
        return 0;
    }
    vec[1] = max(0ll, a[1]-b[n]);
    for(ll i=2; i<=n; i++)
        vec[i] = max(0ll, a[i]-b[i-1]);
    
    for(ll i=1; i<=n; i++)
        sum += vec[i];
    ll ans = INF;
    for(ll i=1; i<=n; i++)
        ans = min(ans, sum - vec[i] + a[i]);
 
    cout << ans << endl;
    return 0;
}
 
int main(){
    fastio;
    
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

