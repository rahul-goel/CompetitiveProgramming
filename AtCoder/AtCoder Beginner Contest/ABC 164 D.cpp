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

ll power(ll x, ll y){
    ll value = 1;
    while(y){
        if(y&1)
            value = (value * x) % 2019;
        y >>= 1;
        x = (x * x) % 2019;
    }
    return value;
}


ll solve(){
    string str;
    cin >> str;
    reverse(all(str));
        
    vi vec(str.size() + 1, 0);
    for(ll i=1; i<=str.size(); i++)
        vec[i] = (vec[i-1] + (str[i-1]-'0')*power(10, i-1)) % 2019;
    ll count[2019] = {0};
    for(ll u : vec)
        count[u]++;

    ll ans = 0;
    for(ll i=0; i<2019; i++)
        ans += count[i]*(count[i]-1)/2;
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
