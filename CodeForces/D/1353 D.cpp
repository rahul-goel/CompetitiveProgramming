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

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define pii             pair < ll, ll >
#define vi              vector < ll >
#define vb              vector < bool >
#define vvi             vector < vector < ll > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < ll, ll > >
#define vvpii           vector < vector < pair < ll, ll > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

/*
    Code begins after this.
*/


class Compare
{
public:
    bool operator() (pii a, pii b)
    {
        if(a.ss-a.ff > b.ss-b.ff)
            return false;
        else if(a.ss-a.ff < b.ss-b.ff)
            return true;
        else
            return a.ff > b.ff;
    }
};

ll solve(){
    ll n;
    cin >> n;
    vi vec(n+1);
    std::priority_queue<pii, std::vector<pii>, Compare> pq;
    
    pq.push({1, n});
    ll cnt = 1;
    while(!pq.empty()){
        pii x = pq.top();
        pq.pop();
        if(x.ff>x.ss)
            continue;
        if((x.ss-x.ff+1)&1){
            vec[(x.ff+x.ss)/2] = cnt++; 
            pq.push({x.ff, (x.ff+x.ss)/2 - 1}); 
            pq.push({(x.ff+x.ss)/2 + 1, x.ss});
        }
        else{
            vec[(x.ff+x.ss-1)/2] = cnt++; 
            pq.push({x.ff, (x.ff+x.ss-1)/2 - 1}); 
            pq.push({(x.ff+x.ss-1)/2 + 1, x.ss});
        }
    }
        
    for(ll i=1; i<=n; i++)
        cout << vec[i] << " ";
    cout << endl;
    
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

