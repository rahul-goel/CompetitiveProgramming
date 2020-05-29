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

int freq[200000];
vi vec;
map < int, int > cc;
int mcc = 0;
int cur_query_ans = 0;
const int block_size = 555;

struct foo{
    ll l, r, id, block_id;
};
vector < foo > queries;

bool cmp(foo &a, foo &b){
    if(a.block_id < b.block_id)
        return true;
    else if(a.block_id > b.block_id)
        return false;
    else
        return a.r < b.r;
}

void add(int idx){
    if(!freq[vec[idx]])
        cur_query_ans++;
    freq[vec[idx]]++;
}

void remove(int idx){
    freq[vec[idx]]--;
    if(!freq[vec[idx]])
        cur_query_ans--;
}

int get_ans(){
    return cur_query_ans;
}

int solve(){
    memset(freq, 0, sizeof(freq));
    int n, q;
    cin >> n >> q;
    vi answers(q);
    vec.resize(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
        if(present(cc, vec[i]))
            vec[i] = cc[vec[i]];
        else
            cc[vec[i]] = mcc, vec[i] = mcc++;

    }

    for(int i=0; i<q; i++){
        int x, y;
        cin >> x >> y;
        queries.pb({x-1, y-1, i, (x-1)/block_size});
    }

    sort(all(queries), cmp);

    int cur_l = 0, cur_r = -1;
    for(auto qu : queries){
        int ql = qu.l, qr = qu.r;
        while(cur_l > ql)
            cur_l--, add(cur_l);
        while(cur_r < qr)
            cur_r++, add(cur_r);
        while(cur_l < ql)
            remove(cur_l), cur_l++;
        while(cur_r > qr)
            remove(cur_r), cur_r--;
        answers[qu.id] = get_ans();
    }

    for(int i=0; i<q; i++)
        cout << answers[i] << '\n';

    return 0;
}


int main(){
    fastio;

    int t = 1;
    while(t--)
        solve();

    return 0;
}

