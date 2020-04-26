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
    vi vec(n+2);
    for(ll i=1; i<=n; i++)
        cin >> vec[i];
    string str;
    cin >> str;
    vi prefix_A(n+2), prefix_B(n+2), suffix_A(n+2), suffix_B(n+2);
    for(ll i=1; i<=n; i++){
        if(str[i-1] == 'A')
            prefix_A[i] = prefix_A[i-1] + vec[i], prefix_B[i] = prefix_B[i-1];
        else
            prefix_B[i] = prefix_B[i-1] + vec[i], prefix_A[i] = prefix_A[i-1];
    }
    for(ll i=n; i>=1; i--){
        if(str[i-1] == 'A')
            suffix_A[i] = suffix_A[i+1] + vec[i], suffix_B[i] = suffix_B[i+1];
        else
            suffix_B[i] = suffix_B[i+1] + vec[i], suffix_A[i] = suffix_A[i+1];
    }
    ll mx = 0;
    for(ll i=1; i<=n; i++){
        mx = max(mx, prefix_A[i] + suffix_B[i+1]);
        mx = max(mx, prefix_B[i] + suffix_A[i+1]);
    }

    cout << mx << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
