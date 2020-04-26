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

ll solve(){
    string str;
    cin >> str;
    vvi vec(26);
    for(ll i=0; i<26; i++)
        vec[i].pb(-1);
    for(ll i=0; i<str.size(); i++){
        vec[str[i]-'a'].pb(i);
    }
    for(ll i=0; i<26; i++)
        vec[i].pb(str.size());
    ll ans = LINF;
    for(ll i=0; i<26; i++){
        ll mx = 0;
        for(ll j=1; j<vec[i].size(); j++)
            mx = max(mx, vec[i][j]-vec[i][j-1]);
        ans = min(mx, ans);
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
