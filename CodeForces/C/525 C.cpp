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
    vi vec(n);
    vi count(1e6+5, 0);
    for(ll i=0; i<n; i++)
        cin >> vec[i], count[vec[i]]++;
    ll have = 0, prod = 1, sum=0;
    for(ll i=count.size()-1; i>=1; ){
        if(count[i] == 0)
            i--;
        else if(count[i] >= 2){
            if(have == 0)
                have += 2, prod = i;
            else if(have == 2)
                prod = prod*i, sum += prod, prod = 1, have = 0;
            count[i] -= 2;
        }
        else if(count[i] == 1 && count[i-1]){
            count[i]--, count[i-1]++;
            i--;
        }
        else if(count[i] <= 1)
            i--;
    }
    cout << sum << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
