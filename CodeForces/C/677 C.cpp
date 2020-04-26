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
            value = (value * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return value;
}

ll solve(){
    string str;
    cin >> str;
    vi vec(str.size());
    for(ll i=0; i<str.size(); i++){
        if(str[i] <= '9' && str[i] >= '0')
            vec[i] = 0 + str[i] - '0';
        else if(str[i] <= 'z' && str[i] >= 'a')
            vec[i] = 36 + str[i] - 'a';
        else if(str[i] <='Z' && str[i] >= 'A')
            vec[i] = 10 + str[i] - 'A';
        else if(str[i] == '-')
            vec[i] = 62;
        else
            vec[i] = 63;
    }

    ll ans = 1;

    for(ll i=0; i<str.size(); i++){
        ll count = 0, m = 6, x = vec[i];
        while(m--){
            if(x&1)
                count++;
            x>>=1;
        }
        ans = (ans * power(3, 6-count)) % mod;
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
