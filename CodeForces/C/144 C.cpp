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
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
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


ll solve(){
    string str, p;
    cin >> str >> p;
    ll n = str.size(), pn = p.size();
    if(pn > n){
        cout << 0 << endl;
        return 0;
    }
    vvi vec(n, vi(128, 0));
    
    vec[0][str[0]] = 1;
    for(ll i=1; i<n; i++){
        for(ll j='a'; j<='z'; j++)
            vec[i][j] = vec[i-1][j];
        vec[i]['?'] = vec[i-1]['?'];
        vec[i][str[i]]++;
    }
    
    vi ap(128, 0);
    for(char x : p)
        ap[x]++;

    ll ans = 0;
    bool flag = true;
    ll diff = 0;
    for(ll j='a'; j<='z'; j++){
        if(ap[j] == vec[pn-1][j])
            continue;
        else if(ap[j] < vec[pn-1][j]){
            flag = false;
            break;
        }
        else
            diff += ap[j] - vec[pn-1][j];
    }
    if(flag && diff == vec[pn-1]['?'])
        ans++;

    for(ll i=pn; i<n; i++){
        flag = true;
        diff = 0;
        vi temp_vec(128, 0);
        for(ll j=0; j<128; j++)
            temp_vec[j] = vec[i][j] - vec[i-pn][j];

        for(ll j='a'; j<='z'; j++){
            if(ap[j] == temp_vec[j])
                continue;
            else if(ap[j] < temp_vec[j]){
                flag = false;
                break;
            }
            else
                diff += ap[j] - temp_vec[j];
        }
        if(flag && diff == temp_vec['?'])
            ans++;
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

