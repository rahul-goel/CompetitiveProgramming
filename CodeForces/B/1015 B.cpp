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

    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi asci1(128, 0), asci2(128, 0);
    for(ll i=0; i<n; i++)
        asci1[s[i]]++, asci2[t[i]]++;
    if(asci1 != asci2){
        cout << -1 << endl;
        return 0;
    }
    
    vi ans;

    for(ll i=0; i<n; i++){
        ll j = i;
        while(t[i] != s[j])
            j++;

        for(ll k=j-1; k>=i; k--){
            ans.pb(k);
            swap(s[k], s[k+1]);
        }
    }

    cout << ans.size() << endl;
    for(ll x : ans)
        cout << x+1 << " ";
    cout << endl;

    return 0;
}

int main(){
    fastio;
    
    ll t;
    t = 1;
    while(t--)
        solve();

    return 0;
}
