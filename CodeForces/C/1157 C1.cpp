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
    deque < ll > dq;
    ll n;
    cin >> n;
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        dq.push_back(x);
    }
    string ans = "";
    ll mx = 0;

    while(!dq.empty()){
        if(dq.back() <= mx && dq.front() <= mx)
            break;
        if(dq.back() > mx && dq.front() > mx){
            if(dq.back() < dq.front()){
                ans += 'R';
                mx = dq.back();
                dq.pop_back();
            }
            else{
                ans += 'L';
                mx = dq.front();
                dq.pop_front();
            }
        }
        else if(dq.back() <= mx){
            ans += 'L';
            mx = dq.front();
            dq.pop_front();
        }
        else if(dq.front() <= mx){
            ans += 'R';
            mx = dq.back();
            dq.pop_back();
        }
    }
    cout << ans.size() << endl;
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

