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
using pii = pair < int, int >;
using vi = vector < int >;
using vb = vector < bool >;
using vvi = vector < vector < int > >;
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

vi sieve(3000005);
vi primes;

multiset < int > s;

int ip(int p){
    int x = lower_bound(all(primes), p) - primes.begin();
    return ++x;
}

int solve(){
    for(int i=2; i<(int)sieve.size(); i++){
        if(sieve[i] == 0){
            sieve[i] = i;
            primes.pb(i);
            for(ll j=(ll)i*i; j<(ll)sieve.size(); j+=i)
                if(sieve[j] == 0)
                    sieve[j] = i;
        }
    }

    int n;
    cin >> n;
    for(int i=0; i<2*n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    vi ans;

    while(!s.empty()){
        int x = *--s.end();
        if(sieve[x] == x){
            ans.pb(ip(x));
            s.erase(s.find(x));
            s.erase(s.find(ip(x)));
        }
        else{
            s.erase(s.find(x));
            ans.pb(x);
            x /= sieve[x];
            s.erase(s.find(x));
        }
    }

    for(int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}


signed main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.

