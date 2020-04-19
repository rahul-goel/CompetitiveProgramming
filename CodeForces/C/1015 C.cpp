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

bool cmp(pii &x, pii &y){
    return x.f-x.s < y.f-y.s;
}

ll solve(){
    ll n, m, sum = 0;
    cin >> n >> m;
    vpii vec;
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        sum += a;
        vec.pb({a, b});
    }
    sort(all(vec), cmp);
    
    ll y = sum - m;
    if(y <= 0){
        cout << 0 << endl;
        return 0;
    }
   
    ll count = 0;
    for(ll i=n-1; i>=0; i--){
        count++;
        y -= vec[i].f - vec[i].s;
        if(y<=0)
            break;
    }
    
    if(y>0)
        cout << -1 << endl;
    else
        cout << count << endl;

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
