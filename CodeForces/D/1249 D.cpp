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
using ll = long long;
using ld = long double;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
/*
.-.. . -. -.- .- / .. ... / .-.. --- ...- . -.-.--
 */
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
ll mod_sum() { return 0LL; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1LL; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c)          (c).begin(), (c).end()
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(all(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/

/*
    Code begins after this.
*/


ll solve(){
    ll n, k;
    cin >> n >> k;

    vpii segs(n);
    vi cnt(200005);
    vvi track(200005);

    for(ll i = 0; i < n; i++){
        cin >> segs[i].ff >> segs[i].ss;

        cnt[segs[i].ff] += 1;
        cnt[segs[i].ss + 1] -= 1;

        track[segs[i].ff].pb(i + 1);
        track[segs[i].ss + 1].pb(-i - 1);
    }

    for(ll i = 1; i < 200005; i++)
        cnt[i] += cnt[i - 1];

    vi ans(200005), sub(200005);
    set < pii > cur;
    ll rmv = 0;

    for(ll i = 0; i < 200005; i++){
        rmv += sub[i];
        for(auto ind : track[i]){
            if(ind > 0){
                cur.insert({segs[ind - 1].ss, ind - 1});
            }
            else{
                if(present(cur, make_pair(segs[-ind - 1].ss, -ind - 1)))
                    cur.erase(make_pair(segs[-ind - 1].ss, -ind - 1));
            }
        }

        while(cnt[i] - rmv > k){
            ll pos = (*--cur.end()).ss;
            cur.erase(--cur.end());
            rmv++;
            sub[segs[pos].ss + 1]--;
            ans[pos] = 1;
        }
    }

    ll sum = 0;
    for(ll i = 0; i < 200005; i++)
        if(ans[i])
            sum++;
    cout << sum << endl;
    for(ll i = 0; i < 200005; i++)
        if(ans[i])
            cout << i + 1 << " ";
    cout << endl;

    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

