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


ll solve(vi &a){
   ll n;
   cin >> n;
   if(n <= 2){
      cout << 0 << endl;
      return 0;
   }
   cout << mod_prod(4, a[n]) << endl;
   return 0;
}


signed main(){
   fastio;

   vi z, o, c, a;
   z = o = c = a = vi(2e6 + 5);
   z[1] = 1, o[1] = 0;
   z[2] = 1, o[2] = 1;
   a[3] = 1;

   for(ll i=3; i<=2000000; i++){
      o[i] = z[i-1];
      z[i] = mod_sum(z[i-1], o[i-1], o[i-1]);
      c[i] = mod_sum(z[i-2], c[i-1]);
      if(i >= 4)
         a[i] = mod_sum(a[i-3], z[i-2]);
   }

   ll t = 1;
   cin >> t;
   while(t--)
      solve(a);

   return 0;
}

/*******************************************************************************/
// Remeber - In a custom comparator cmp(a, b) a==b must always return to false.
