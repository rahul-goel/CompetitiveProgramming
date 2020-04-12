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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vvi magic(2, vi(2));

vvi mat_mult(vvi &a, vvi &b){
    vvi ans(2, vi(2, 0));

    for(ll i=0; i<2; i++)
        for(ll j=0; j<2; j++)
            for(ll k=0; k<2; k++)
                ans[i][j] = (ans[i][j] + (a[i][k]*b[k][j])%mod)%mod;
    return ans;
}

vvi power(vvi &a, ll n){
    vvi ans(2, vi(2));
    ans[0][0] = ans[1][1] = 1;
    ans[1][0] = ans[0][1] = 0;
    while(n){
        if(n&1)
            ans = mat_mult(ans, a);
        a = mat_mult(a, a);
        n>>=1;
    }
    return ans;
}

int solve(){
    magic[0][0] = magic[0][1] = magic[1][0] = 1;
    magic[1][1] = 0;

    ll n;
    cin >> n;
    vvi ans = power(magic, n+1);
    cout << ans[0][0] << endl;
    return 0;
}

int main(){
    fastio;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
