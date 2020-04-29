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
    string str;
    cin >> str;
    ll ans = LINF;
    for(int j=0; j<=999999; j++){
        ll i = j;
        ll a = i%10 + i/10%10 + i/100%10;
        i/=1000;
        ll b = i%10 + i/10%10 + i/100%10;
        if(a==b){
            string str2 = to_string(j);
            while(str2.size()<6)
                str2 = "0" + str2;
            ll count = 0;
            for(ll k=0; k<6; k++)
                if(str[k]!=str2[k])
                    count++;
            ans = min(ans, count);
        }
    }
    cout << ans << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
