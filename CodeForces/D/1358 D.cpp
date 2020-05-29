/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
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
/*******************************************************************************/
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/* For PBDS */
/*Two new methods X.order_of_key() and X.find_by_order()*/
/*
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

/*******************************************************************************/
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
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
    Code begins after this.
*/

vi prefix_sums(1e6 + 5);


ll solve(){
    
    prefix_sums[0] = 0;
    for(ll i=1; i<(ll)prefix_sums.size(); i++)
        prefix_sums[i] = prefix_sums[i-1] + i;
    

    ll n, x;
    cin >> n >> x;
    vi vec(n+5, 0), suf(n+5, 0), values(n+5, 0);
    for(ll i=1; i<=n; i++)
        cin >> vec[i], values[i] = vec[i] * (vec[i] + 1) / 2;
    for(ll i=n; i>0; i--)
        suf[i] = suf[i+1] + vec[i], values[i] += values[i+1];
    ll ans = 0;
    for(ll i=n; i>0; i--){
        ll rem = x;
        ll search = suf[i+1] + rem;
        ll start = 1, end = i, mid, pos = -1;
        while(start <= end){
            mid = (start + end) >> 1;
            if(suf[mid] > search)
                start = mid + 1;
            else
                pos = mid, end = mid - 1;
        }
        if(pos == -1){
            ll temp_ans = prefix_sums[vec[i]] - prefix_sums[vec[i] - rem];
            ans = max(ans, temp_ans);
            continue;
        }
        // the pos value now has either till x or less than it
        rem -= suf[pos] - suf[i+1];
        ll temp_ans = values[pos] - values[i+1];
        if(rem > 0){
            if(pos == 1){
                search = suf[n+1] + rem;
                start = 1, end = n, pos = -1;
                while(start <= end){
                    mid = (start + end) >> 1;
                    if(suf[mid] > search)
                        start = mid + 1;
                    else
                        pos = mid, end = mid - 1;
                }
                if(pos == -1){
                    temp_ans += prefix_sums[vec[n]] - prefix_sums[vec[n] - rem];
                    ans = max(ans, temp_ans);
                    continue;
                }
                rem -= suf[pos] - suf[n+1];
                temp_ans += values[pos] - values[n+1];
            }
            temp_ans += prefix_sums[vec[pos-1]] - prefix_sums[vec[pos-1] - rem];
        }
        ans = max(ans, temp_ans);
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

