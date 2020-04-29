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
    vvi mat(n, vi(m));
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            cin >> mat[i][j];

    ll value = 0;
    vi ans(n);
    for(ll i=0; i<n; i++)
        value ^= mat[i][0], ans[i]=0;
    if(value > 0){
        cout << "TAK" << endl;
        for(ll x : ans)
            cout << x+1 << " ";
        cout << endl;
        return 0;
    }

    for(ll i=0; i<n; i++){
        for(ll j=1; j<m; j++){
            if(mat[i][j] != mat[i][j-1]){
                ans[i] = j;
                cout << "TAK" << endl;
                for(ll x : ans)
                    cout << x+1 << " ";
                cout << endl;
                return 0;
            }
        }
    }
        
    cout << "NIE" << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
