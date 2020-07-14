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


void count_sort(vi &suf, vi &cls){
    ll n = suf.size();
    vi cnt(n);

    for(auto x : cls)
        cnt[x]++;
    vi pos(n), suf_new(n);
    pos[0] = 0;
    for(ll i=1; i<n; i++)
        pos[i] = pos[i-1] + cnt[i-1];
    for(auto x : suf){
        ll i = cls[x];
        suf_new[pos[i]] = x;
        pos[i]++;
    }
    suf = suf_new;
}

ll solve(){
    string str;
    cin >> str;
    str += "$";

    ll n = str.size();
    vi suf(n), cls(n);

    {
        vpii a(n);
        for(ll i=0; i<n; i++)
            a[i] = {str[i], i};
        sort(all(a));
        for(ll i=0; i<n; i++)
            suf[i] = a[i].ss;
        cls[suf[0]] = 0;
        for(ll i=1; i<n; i++){
            if(a[i].ff == a[i-1].ff)
                cls[suf[i]] = cls[suf[i-1]];
            else
                cls[suf[i]] = cls[suf[i-1]] + 1;
        }
    }

    ll k = 0;
    while((1<<k) < n){
        for(ll i=0; i<n; i++)
            suf[i] = (suf[i] - (1<<k) + n)%n;

        count_sort(suf, cls);
        vi cls_new(n);
        cls_new[suf[0]] = 0;
        for(ll i=1; i<n; i++){
            pii prev = {cls[suf[i-1]], cls[(suf[i-1] + (1<<k))%n]};
            pii now = {cls[suf[i]], cls[(suf[i] + (1<<k))%n]};
            if(prev == now)
                cls_new[suf[i]] = cls_new[suf[i-1]];
            else
                cls_new[suf[i]] = cls_new[suf[i-1]] + 1;
        }
        cls = cls_new;
        k++;
    }

    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;

        ll start = 0, end = suf.size()-1;
        for(ll i=0; i<(ll)s.size(); i++){
            ll lo = start, hi = end, mid, snext = -1, enext = -1;
            while(lo <= hi){
                mid = (lo + hi) >> 1;
                if(str[(suf[mid] + i)%n] < s[i])
                    lo = mid + 1;
                else if(str[(suf[mid] + i)%n] == s[i])
                    snext = mid, hi = mid - 1;
                else
                    hi = mid - 1;
            }
            lo = start, hi = end;
            while(lo <= hi){
                mid = (lo + hi) >> 1;
                if(str[(suf[mid] + i)%n] < s[i])
                    lo = mid + 1;
                else if(str[(suf[mid] + i)%n] == s[i])
                    enext = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            start = snext, end = enext;
            if(start == -1 || enext == -1)
                break;
        }

        if(start == -1 || end == -1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

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

