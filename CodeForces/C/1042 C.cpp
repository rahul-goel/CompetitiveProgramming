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


ll solve(){
    ll n;
    cin >> n;
    set < pii > s, l, z;
    ll neg = 0, mx = -LINF;
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        s.insert({x, i});
        if(x==0)
            z.insert({x, i});
        if(x<0)
            l.insert({x, i}), neg++, mx = max(mx, x);
    }

    if(neg%2==1){
        while(z.size()>1){
            auto it1 = z.begin(), it2 = --z.end();
            cout << 1 << " " << it1->ss << " " << it2->ss << endl;
            s.erase(*it1);
            z.erase(*it1);
        }
        if(s.size() <= 1)
            return 0;
        if(z.size()){
            auto iz = z.begin(), il = --l.end();
            cout << 1 << " " << iz->ss << " " << il->ss << endl;
            s.erase(*iz);
            z.erase(*iz);

            if(s.size() == 1){
                return 0;
            }

            cout << 2 << " " << il->ss << endl;
            s.erase(*il);
            l.erase(*il);
        }
        else{
            auto il = --l.end();
            cout << 2 << " " << il->ss << endl;
            s.erase(*il);
            l.erase(*il);
        }
        if(s.size() <= 1)
            return 0;
        while(s.size()>1){
            auto is1 = s.begin(), is2 = --s.end();
            cout << 1 << " " << is1->ss << " " << is2->ss << endl;
            s.erase(is1);
        }
    }
    else{
        while(z.size()>1){
            auto it1 = z.begin(), it2 = --z.end();
            cout << 1 << " " << it1->ss << " " << it2->ss << endl;
            s.erase(*it1);
            z.erase(*it1);
        }
        if(s.size() <= 1)
            return 0;
        if(z.size()){
            if(s.size() <= 1)
                return 0;
            auto iz = z.begin();
            cout << 2 << " " << iz->ss << endl;
            z.erase(*iz);
            s.erase(*iz);
        }
        while(s.size()>1){
            auto is1 = s.begin(), is2 = --s.end();
            cout << 1 << " " << is1->ss << " " << is2->ss << endl;
            s.erase(is1);
        }
    }
    return 0;
}


int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

