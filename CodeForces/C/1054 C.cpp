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
    vi vec(n), l(n), r(n);
    for(ll i=0; i<n; i++)
        cin >> l[i];
    for(ll i=0; i<n; i++)
        cin >> r[i];
    for(ll i=0; i<n; i++)
        vec[i] = n - l[i] - r[i];
    for(ll i=0; i<n; i++){
        ll count_left = 0, count_right = 0;
        for(ll x=i-1; x>=0; x--)
            if(vec[x] > vec[i])
                count_left++;
        for(ll y=i+1; y<n; y++)
            if(vec[y] > vec[i])
                count_right++;
        if(count_left != l[i] || count_right != r[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(ll u : vec)
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
