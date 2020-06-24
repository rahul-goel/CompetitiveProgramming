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
    ll n;
    cin >> n;
    string str, ans = "";
    cin >> str;

    if(count(all(str), '0') == 0 || count(all(str), '1') == 0){
        cout << str << endl;
        return 0;
    }

    string temp;
    for(ll i=0; i<n; ){
        ll j = i;
        while(j < n && str[j] == str[i])
            j++;
        temp += str[i];
        i = j;
    }

    if(temp == "01"){
        cout << str << endl;
        return 0;
    }
    else if(temp == "10"){
        cout << "0" << endl;
        return 0;
    }

    if(temp.front() == '0' && temp.back() == '1'){
        string ans;
        ll i=0;
        while(str[i] == '0')
            ans += '0', i++;
        string one = "";
        i = n-1;
        while(str[i] == '1')
            one += '1', i--;
        cout << ans + "0" + one << endl;
    }
    else if(temp.front() == '1' && temp.back() == '1'){
        string one = "";
        ll i = n-1;
        while(str[i] == '1')
            one += '1', i--;
        cout << "0" + one << endl;
    }
    else if(temp.front() == '1' && temp.back() == '0'){
        cout << "0" << endl;
    }
    else{
        string ans;
        ll i=0;
        while(str[i] == '0')
            ans += '0', i++;
        cout << ans + "0" << endl;
    }


    return 0;
}


signed main(){
    fastio;

    ll t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.
