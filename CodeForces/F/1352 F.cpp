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
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define min_pq(t) priority_queue < t, vector < t >, greater < t > >
#define max_pq(t) priority_queue < t >
#define pb push_back
#define ff first
#define ss second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

// --------------------------------------------------------------

ll solve(){
    string str = "";
    ll n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    if(n1 == 0){
        if(n2==0){
            for(ll i=0; i<=n0; i++)
                str += '0';
            cout << str << endl;
            return 0;
        }
        else if(n0 == 0){
            for(ll i=0; i<=n2; i++)
                str += '1';
            cout << str << endl;
            return 0;
        }
    }

    for(ll i=0, j = 0; i<=n1; i++, j^=1)
        str += '0' + j;
    string str0 = "";
    for(ll i=0; i<n0; i++)
        str0 += '0';
    str = str0 + str;
    
    if(str.back() == '1'){
        for(ll i=0; i<n2; i++)
            str += '1';
    }
    else{
        str.pop_back();
        for(ll i=0; i<n2; i++)
            str += '1';
        str.pb('0');
    }
    cout << str << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

