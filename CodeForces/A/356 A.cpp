/*
   Created by Rahul Goel.
*/

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

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) (c).begin(), (c).end()
#define pii pair < ll, ll >
#define vi vector < ll >
#define vb vector < bool >
#define vvi vector < vector < ll > >
#define vvb vector < vector < bool > >
#define vpii vector < pair < ll, ll > >
#define vvpii vector < vector < pair < ll, ll > > >
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define min_pq(t) priority_queue < t, vector < t >, greater < t > >
#define max_pq(t) priority_queue < t >
#define pb push_back
#define ff first
#define ss second

ll mod_sum() { return 0ll; }
template<typename T, typename... Args>
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%mod + mod)%mod; }

ll mod_prod() { return 1ll; }
template<typename T, typename... Args>
T mod_product(T a, Args... args) { return (a*mod_product(args...))%mod; }

// --------------------------------------------------------------
int n, m;

vi t, ans;
vb marked;

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = tl;
        return;
    }
    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
}

void update(int v, int tl, int tr, int x, int l, int r){
    if(l > r)
        return;
    if(tl == l && tr == r){
        marked[v] = true;
        t[v] = x;
        return;
    }
    int tm = (tl+tr)/2;
    if(!marked[2*v])
        update(2*v, tl, tm, x, l, min(r, tm));
    if(!marked[2*v+1])
        update(2*v+1, tm+1, tr, x, max(l, tm+1), r);
}

void find_ans(int v, int tl, int tr){
    if(tl == tr){
        ans[tl] = t[v];
        return;
    }   
    if(!marked[2*v])
        t[2*v] = t[v];
    if(!marked[2*v + 1])
        t[2*v+1] = t[v];
    int tm = (tl+tr)/2;
    find_ans(2*v, tl, tm);
    find_ans(2*v+1, tm+1, tr);
}

ll solve(){
    cin >> n >> m;
    t.resize(4*n), marked.resize(4*n, false);
    ans.resize(n);
    build(1, 0, n-1);
    while(m--){
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        update(1, 0, n-1, x, l, x-1);
        update(1, 0, n-1, x, x+1, r);
    }
    t[1] = -1;
    find_ans(1, 0, n-1);
    for(int x : ans)
        cout << x + 1 << " ";
    cout << endl;
    return 0;
}

int main(){
    fastio;

    ll t = 1;
    while(t--)
        solve();

    return 0;
}

