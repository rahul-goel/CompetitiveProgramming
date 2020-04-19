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
    ll n, m;
    cin >> n >> m;
    vi vec(m+1, 0);
    
    while(n--){
        ll l, r;
        cin >> l >> r;
        for(ll i=l; i<=r; i++)
            vec[i] = 1;
    }
    
    cout << count(all(vec), 0) - 1 << endl;
    for(ll i=1; i<=m; i++)
        if(vec[i] == 0)
            cout << i << " ";
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
