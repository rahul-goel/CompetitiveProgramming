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
ll mod = 998244353;
const int INF = 1000000000;

#define pii pair < int, int >
#define vi vector < int >
#define vvi vector < vector < int > >
#define vpii vector < pair < int, int > >
#define vvpii vector < vector < pair < int, int > > >
#define pb push_back
#define f first
#define s second
#define mp make_pair

ll power(ll x, ll y){
    ll value = 1;
    while(y){
        if(y&1){
            value = (value*x)%mod;
        }
        x = (x*x)%mod;
        y>>=1;
    }
    return value;
}

int main(){
    ll n;
    cin >> n;

    for(ll i=1; i<=n-2; i++){
        ll ans = (((power(10, n-i-2)*9*9*10)%mod)*(n-i-1))%mod;
        ans = (ans + (power(10, n-i-1)*9*10*2)%mod)%mod;
        cout << ans << " ";
    }
    if(n>=2)
        cout << ((power(10, 0)*9*10)*2)%mod << " ";
    cout << 10 << endl;
    return 0;
}
