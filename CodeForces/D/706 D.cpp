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
#define pii             pair < int, int >
#define vi              vector < int >
#define vb              vector < bool >
#define vvi             vector < vector < int > >
#define vvb             vector < vector < bool > >
#define vpii            vector < pair < int, int > >
#define vvpii           vector < vector < pair < int, int > > >
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aint(c),x) != (c).end())
#define uniq(c)         (c).resize(distance((c).begin(), unique(aint(c))))
#define min_pq(t)       priority_queue < t, vector < t >, greater < t > >
#define max_pq(t)       priority_queue < t >
#define pb              push_back
#define ff              first
#define ss              second
/*******************************************************************************/
int mod_sum() { return 0; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

int mod_prod() { return 1; }
template<typename T, typename... Args>
T mod_prod(T a, Args... args) { return (a*mod_prod(args...))%mod; }
/*******************************************************************************/

/*
   Code begins after this.
   */

const int NIL = -1;
struct node{
   int count;
   int child[2];
   node(){
      count = 0;
      memset(child, NIL, sizeof(child));
   }
};

vector < node > data_mera;

vb bit_pattern(int num){
   vb ret;
   for(int i=0; i<30; i++)
      ret.pb(num&1), num>>=1;
   reverse(all(ret));
   return ret;
}

int bit_to_num(vb &bits){
   int ans = 0;
   reverse(all(bits));
   for(int i=0; i<(int)bits.size(); i++)
      ans += (1<<i)*bits[i];
   return ans;
}

void insert_word(int head, vb bits){
   int cur = head;
   for(int i=0; i<(int)bits.size(); i++){
      int child_index = bits[i];
      if(data_mera[cur].child[child_index] == NIL){
         data_mera[cur].child[child_index] = data_mera.size();
         data_mera.push_back(node());
      }
      cur = data_mera[cur].child[child_index];
      data_mera[cur].count++;
   }
}

int find_word(int head, vb bits){
   int cur = head;
   for(int i=0; i<(int)bits.size(); i++){
      int child_index = bits[i];
      if(data_mera[cur].child[child_index] == NIL)
         return 0;
      cur = data_mera[cur].child[child_index];
   }
   return data_mera[cur].count;
}

void del_word(int head, vb bits){
   int cur = head;
   stack < int > trace;
   for(int i=0; i<(int)bits.size(); i++){
      int child_index = bits[i];
      cur = data_mera[cur].child[child_index];
      trace.push(cur);
   }
   while(!trace.empty()){
      if(trace.top() == NIL)
         trace.pop();
      else
         data_mera[trace.top()].count--, trace.pop();
   }
}

int query(int head, vb bits){
   int cur = head;
   vb ans;
   for(int i=0; i<(int)bits.size(); i++){
      int child_index;
      int b0 = data_mera[cur].child[0], b1 = data_mera[cur].child[1];
      if(b0 != NIL && b1 != NIL && data_mera[b0].count > 0 && data_mera[b1].count > 0)
         child_index = !bits[i];
      else if(b0 != NIL && data_mera[b0].count > 0)
         child_index = 0;
      else if(b1 != NIL && data_mera[b1].count > 0)
         child_index = 1;
      ans.pb(child_index);
      cur = data_mera[cur].child[child_index];
   }
   return bit_to_num(ans);
}

int solve(){
   data_mera.push_back(node());
   int q, sz = 1;
   insert_word(0, bit_pattern(0));
   cin >> q;
   while(q--){
      char x;
      int num;
      cin >> x >> num;
      if(x == '+'){
         sz++;
         vb bits = bit_pattern(num);
         insert_word(0, bits);
      }
      else if(x == '-'){
         sz--;
         vb bits = bit_pattern(num);
         del_word(0, bits);
      }
      else{
         vb bits = bit_pattern(num);
         cout << (query(0, bits)^num) << endl;
      }
   }
   return 0;
}


int main(){
   fastio;

   int t = 1;
   while(t--)
      solve();

   return 0;
}

