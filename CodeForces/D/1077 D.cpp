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
    ll n, k;
    cin >> n >> k;
    vi vec(n);
    ll occ[(ll)1e6] = {0};
    for(ll i=0; i<n; i++)
        cin >> vec[i], occ[vec[i]]++;
    
    vpii freq;
    for(ll i=0; i<1e6; i++){
        if(occ[i])
            freq.pb({occ[i], i});
    }
    sort(all(freq), greater<pii>());

    vi ans;
    ll start = 1, end = 200005, mid, pos = -1;
    while(start <= end){
        mid = (start + end)/2;
        vi temp_ans;
        ll count = 0;
        for(auto par : freq){
            ll fr = par.f, el = par.s;
            ll times = fr / mid;
            if(times){
                for(ll i=0; i<times; i++){
                    temp_ans.pb(par.s), count++;
                    if(count == k)
                        break;
                }
            }
            if(count == k)
                break;
        }
    
        if(count < k)
            end = mid - 1;
        else
            ans = temp_ans, start = mid + 1;
    }
    
    for(ll u : ans)
        cout << u << " ";
    cout << endl;

    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}
