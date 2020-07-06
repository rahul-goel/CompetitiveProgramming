/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
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
const ll mod = 1000000007;
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

    vi fac(20);
    fac[0] = 1;
    for(ll i = 1; i < 20; i++)
        fac[i] = (i * fac[i - 1]);

    string str;
    cin >> str;

    string check = str;
    sort(all(check));
    uniq(check);

    ll ans = 0;

    set < string > done;

    for(ll mask = 1; mask < (1 << str.size()); mask++){
        string s;
        for(ll i = 0; i < (ll) str.size(); i++)
            if(mask & (1 << i))
                s.push_back(str[i]);

        string scheck = s;
        sort(all(scheck));
        uniq(scheck);
        if(scheck != check)
            continue;

        sort(all(s));
        if(present(done, s))
            continue;
        done.insert(s);

        vi cnt(10);
        for(char x : s)
            cnt[x - '0']++;

        ll temp_ans = fac[s.size()];
        for(ll x : cnt)
            temp_ans /= fac[x];
        ans += temp_ans;
    
        if(cnt[0]){
            cnt[0]--;
            s.erase(find(all(s), '0'));
            temp_ans = fac[s.size()];
            for(ll x : cnt)
                temp_ans /= fac[x];
            ans -= temp_ans;
        }

    }

    cout << ans << endl;

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

