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
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    multiset < ll > setter;
    ll mx = vec[0], mn = vec[0];
    ll ind = 0, ans = 1;
    setter.insert(vec[0]);
    for(ll i=1; i<n; i++){
        mn = min(vec[i], mn);
        mx = max(vec[i], mx);
        if(mx-mn<=1){
            setter.insert(vec[i]);
            ans = max(ans, (ll)setter.size());
            continue;
        }
        setter.insert(vec[i]);
        while(setter.size()>0 && mx-mn>1){
            auto it = setter.find(vec[ind]);
            setter.erase(it);
            ind++;
            auto it1 = setter.begin();
            auto it2 = setter.end();
            it2--;
            mn = *it1;
            mx = *it2;
        }
        ans = max(ans, (ll)setter.size());
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
