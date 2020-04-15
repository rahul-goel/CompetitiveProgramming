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
#include <limits.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = LLONG_MAX;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
//#define pb push_back
#define f first
#define s second
#define mp make_pair

ll binsearch(vi &vec, ll value){
    ll start = 0, end = vec.size()-1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(vec[mid] <= value)
            start = mid + 1;
        else if(vec[mid] > value)
            end = mid - 1;
        else
            break;
    }
    return mid;
}

ll sq(ll x){
    return x*x;
}

ll solve(vi &a, vi &b, vi &c){
    ll ans = LINF;
    for(ll x : a){
        ll ind1 = binsearch(b, x);
        ll cur = LINF, ind2 = -1;
        for(ll i=max(0ll, ind1-1); i<=min((ll)b.size()-1, ind1+1); i++){
            if(sq(x - b[i]) < cur)
                ind2 = i, cur = sq(x - b[i]);
        }
        ll index = binsearch(c, b[ind2]);
        ll cur2 = LINF, ind3 = -1;
        for(ll i=max(0ll, index-1); i<=min((ll)c.size()-1, index+1); i++){
            if(sq(x - c[i]) < cur2)
                ind3 = i, cur2 = sq(x - c[i]);
        }
        ans = min(ans, sq(x-b[ind2]) + sq(x-c[ind3]) + sq(b[ind2]-c[ind3]));
    }
    return ans;
}

int main(){
    fastio;
    
    ll t;
    cin >> t;
    while(t--){
        ll r, g, b;
        cin >> r >> g >> b;
        vi rr(r), gg(g), bb(b);
        for(ll i=0; i<r; i++)
            cin >> rr[i];
        for(ll i=0; i<g; i++)
            cin >> gg[i];
        for(ll i=0; i<b; i++)
            cin >> bb[i];
        sort(all(rr)), sort(all(gg)), sort(all(bb));

        ll ans = LINF;
        ans = min(ans, solve(rr, gg, bb));
        ans = min(ans, solve(rr, bb, gg));
        ans = min(ans, solve(gg, rr, bb));
        ans = min(ans, solve(gg, bb, rr));
        ans = min(ans, solve(bb, rr, gg));
        ans = min(ans, solve(bb, gg, rr));
        cout << ans << endl;
        
    }
    return 0;
}
