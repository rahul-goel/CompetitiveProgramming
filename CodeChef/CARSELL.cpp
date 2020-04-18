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

int solve(){
    ll n;
    cin >> n;
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    sort(all(vec), greater < ll > ());
    ll ans = 0;
    for(ll i=0; i<n; i++)
        ans = (ans + max(vec[i] - i, 0ll))%mod;
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
