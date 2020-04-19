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
    ll n, k, ss;
    cin >> n >> k >> ss;
    if(ss < k || (n-1) * k < ss){
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    ll where = 1;
    while(k){
        ll dist = min(n-1, ss+1-k);
        if(where - dist >= 1)
            where -= dist;
        else
            where += dist;
        cout << where << " ";
        ss -= dist;
        k--;
    }
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
