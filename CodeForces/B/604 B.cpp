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
    ll n, k;
    cin >> n >> k;
    vi vec(n);
    ll mx = 0;
    for(ll i=0; i<n; i++)
        cin >> vec[i], mx = max(mx, vec[i]);
    if(k >= n){
        cout << mx << endl;
        return 0;
    }
    
    ll mx_box = 0;
    for(ll i=n-1; i>=2*n-2*k; i--){
        mx_box = max(mx_box, vec[i]);
    }
    for(ll i=0, j = 2*n-2*k-1; i<=j; i++, j--){
        if(i == j)
            mx_box = max(mx_box, vec[i]);
        else
            mx_box = max(mx_box, vec[i] + vec[j]);
    }

    cout << mx_box << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
