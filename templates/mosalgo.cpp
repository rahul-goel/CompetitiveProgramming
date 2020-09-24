/*
    Created by Rahul Goel.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*******************************************************************************/
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*******************************************************************************/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template < typename T, typename... Args >
T mod_sum(T a, Args... args) { return ((a + MOD_sum(args...))%MOD + MOD)%MOD; }
/*******************************************************************************/
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a*MOD_prod(args...))%MOD; }
/*******************************************************************************/
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
using pii = pair < ll, ll >;
using vi = vector < ll >;
using vb = vector < bool >;
using vvi = vector < vector < ll > >;
using vvb = vector < vector < bool > >;
using vpii = vector < pii >;
using vvpii = vector < vector < pii > >;
/*******************************************************************************/
//.-.. . -. -.- .- .. ... .-.. --- ...- .
/*
    Code begins after this.
*/

struct foo {
    ll l, r, id, block_id;
};
vector < foo > queries;
bool cmp(foo &a, foo &b){
    if (a.block_id < b.block_id) {
        return true;
    } else if (a.block_id > b.block_id) {
        return false;
    } else if (a.block_id & 1) {
        return a.r > b.r;
    } else {
        return a.r < b.r;
    }
    // the last one (parity one) is an optimization to reduce
    // rutntime by half
}

vi vec; // the array on which queries are made
ll cur_query_ans = 0;

void add(ll idx) {
    // add to the data structure
    // take care of frequency and set the cur_query_ans accordingly.
}

void remove(ll idx) {
    // remove from the data structure
    // take care of frequency and set the cur_query_ans accordingly.
}

ll get_ans() {
    return cur_query_ans;
}

ll solve() {

    ll n, q;
    cin >> n >> q;


    ll block_size = sqrt(n); // for more optimization fix the block size as const int above;
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        queries.pb({l - 1, r - 1, i,(l - 1) / block_size});
    }
    sort(all(queries), cmp);

    vector < ll > answers(q);
    int cur_l = 0, cur_r = -1;
    for(auto qu : queries){
        int ql = qu.l, qr = qu.r;
        while (cur_l > ql) {
            cur_l--, add(cur_l);
        }
        while (cur_r < qr) {
            cur_r++, add(cur_r);
        }
        while (cur_l < ql) {
            remove(cur_l), cur_l++;
        }
        while (cur_r > qr) {
            remove(cur_r), cur_r--;
        }
        answers[qu.id] = get_ans();
    }

    return 0;
}

signed main() {
    fastio;

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
