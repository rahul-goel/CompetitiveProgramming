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
const ll INF = 1000000000;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
    ll n, x;
    cin >> n >> x;
    vi vec(n);
    for(ll i=0; i<n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), greater < ll > ());
    ll i=0, sum = 0;
    while(i<n && vec[i]>x)
        sum += vec[i], i++;
    double avg = (double)sum/i;
    ll ans = i;

    while(i<n){
       sum += vec[i];
       avg = (double)sum/(i+1);
       if((ll)avg >= x)
           ans = i+1;
       else
           break;
       i++;
    }
    cout << ans << endl;
    return 0;
}

int main(){
    fastio;
    
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
