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

ll n, m, k, s;
vi a, b, d, e;

bool f(ll ind){
    ll mna = LINF, mnb = LINF;
    for(ll i=0; i<ind; i++)
        mna = min(mna, a[i]), mnb = min(mnb, b[i]);

    ll have = 0, cost = 0, mncost = LINF;
    ll dp = 0, ep = 0;

    for(ll i=0; have < k && i < (ll)d.size(); i++)
        have++, cost += d[i]*mna, dp++;
    for(ll i=0; have < k && i < (ll)e.size(); i++)
        have++, cost += e[i]*mnb, ep++;

    mncost = min(mncost, cost);
    while(dp > 0 && ep < (ll)e.size()){
        cost -= d[dp-1]*mna;
        cost += e[ep]*mnb;
        dp--, ep++;
        mncost = min(mncost, cost);
    }

    return mncost <= s;
}

vi ff(ll ind){
    ll mna = LINF, mnb = LINF;
    for(ll i=0; i<ind; i++)
        mna = min(mna, a[i]), mnb = min(mnb, b[i]);

    ll ai = -1, bi = -1;
    for(ll i=0; i<ind; i++)
        if(a[i] == mna)
            ai = i;
    for(ll i=0; i<ind; i++)
        if(b[i] == mnb)
            bi = i;

    ll have = 0, cost = 0, mncost = LINF;
    ll dp = 0, ep = 0;

    for(ll i=0; have < k && i < (ll)d.size(); i++)
        have++, cost += d[i]*mna, dp++;
    for(ll i=0; have < k && i < (ll)e.size(); i++)
        have++, cost += e[i]*mnb, ep++;

    mncost = min(mncost, cost);
    while(dp > 0 && ep < (ll)e.size()){
        cost -= d[dp-1]*mna;
        cost += e[ep]*mnb;
        dp--, ep++;
        mncost = min(mncost, cost);
    }

    have = 0, cost = 0;
    dp = 0, ep = 0;

    for(ll i=0; have < k && i < (ll)d.size(); i++)
        have++, cost += d[i]*mna, dp++;
    for(ll i=0; have < k && i < (ll)e.size(); i++)
        have++, cost += e[i]*mnb, ep++;

    if(cost == mncost){
        return {ai+1, bi+1, dp, ep};
    }


    while(dp > 0 && ep < (ll)e.size()){
        cost -= d[dp-1]*mna;
        cost += e[ep]*mnb;
        dp--, ep++;
        if(cost == mncost){
            return {ai+1, bi+1, dp, ep};
        }
    }

    return {ai+1, bi+1, dp, ep};
}

ll solve(){
    cin >> n >> m >> k >> s;
    a = b = vi(n);

    vpii dd, ee;

    for(ll i=0; i<n; i++)
        cin >> a[i];
    for(ll i=0; i<n; i++)
        cin >> b[i];

    for(ll i=0; i<m; i++){
        ll t, c;
        cin >> t >> c;
        if(t == 1)
            d.pb(c), dd.pb({c, i+1});
        else
            e.pb(c), ee.pb({c, i+1});
    }

    sort(all(d)), sort(all(e));
    sort(all(dd)), sort(all(ee));

    ll start = 1, end = n, mid, pos = -1;
    while(start <= end){
        mid = (start + end) >> 1;
        if(f(mid))
            pos = mid, end = mid - 1;
        else
            start = mid + 1;
    }

    if(pos == -1){
        cout << -1 << endl;
        return 0;
    }

    vi data = ff(pos);
    cout << pos << endl;
    for(ll i=0; i<data[2]; i++)
        cout << dd[i].ss << " " << data[0] << endl;
    for(ll i=0; i<data[3]; i++)
        cout << ee[i].ss << " " << data[1] << endl;

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

