/*
   Created by Rahul Goel.
*/
/*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
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

const int NIL = -1;

struct node{
   int count;
   int child[26];
   node(){
       count = 0;
       memset(child, NIL, sizeof(child));
   }
};

vector < node > dataaa;

void insert_word(int head, string str){
    int cur = head;
    for(int i=0; i<(int)str.size(); i++){
        int child_index = str[i] - 'a';
        if(dataaa[cur].child[child_index] == NIL){
            dataaa[cur].child[child_index] = dataaa.size();
            dataaa.push_back(node());
        }
        cur = dataaa[cur].child[child_index];
        dataaa[cur].count++;
    }
}

int find_word(int head, string str){
    int cur = head;
    for(int i=0; i<(int)str.size(); i++){
        int child_index = str[i] - 'a';
        if(dataaa[cur].child[child_index] == NIL)
            return 0;
        cur = dataaa[cur].child[child_index];
    }
    return dataaa[cur].count;
}

ll solve(){
    dataaa.pb(node());

    string str;
    cin >> str;
    string valid;
    cin >> valid;
    vi asci(128);
    for(ll i = 'a'; i <= 'z'; i++)
        asci[i] = valid[i - 'a'] - '0';

    ll k;
    cin >> k;
    ll ans = 0;

    for(ll i = 0; i < (ll)str.size(); i++){
        ll bad = 0;
        string s = str.substr(i);
        int cur = 0;
        for(ll j = 0; j < (ll)s.size(); j++){
            if(!asci[s[j]])
                bad++;
            if(bad > k)
                break;
            int child_index = s[j] - 'a';
            if(dataaa[cur].child[child_index] == NIL){
                ans++;
                dataaa[cur].child[child_index] = dataaa.size();
                dataaa.push_back(node());
            }
            cur = dataaa[cur].child[child_index];
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

