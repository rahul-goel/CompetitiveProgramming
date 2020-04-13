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

int main(){
    fastio;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vi vec(n), diff(n);
        for(ll i=0; i<n; i++)
            cin >> vec[i];
        
        ll mn = vec[n-1];
        diff[n-1] = 0;
        for(ll i=n-2; i>=0; i--)
            diff[i] = max(0ll, vec[i]-mn), mn = min(mn, vec[i]);
        ll mx = 0;
        for(ll i=0; i<n; i++)
            mx = max(mx, diff[i]);
        ll bit = 0;
        while(mx)
            bit++, mx>>=1;
        cout << bit << endl;
    }
    return 0;
}
