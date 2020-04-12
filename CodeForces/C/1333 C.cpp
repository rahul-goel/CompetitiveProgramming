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
#include <map>
#include <set>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const ll INF = 1000000000;

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
    ll n;
    cin >> n;
    vi vec(n+1);
    for(ll i=1; i<=n; i++)
        cin >> vec[i];
    vec[0] = 0;
    for(ll i=1; i<=n; i++)
        vec[i] += vec[i-1];
    
    ll ans = 0, i = 1, j = 1;
    set < ll > ss;
    while(i<=n){
        ss.insert(vec[i-1]);
        while(j<=n && ss.count(vec[j])==0)
            ss.insert(vec[j]), j++;
        ans += j-i;
        ss.erase(vec[i-1]);
        i++;
        j = max(j, i);
    }
    cout << ans << endl;
    return 0;
}
