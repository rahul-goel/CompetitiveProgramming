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
    vvi occ(1e6 + 5);

    vi vec(n), ans;
    ll sum = 0;
    for(ll i=0; i<n; i++){
        cin >> vec[i], occ[vec[i]].pb(i+1), sum += vec[i];
    }
    for(ll i=0; i<n; i++){
        ll x = sum - vec[i];
        if(x - vec[i] < 0 || x - vec[i] > 1000000 + 4)
            continue;
        if(occ[x - vec[i]].size() > 0){
            for(ll u : occ[x - vec[i]])
                if(u != i+1)
                    ans.pb(u);
        }
    }
    
    sort(all(ans));
    auto it = unique(all(ans));
    ans.resize(distance(ans.begin(), it));

    cout << ans.size() << endl;
    for(ll u : ans)
        cout << u <<  " ";
    cout << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
